//
// Graphic.cpp for Graphic.cpp in /home/jean_c/Dropbox/zappy
//
// Made by jean_c
// Login   <jean_c@epitech.net>
//
// Started on  Sat Jun 20 10:23:22 2015 jean_c
// Last update Thu Jul  2 15:42:14 2015 Leo Thevenet
//

#include "Graphic.hh"

Graphic::Graphic(size_t width, size_t height) : _width(width), _height(height)
{
  this->_camType = 1;
  this->_actualCase = 0;
  this->_needUpdate = false;
  this->Initialize();
}

Graphic::~Graphic()
{
  /*for (std::vector<AObject *>::iterator it = this->_objects.begin(); it != this->_objects.end(); ++it)
    delete (*it);*/
  for (size_t i = 0; i < this->_HUD.size(); ++i)
    delete this->_HUD[i];
  delete this->_texturePool;
  delete this->_modelPool;
  delete this->_cam;
  this->_context.stop();
}

void		Graphic::setMap(std::vector<std::vector <Content *> > &map, std::list<std::pair<int, int> > &update, std::list<int> &play, User &user)
{
  this->_map = map;
  this->_update = update;
  this->_play = play;
  this->_user = user;
}

void		Graphic::Initialize()
{
  glm::mat4	projection;

  if (!this->_context.start(1920, 1080, "Zappy"))
    throw std::runtime_error("Cannot instanciate the window");
  if (!this->_shader.load("./Library/shaders/basic.fp", GL_FRAGMENT_SHADER)
      || !this->_shader.load("./Library/shaders/basic.vp", GL_VERTEX_SHADER)
      || !this->_shader.build())
    throw std::runtime_error("shader erreur");

  this->_cam = new Camera(this->_width / 2, this->_height / 2.2, 22);

  this->_modelPool = new ModelPool();
  this->_modelPool->init();
  this->_texturePool = new TexturePool();
  this->_texturePool->init();

  glEnable(GL_DEPTH_TEST);
  projection = glm::perspective(80.0f, 1920.0f / 1080.0f, 0.1f, 100.0f);

  this->initMap();
  this->_shader.bind();
  this->_shader.setUniform("projection", projection);
//  this->_shader.setUniform("view", this->_cam->getCam());
}

void		Graphic::changeSize(size_t width, size_t height, std::vector<std::vector <Content *> > &map)
{
  this->_map = map;
  this->_width = width;
  this->_height = height;
  this->_actualCase = 0;
  this->initMap();
  this->_cam->setCam(this->_width / 2, this->_height / 2.2, 22);
  this->_cam->setCam2(0, 0, 5);
  this->setHUD();
}

void		Graphic::initMap()
{
  Ground        *model;

  for (size_t i = 0; i < this->_height; ++i)
    for (size_t j = 0; j < this->_width; ++j)
      {
	model = new Ground(i, j);
	model->setModel(this->_modelPool->getGround());
	model->setTexture(this->_texturePool->getGround());
	model->translate(glm::vec3(j, 0, i));
	this->_objects.push_back(model);
      }
}

void		Graphic::addNumberHUD()
{
  AObject        *model;

  model = new Ground(0, 0);
  model->setModel(this->_modelPool->getGround());
  model->setTexture(this->_texturePool->getGround());
  model->scale(glm::vec3(0.2, 0, 0.2));
  model->rotate(glm::vec3(0, 1, 0), -90);
  this->_HUD.push_back(model);
}

void		Graphic::setHUD()
{
  AObject        *model;

  model = new Deraumere(0, 0);
  model->setModel(this->_modelPool->getCrystalD());
  this->_HUD.push_back(model);
  addNumberHUD();

  model = new Linemate(0, 0);
  model->setModel(this->_modelPool->getCrystalL());
  this->_HUD.push_back(model);
  addNumberHUD();

  model = new Sibur(0, 0);
  model->setModel(this->_modelPool->getCrystalS());
  this->_HUD.push_back(model);
  addNumberHUD();

  model = new Mendiane(0, 0);
  model->setModel(this->_modelPool->getCrystalM());
  this->_HUD.push_back(model);
  addNumberHUD();

  model = new Phiras(0, 0);
  model->setModel(this->_modelPool->getCrystalP());
  this->_HUD.push_back(model);
  addNumberHUD();

  model = new Thystame(0, 0);
  model->setModel(this->_modelPool->getCrystalT());
  this->_HUD.push_back(model);
  addNumberHUD();
}

