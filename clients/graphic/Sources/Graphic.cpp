//
// Graphic.cpp for Graphic.cpp in /home/jean_c/Dropbox/zappy
//
// Made by jean_c
// Login   <jean_c@epitech.net>
//
// Started on  Sat Jun 20 10:23:22 2015 jean_c
// Last update Tue Jun 30 13:02:01 2015 Leo Thevenet
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
}

void		Graphic::setMap(std::vector<std::vector <Content *> > &map, std::list<std::pair<int, int> > &update)
{
  this->_map = map;
  this->_update = update;
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
  this->_shader.setUniform("view", this->_cam->getCam());
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
  setHUD();
}

void		Graphic::affHudData()
{
  int		y = this->_actualCase % this->_width;
  int		x = this->_actualCase / this->_width;

  std::cout << "x : " << y << " y : " << x << std::endl;
  std::cout << "Food : " << this->_map[x][y]->getFood();
  std::cout << " Limenate : " << this->_map[x][y]->getLinemate();
  std::cout << " Deraumere : " << this->_map[x][y]->getDeraumere();
  std::cout << " Sibur : " << this->_map[x][y]->getSibur();
  std::cout << " Mendiane : " << this->_map[x][y]->getMendiane();
  std::cout << " Phiras : " << this->_map[x][y]->getPhiras();
  std::cout << " Thystame : " << this->_map[x][y]->getThystame() << std::endl;
}

void		Graphic::setHUD()
{
  AObject        *model;

  model = new Deraumere(0, 0);
  model->setModel(this->_modelPool->getCrystalD());
  this->_HUD.push_back(model);

  // model = new Food(0, 0);
  // model->setModel(this->_modelPool->getCrystalF());
  // this->_HUD.push_back(model);

  model = new Linemate(0, 0);
  model->setModel(this->_modelPool->getCrystalL());
  this->_HUD.push_back(model);

  model = new Sibur(0, 0);
  model->setModel(this->_modelPool->getCrystalS());
  this->_HUD.push_back(model);

  model = new Mendiane(0, 0);
  model->setModel(this->_modelPool->getCrystalM());
  this->_HUD.push_back(model);

  model = new Phiras(0, 0);
  model->setModel(this->_modelPool->getCrystalP());
  this->_HUD.push_back(model);

  model = new Thystame(0, 0);
  model->setModel(this->_modelPool->getCrystalT());
  this->_HUD.push_back(model);
}

