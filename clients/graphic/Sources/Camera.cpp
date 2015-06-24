//
// Camera.cpp for Camera in /home/theven_l/Dropbox/zappy/Sources
// 
// Made by Leo Thevenet
// Login   <theven_l@epitech.net>
// 
// Started on  Mon Jun 22 16:21:13 2015 Leo Thevenet
// Last update Tue Jun 23 15:44:17 2015 Leo Thevenet
//

#include "Camera.hh"

Camera::Camera(float x, float y, float z) : _x(x), _y(y), _z(z)
{
  this->_keys[SDLK_LEFT] = &Camera::camLeft;
  this->_keys[SDLK_RIGHT] = &Camera::camRight;
  this->_keys[SDLK_DOWN] = &Camera::camDown;
  this->_keys[SDLK_UP] = &Camera::camUp;
  this->_keys[SDLK_KP_MINUS] = &Camera::camMinus;
  this->_keys[SDLK_KP_PLUS] = &Camera::camPlus;
}

Camera::~Camera()
{}

const glm::mat4 Camera::getCam()
{
  glm::mat4 transformation;

  transformation = glm::lookAt(glm::vec3(this->_x, this->_z, this->_y),
			       glm::vec3(this->_x, 0, this->_y + 0.0001),
			       glm::vec3(0, 1, 0));
  return transformation;
}

const glm::vec3 Camera::getPosHUD()
{
  return glm::vec3(this->_x, this->_z, this->_y);
}

void	Camera::getKey(gdl::Input &input)
{
  std::map<int, void(Camera::*)()>::const_iterator it;

  for (it = this->_keys.begin(); it != this->_keys.end(); ++it)
    if (input.getKey(it->first))
      (this->*(*it).second)();
}

void	Camera::camLeft()
{
  this->_x += 0.1;
}

void	Camera::camRight()
{
  this->_x -= 0.1;
}

void	Camera::camDown()
{
  this->_y -= 0.1;
}

void	Camera::camUp()
{
  this->_y += 0.1;
}

void	Camera::camMinus()
{
  this->_z += (this->_z <= 4) ? 0 : -0.1;
}

void	Camera::camPlus()
{
  this->_z += (this->_z > 25) ? 0 : 0.1;
}
