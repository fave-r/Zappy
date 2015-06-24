//
// Graphic.cpp for Graphic.cpp in /home/jean_c/Dropbox/zappy
//
// Made by jean_c
// Login   <jean_c@epitech.net>
//
// Started on  Sat Jun 20 10:23:22 2015 jean_c
// Last update Wed Jun 24 09:25:02 2015 jean_c
//

#include "Graphic.hh"

Graphic::Graphic(size_t width, size_t height) : _width(width), _height(height)
{
  this->_cam = new Camera(width / 2, height / 2, 22);
  this->Initialize();
  this->_isHUD = false;
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
  pos.z -= 1;
  this->_HUD[0]->setPos(pos);
  pos.x += 1;
  this->_HUD[1]->setPos(pos);
  pos.x += 1;
  this->_HUD[2]->setPos(pos);
}

bool		Graphic::update()
{
  this->_context.updateClock(this->_clock);
  this->_context.updateInputs(this->_input);
  if (this->_input.getKey(SDLK_ESCAPE) || this->_input.getInput(SDL_QUIT))
    return false;
  if (this->_input.getKey(SDLK_SPACE))
    this->_isHUD = !this->_isHUD;
  this->_cam->getKey(this->_input);
  glm::ivec2 caca = this->_input.getMousePosition();
  std::cout << caca.x << "  " << caca.y << std::endl;

  this->_shader.setUniform("view", this->_cam->getCam());
  updateHUD();
  return true;
}

void		Graphic::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  for (size_t i = 0; i < this->_objects.size(); ++i)
    this->_objects[i]->draw(this->_shader);
  if (this->_isHUD == true)
    for (size_t i = 0; i < this->_HUD.size(); ++i)
      this->_HUD[i]->draw(this->_shader);
  this->_context.flush();
}