void		Graphic::updateHUD()
{
  int		y = this->_actualCase % this->_width;
  int		x = this->_actualCase / this->_width;

  glm::vec3 pos = this->_cam->getPosHUD();

  pos.x -= 2.4;
  pos.y -= 2;
  pos.z += 1.2;
  for (int i = 0; i < 12; i++)
    {
      this->_HUD[i]->setPos(pos);
      pos.x += 0.3;
      pos.x += (i % 2 == 1) ? 0.3 : 0;
    }
  this->_HUD[1]->setTexture(this->_texturePool->getNumber(this->_map[x][y]->getDeraumere()));
  this->_HUD[3]->setTexture(this->_texturePool->getNumber(this->_map[x][y]->getLinemate()));
  this->_HUD[5]->setTexture(this->_texturePool->getNumber(this->_map[x][y]->getSibur()));
  this->_HUD[7]->setTexture(this->_texturePool->getNumber(this->_map[x][y]->getMendiane()));
  this->_HUD[9]->setTexture(this->_texturePool->getNumber(this->_map[x][y]->getPhiras()));
  this->_HUD[11]->setTexture(this->_texturePool->getNumber(this->_map[x][y]->getThystame()));
}

void		Graphic::MoveCase(int nb)
{
  int		x = this->_actualCase % this->_width;
  int		y = this->_actualCase / this->_width;

  if (nb == -1 || nb == 1)
    {
      x += nb;
      x += (x < 0) ? this->_width : 0;
      x -= (x >= static_cast<int>(this->_width)) ? this->_width : 0;
    }
  else
    {
      y += (nb < 0) ? -1 : 1;
      y += (y < 0) ? this->_height : 0;
      y -= (y >= static_cast<int>(this->_height)) ? this->_height : 0;
    }
  this->_actualCase = x + y * this->_width;
  this->_needUpdate = true;
}

template <typename T>void	Graphic::erase(std::list<std::pair<int, int> >::const_iterator it2)
{
  for(std::vector<AObject *>::iterator it = this->_objects.begin(); it != this->_objects.end();)
    if (dynamic_cast<T>((*it)) != NULL && (*it)->getX() == (*it2).second && (*it)->getY() == (*it2).first)
      it = this->_objects.erase(it);
    else
      it++;
}

