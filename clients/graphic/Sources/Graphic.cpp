//
// Graphic.cpp for Graphic.cpp in /home/jean_c/Dropbox/zappy
//
// Made by jean_c
// Login   <jean_c@epitech.net>
//
// Started on  Sat Jun 20 10:23:22 2015 jean_c
// Last update Wed Jun 24 18:12:05 2015 Leo Thevenet
//

#include "Graphic.hh"

Graphic::Graphic(size_t width, size_t height) : _width(width), _height(height)
{
  this->Initialize();
  this->_camType = 1;
  this->_actualCase = 0;
  std::cout << width << " " << height << std::endl;
}

Graphic::~Graphic()
{
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

  this->_shader.bind();
  this->_shader.setUniform("projection", projection);
  this->_shader.setUniform("view", this->_cam->getCam());
  this->initMap();
}

void		Graphic::changeSize(size_t width, size_t height, std::vector<std::vector <Content *> > map)
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
  AObject        *model;

  for (size_t i = 0; i < this->_height; ++i)
    for (size_t j = 0; j < this->_width; ++j)
      {
	model = new Ground(j, i);
	model->setModel(this->_modelPool->getGround());
	model->setTexture(this->_texturePool->getGround());
	model->translate(glm::vec3(j, 0, i));
	this->_objects.push_back(model);
      }
  setHUD();
}

void		Graphic::setHUD()
{
  AObject        *model;

  model = new Ground(0, 0);
  model->setModel(this->_modelPool->getGround());
  model->setTexture(this->_texturePool->getGround());
  this->_HUD.push_back(model);

  model = new Ground(0, 0);
  model->setModel(this->_modelPool->getGround());
  model->setTexture(this->_texturePool->getGround());
  this->_HUD.push_back(model);

  model = new Ground(0, 0);
  model->setModel(this->_modelPool->getGround());
  model->setTexture(this->_texturePool->getGround());
  this->_HUD.push_back(model);
}

void		Graphic::updateHUD()
{
  glm::vec3 pos = this->_cam->getPosHUD();

  pos.x -= 1;
  pos.y -= 2.5;
  pos.z += 1;
  this->_HUD[0]->setPos(pos);
  pos.x += 1;
  this->_HUD[1]->setPos(pos);
  pos.x += 1;
  this->_HUD[2]->setPos(pos);
}

#include <unistd.h>

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
}

bool		Graphic::update()
{
  this->_context.updateClock(this->_clock);
  this->_context.updateInputs(this->_input);
  if (this->_input.getKey(SDLK_ESCAPE) || this->_input.getInput(SDL_QUIT))
    return false;

  if (this->_input.getKey(SDLK_KP_1))
    this->_camType = 1;
  else if (this->_input.getKey(SDLK_KP_2))
    this->_camType = 2;
  else if (this->_input.getKey(SDLK_KP_3))
    this->_camType = 3;

  if (this->_camType == 1)
    {
      this->_cam->getKey(this->_input);
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
    } /* variable case actuelle
	 catch des touches haut, bas, droite, gauche
	 appel de getcam avec les pos x, y*/
  // else if (this->_camType == 3)
  // vue sur un perso, catch de droite gauche
  return true;
}

void		Graphic::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  for (size_t i = 0; i < this->_objects.size(); ++i)
    this->_objects[i]->draw(this->_shader);
  if (this->_camType == 2)
    for (size_t i = 0; i < this->_HUD.size(); ++i)
      this->_HUD[i]->draw(this->_shader);
  this->_context.flush();
}
