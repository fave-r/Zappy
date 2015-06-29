//
// Camera.cpp for Camera in /home/theven_l/Dropbox/zappy/Sources
//
// Made by Leo Thevenet
// Login   <theven_l@epitech.net>
//
// Started on  Mon Jun 22 16:21:13 2015 Leo Thevenet
// Last update Fri Jun 26 16:30:45 2015 Leo Thevenet
//

#include "Camera.hh"

Camera::Camera(float x, float y, float z) : _x(x), _y(y), _z(z), _x2(0), _y2(0), _z2(0)
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
			       glm::vec3(this->_x, 0, this->_y - 0.0001),
			       glm::vec3(0, 1, 0));
  return transformation;
}

const glm::mat4 Camera::getCam2()
{
  glm::mat4 transformation;

  transformation = glm::lookAt(glm::vec3(this->_x2, this->_z2, this->_y2 + 4),
			       glm::vec3(this->_x2, 0, this->_y2 + 2),
			       glm::vec3(0, 1, 0));
  return transformation;
}

const glm::vec3 Camera::getPosCam()
{
  return glm::vec3(this->_x, this->_z, this->_y);
}

void	Camera::setCam(float x, float y, float z)
{
  this->_x = x;
  this->_y = y;
  this->_z = z;
}

void	Camera::setCam2(float x, float y, float z)
{
  this->_x2 = x;
  this->_y2 = y;
  this->_z2 = z;
}

const glm::vec3 Camera::getPosHUD()
{
  return glm::vec3(this->_x2, this->_z2, this->_y2 + 3);
}

bool	Camera::getKey(gdl::Input &input)
{
  std::map<int, void(Camera::*)()>::const_iterator it;

  for (it = this->_keys.begin(); it != this->_keys.end(); ++it)
    if (input.getKey(it->first))
    {
      (this->*(*it).second)();
      return true;
  } 
  return false;
}

void	Camera::camLeft()
{
  this->_x -= 0.1;
}

void	Camera::camRight()
{
  this->_x += 0.1;
}

void	Camera::camDown()
{
  this->_y += 0.1;
}

void	Camera::camUp()
{
  this->_y -= 0.1;
}

void	Camera::camMinus()
{
  this->_z += (this->_z <= 4) ? 0 : -0.1;
}

void	Camera::camPlus()
{
  this->_z += (this->_z > 25) ? 0 : 0.1;
}