bool		Graphic::update()
{
  this->_context.updateClock(this->_clock);
  this->_context.updateInputs(this->_input);
  if (this->_input.getKey(SDLK_ESCAPE) || this->_input.getInput(SDL_QUIT))
    return false;

  if (this->_input.getKey(SDLK_KP_1) && (this->_needUpdate = true))
    this->_camType = 1;
  else if (this->_input.getKey(SDLK_KP_2) && (this->_needUpdate = true))
    this->_camType = 2;
  else if (this->_input.getKey(SDLK_KP_3) && (this->_needUpdate = true))
    this->_camType = 3;

  if (this->_camType == 1)
    {
      this->_needUpdate = this->_cam->getKey(this->_input) ? true : this->_needUpdate;
      this->_shader.setUniform("view", this->_cam->getCam());
    }
  else if (this->_camType == 2)
    {
      this->_objects[this->_actualCase]->setTexture(this->_texturePool->getGround());
      if (this->_input.getKey(SDLK_UP))
	MoveCase(-this->_width);
      else if (this->_input.getKey(SDLK_DOWN))
	MoveCase(this->_width);
      else if (this->_input.getKey(SDLK_LEFT))
	MoveCase(-1);
      else if (this->_input.getKey(SDLK_RIGHT))
	MoveCase(1);
      this->_objects[this->_actualCase]->setTexture(this->_texturePool->getSelectedGround());
      this->_cam->setCam2(this->_actualCase % this->_width, this->_actualCase / this->_width, 5);
      this->_shader.setUniform("view", this->_cam->getCam2());
      updateHUD();
    }
  // else if (this->_camType == 3)
  // vue sur un perso, catch de droite gauche

  if (this->_update.size() > 0)
    {
      std::list<std::pair<int, int> >::const_iterator it2;
      for (it2 = this->_update.begin(); it2 != this->_update.end(); ++it2)
	       {
	  if (this->_map[(*it2).second][(*it2).first]->getDeraumere() > 0 && this->_map[(*it2).second][(*it2).first]->getBoolD() == false)
	    {
	      Deraumere *de = new Deraumere((*it2).first, (*it2).second);
	      de->setModel(this->_modelPool->getCrystalD());
	      // de->setTexture(this->_texturePool->getWaterMelon());
	      this->_objects.push_back(de);
	      this->_map[(*it2).second][(*it2).first]->setBoolD(true);
	    }
	  else if (this->_map[(*it2).second][(*it2).first]->getDeraumere() == 0 && this->_map[(*it2).second][(*it2).first]->getBoolD() == true)
	     erase<Deraumere *>(it2);

	  if (this->_map[(*it2).second][(*it2).first]->getLinemate() > 0 && this->_map[(*it2).second][(*it2).first]->getBoolL() == false)
	    {
	      Linemate *li = new Linemate((*it2).first, (*it2).second);
	      li->setModel(this->_modelPool->getCrystalL());
	      this->_objects.push_back(li);
	      this->_map[(*it2).second][(*it2).first]->setBoolL(true);
	    }
	  else if (this->_map[(*it2).second][(*it2).first]->getLinemate() == 0 && this->_map[(*it2).second][(*it2).first]->getBoolL() == true)
	    erase<Linemate *>(it2);

	  if (this->_map[(*it2).second][(*it2).first]->getMendiane() > 0 && this->_map[(*it2).second][(*it2).first]->getBoolM() == false)
	    {
	      Mendiane *me = new Mendiane((*it2).first, (*it2).second);
	      me->setModel(this->_modelPool->getCrystalM());
	      this->_objects.push_back(me);
	      this->_map[(*it2).second][(*it2).first]->setBoolM(true);
	    }
	  else if (this->_map[(*it2).second][(*it2).first]->getMendiane() == 0 && this->_map[(*it2).second][(*it2).first]->getBoolM() == true)
	    erase<Mendiane *>(it2);

	  if (this->_map[(*it2).second][(*it2).first]->getPhiras() > 0 && this->_map[(*it2).second][(*it2).first]->getBoolP() == false)
	    {
	      Phiras *ph = new Phiras((*it2).first, (*it2).second);
	      ph->setModel(this->_modelPool->getCrystalP());
	      this->_objects.push_back(ph);
	      this->_map[(*it2).second][(*it2).first]->setBoolP(true);
	    }
	  else if (this->_map[(*it2).second][(*it2).first]->getPhiras() == 0 && this->_map[(*it2).second][(*it2).first]->getBoolP() == true)
	    erase<Phiras *>(it2);

	  if (this->_map[(*it2).second][(*it2).first]->getSibur() > 0 && this->_map[(*it2).second][(*it2).first]->getBoolS() == false)
	    {
	      Sibur *si = new Sibur((*it2).first, (*it2).second);
	      si->setModel(this->_modelPool->getCrystalS());
	      this->_objects.push_back(si);
	      this->_map[(*it2).second][(*it2).first]->setBoolS(true);
	    }
	  else if (this->_map[(*it2).second][(*it2).first]->getSibur() == 0 && this->_map[(*it2).second][(*it2).first]->getBoolS() == true)
	    erase<Sibur *>(it2);

	  if (this->_map[(*it2).second][(*it2).first]->getThystame() > 0 && this->_map[(*it2).second][(*it2).first]->getBoolT() == false)
	    {
	      Thystame *th = new Thystame((*it2).first, (*it2).second);
	      th->setModel(this->_modelPool->getCrystalT());
	      this->_objects.push_back(th);
	      this->_map[(*it2).second][(*it2).first]->setBoolT(true);
	    }
	  else if (this->_map[(*it2).second][(*it2).first]->getThystame() == 0 && this->_map[(*it2).second][(*it2).first]->getBoolT() == true)
	    erase<Thystame *>(it2);

	  if (this->_map[(*it2).second][(*it2).first]->getFood() > 0 && this->_map[(*it2).second][(*it2).first]->getBoolF() == false)
	    {
	      Food *fd = new Food((*it2).first, (*it2).second);
	      fd->setModel(this->_modelPool->getFood());
	      fd->setTexture(this->_texturePool->getWaterMelon());
	      this->_objects.push_back(fd);
	      this->_map[(*it2).second][(*it2).first]->setBoolF(true);
	    }
	  else if (this->_map[(*it2).second][(*it2).first]->getFood() == 0 && this->_map[(*it2).second][(*it2).first]->getBoolF() == true)
	     erase<Food *>(it2);
	}
      this->_update.clear();
      this->_needUpdate = true;

    }
  return true;
}

void		Graphic::draw()
{
  //  this->_needUpdate = true;
  if (this->_update.size() > 0 || this->_needUpdate == true)
    {
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      for (std::vector<AObject *>::iterator it = this->_objects.begin(); it != this->_objects.end(); ++it)
	       (*it)->draw(this->_shader);
     std::list<int>::const_iterator it3;
	   for (it3 = this->_play.begin(); it3 != this->_play.end(); ++it3) {
        this->_user.getUser()[(*it3)]->update();
	      this->_user.getUser()[(*it3)]->draw(this->_shader);
      }
      if (this->_camType == 2)
	for (size_t i = 0; i < this->_HUD.size(); ++i)
	  if (i % 2 == 0)
	    this->_HUD[i]->draw(this->_shader);
      if (this->_camType == 2)
	for (size_t i = 0; i < this->_HUD.size(); ++i)
	  if (i % 2 == 1)
	    this->_HUD[i]->draw(this->_shader);
      this->_needUpdate = false;
      this->_context.flush();
    }
}