void		Graphic::updateHUD()
{
  glm::vec3 pos = this->_cam->getPosHUD();

  pos.x -= 2.5;
  pos.y -= 2;
  pos.z += 1;
  for (int i = 0; i < 6; i++)
    {
      this->_HUD[i]->setPos(pos);
      pos.x += 1;
    }
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

bool		Graphic::update()
{
  this->_context.updateClock(this->_clock);
  this->_context.updateInputs(this->_input);
  if (this->_input.getKey(SDLK_ESCAPE) || this->_input.getInput(SDL_QUIT))
    return false;

  if (this->_input.getKey(SDLK_KP_1))
    {
      this->_needUpdate = true;
      this->_camType = 1;
    }
  else if (this->_input.getKey(SDLK_KP_2))
    {
      this->_camType = 2;
      this->_needUpdate = true;
    }
  else if (this->_input.getKey(SDLK_KP_3))
    this->_camType = 3;

  //  if (this->_update.size() == 0)
  //draw();

  if (this->_camType == 1)
    {
      this->_needUpdate = this->_cam->getKey(this->_input);
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
      std::cout << "XXXX : " << this->_objects[this->_actualCase]->getX() << " YYYY " << this->_objects[this->_actualCase]->getY() << std::endl;
      this->_cam->setCam2(this->_actualCase % this->_width, this->_actualCase / this->_width, 5);
      std::cout << this->_actualCase << std::endl;
      this->_shader.setUniform("view", this->_cam->getCam2());
      affHudData();
      updateHUD();
    }
  // else if (this->_camType == 3)
  // vue sur un perso, catch de droite gauche

  if (this->_update.size() > 0)
    {
      std::list<std::pair<int, int> >::const_iterator it2;
      for (it2 = this->_update.begin(); it2 != this->_update.end(); ++it2) {

	if (this->_map[(*it2).second][(*it2).first]->getDeraumere() > 0 && this->_map[(*it2).second][(*it2).first]->getBoolD() == false)
	  {
	    Deraumere *de = new Deraumere((*it2).first, (*it2).second);
	    de->setModel(this->_modelPool->getCrystalD());
	    this->_objects.push_back(de);
	    this->_map[(*it2).second][(*it2).first]->setBoolD(true);
	  }
	else if (this->_map[(*it2).second][(*it2).first]->getDeraumere() == 0 && this->_map[(*it2).second][(*it2).first]->getBoolD() == true)
	  {
	    for(std::vector<AObject *>::iterator it = this->_objects.begin(); it != this->_objects.end(); ++it) {
	      if ((*it)->getX() == (*it2).second && (*it)->getY() == (*it2).first && dynamic_cast<Deraumere *>((*it)) != NULL)
		this->_objects.erase(it);
	    }
	  }

	if (this->_map[(*it2).second][(*it2).first]->getLinemate() > 0 && this->_map[(*it2).second][(*it2).first]->getBoolL() == false)
	  {
	    Linemate *li = new Linemate((*it2).first, (*it2).second);
	    li->setModel(this->_modelPool->getCrystalL());
	    this->_objects.push_back(li);
	    this->_map[(*it2).second][(*it2).first]->setBoolL(true);
	  }
	else if (this->_map[(*it2).second][(*it2).first]->getLinemate() == 0 && this->_map[(*it2).second][(*it2).first]->getBoolL() == true)
	  {
	    for(std::vector<AObject *>::iterator it = this->_objects.begin(); it != this->_objects.end(); ++it) {
	      if ((*it)->getX() == (*it2).second && (*it)->getY() == (*it2).first && dynamic_cast<Linemate *>((*it)) != NULL)
		this->_objects.erase(it);
	    }
	  }

	if (this->_map[(*it2).second][(*it2).first]->getMendiane() > 0 && this->_map[(*it2).second][(*it2).first]->getBoolM() == false)
	  {
	    Mendiane *me = new Mendiane((*it2).first, (*it2).second);
	    me->setModel(this->_modelPool->getCrystalM());
	    this->_objects.push_back(me);
	    this->_map[(*it2).second][(*it2).first]->setBoolM(true);
	  }
	else if (this->_map[(*it2).second][(*it2).first]->getMendiane() == 0 && this->_map[(*it2).second][(*it2).first]->getBoolM() == true)
	  {
	    for(std::vector<AObject *>::iterator it = this->_objects.begin(); it != this->_objects.end(); ++it) {
	      if ((*it)->getX() == (*it2).second && (*it)->getY() == (*it2).first && dynamic_cast<Mendiane *>((*it)) != NULL)
		this->_objects.erase(it);
	    }
	  }

	if (this->_map[(*it2).second][(*it2).first]->getPhiras() > 0 && this->_map[(*it2).second][(*it2).first]->getBoolP() == false)
	  {
	    Phiras *ph = new Phiras((*it2).first, (*it2).second);
	    ph->setModel(this->_modelPool->getCrystalP());
	    this->_objects.push_back(ph);
	    this->_map[(*it2).second][(*it2).first]->setBoolP(true);
	  }
	else if (this->_map[(*it2).second][(*it2).first]->getPhiras() == 0 && this->_map[(*it2).second][(*it2).first]->getBoolP() == true)
	  {
	    for(std::vector<AObject *>::iterator it = this->_objects.begin(); it != this->_objects.end(); ++it) {
	      if ((*it)->getX() == (*it2).second && (*it)->getY() == (*it2).first && dynamic_cast<Phiras *>((*it)) != NULL)
		this->_objects.erase(it);
	    }
	  }

	if (this->_map[(*it2).second][(*it2).first]->getSibur() > 0 && this->_map[(*it2).second][(*it2).first]->getBoolS() == false)
	  {
	    Sibur *si = new Sibur((*it2).first, (*it2).second);
	    si->setModel(this->_modelPool->getCrystalS());
	    this->_objects.push_back(si);
	    this->_map[(*it2).second][(*it2).first]->setBoolS(true);
	  }
	else if (this->_map[(*it2).second][(*it2).first]->getSibur() == 0 && this->_map[(*it2).second][(*it2).first]->getBoolS() == true)
	  {
	    for(std::vector<AObject *>::iterator it = this->_objects.begin(); it != this->_objects.end(); ++it) {
	      if ((*it)->getX() == (*it2).second && (*it)->getY() == (*it2).first && dynamic_cast<Sibur *>((*it)) != NULL)
		this->_objects.erase(it);
	    }
	  }

	if (this->_map[(*it2).second][(*it2).first]->getThystame() > 0 && this->_map[(*it2).second][(*it2).first]->getBoolT() == false)
	  {
	    Thystame *th = new Thystame((*it2).first, (*it2).second);
	    th->setModel(this->_modelPool->getCrystalT());
      this->_objects.push_back(th);
	    this->_map[(*it2).second][(*it2).first]->setBoolT(true);
	  }
	else if (this->_map[(*it2).second][(*it2).first]->getThystame() == 0 && this->_map[(*it2).second][(*it2).first]->getBoolT() == true)
	  {
	    for(std::vector<AObject *>::iterator it = this->_objects.begin(); it != this->_objects.end(); ++it) {
	      if ((*it)->getX() == (*it2).second && (*it)->getY() == (*it2).first && dynamic_cast<Thystame *>((*it)) != NULL)
		this->_objects.erase(it);
	    }
	  }

  /*if (this->_map[(*it2).second][(*it2).first]->getFood() > 0 && this->_map[(*it2).second][(*it2).first]->getBoolF() == false)
      {
         Food *fd = new Food((*it2).first, (*it2).second);
         fd->setModel(this->_modelPool->getFood());
         fd->setTexture(this->_texturePool->getWaterMelon());
         this->_objects.push_back(fd);
         this->_map[(*it2).second][(*it2).first]->setBoolF(true);
      }
    else if (this->_map[(*it2).second][(*it2).first]->getFood() == 0 && this->_map[(*it2).second][(*it2).first]->getBoolF() == true)
     {
        for(std::vector<AObject *>::iterator it = this->_objects.begin(); it != this->_objects.end(); ++it) {
           if ((*it)->getX() == (*it2).second && (*it)->getY() == (*it2).first && dynamic_cast<Food *>((*it)) != NULL)
            this->_objects.erase(it);
           }
      }*/
    }
      this->_update.clear();
    }
       // glm::vec4 final = inv * point;
  //     // std::cout << mouse.x << " " << mouse.y << std::endl;

  //     glm::vec3 final1 = glm::unProject(glm::vec3((float)mouse.x, (float)mouse.y, 0.0), view, projection, glm::vec4(0, 0, 1920, 1080));
  //     glm::vec3 final2 = glm::unProject(glm::vec3((float)mouse.x, (float)mouse.y, 1.0), view, projection, glm::vec4(0, 0, 1920, 1080));


  //     glm::vec3 ray = glm::normalize(final2 - final1);

  //     std::cout << ray.x << " " << ray.y << " " << ray.z << std::endl;
  //     glm::vec3 pos = this->_cam->getPosCam();
  //     glm::vec3 n = glm::vec3(0, 1, 0);

  //     float t = (-glm::dot(pos, n)) / glm::dot(ray, n);

  //     std::cout << t << std::endl;
  //     glm::vec3 p = pos + ray * t;
  //     std::cout << " x : " << p.x << " y : " << p.y << " z : " << p.z << std::endl;

  // glm::vec3 vDirToSphere = glm::vec3(0, 0, 0) - final1;
  // glm::vec3 vLineDir = glm::normalize(final1 - final2);
  // // float fLineLength = glm::distance(final1, final2);
  // float t = glm::dot(vDirToSphere, vLineDir);

  // glm::vec3 final;

  // if (t <= 0.0f)
  //	vClosestPoint = vA;
  // else if (t >= fLineLength)
  //	vClosestPoint = vB;
  // else
  // final = final1 + vLineDir * t;



  //std::cout << "t : " << t // << " f " << fLineLength
  // std::cout << " " << final.x << "  " << final.y << "  " << final.z << std::endl;

  // double a = 1;
  // double b = 1;
  // double c = 0;
  // double d = 0;
  // glm::vec3 pos = this->_cam->getPosCam();
  // //final = final - pos;

  // double k = -(a * pos.x + b * pos.y + c * pos.z + d) / (a * final.x + b * final.y + c * final.z);


  // // double Vx = mouse.x - 1920 / 2;
  // // double Vy = mouse.y - 1080 / 2;
  // // double Vz = 1920 / 2 / tan(40);
  // double Px = k * final.x + pos.x;
  // double Py = k * final.y + pos.y;
  // double Pz = k * final.z + pos.z;
  // std::cout << "k : " << k << " x : " << Px << " y : " << Py << " z : " << Pz << std::endl;
  // std::cout << mouse.x << std::endl;
  //}
  return true;
}
// #include <ctime>
// #include <cstdio>

void		Graphic::draw()
{
  this->_needUpdate = true;
  if (this->_update.size() > 0 || this->_needUpdate == true)
  {
    //std::clock_t start;
    //double duration;

    //start = std::clock();

      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
  //  std::cout << "clear update : " << duration << std::endl;

    //start = std::clock();

      for (std::vector<AObject *>::iterator it = this->_objects.begin(); it != this->_objects.end(); ++it) {
	       (*it)->draw(this->_shader);
	      }

      //duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    //  std::cout << "All draw update : " << duration << std::endl;

    //  start = std::clock();

      if (this->_camType == 2)
	for (size_t i = 0; i < this->_HUD.size(); ++i)
	  this->_HUD[i]->draw(this->_shader);
	this->_needUpdate = false;
	this->_context.flush();
    }
  //duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
  //std::cout << "flush update : " << duration << std::endl;
}
