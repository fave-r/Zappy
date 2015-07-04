//
// AObject.cpp for AObject.cpp in /home/jean_c/Dropbox/zappy
//
// Made by jean_c
// Login   <jean_c@epitech.net>
//
// Started on  Sun Jun 21 02:02:59 2015 jean_c
// Last update Mon Jun 29 10:23:18 2015 jean_c
//

#include "AObject.hh"

AObject::AObject(float x, float y)
  : _x(x), _y(y), _position(0, 0, 0), _rotation(0, 0, 0), _scale(1, 1, 1)
{
}

AObject::~AObject()
{
}

void                    AObject::scale(const glm::vec3 &scale)
{
  this->_scale *= scale;
}

void                    AObject::translate(const glm::vec3 &v)
{
  //this->_position += v;
  this->_position = v;
}

void                    AObject::setPos(const glm::vec3 &v)
{
  this->_position = v;
}

void                    AObject::rotate(const glm::vec3 &axis, const float &angle)
{
  this->_rotation += axis * angle;
}

const glm::mat4         AObject::getTransformation()
{
  glm::mat4             transform(1);

  transform = glm::translate(transform, this->_position);
  transform = glm::rotate(transform, this->_rotation.x, glm::vec3(1, 0, 0));
  transform = glm::rotate(transform, this->_rotation.y, glm::vec3(0, 1, 0));
  transform = glm::rotate(transform, this->_rotation.z, glm::vec3(0, 0, 1));
  transform = glm::scale(transform, this->_scale);
  return (transform);
}

void                    AObject::setTexture(const gdl::Texture &old)
{
  this->_texture = old;
}

float			AObject::getX()
{
  return this->_x;
}

float			AObject::getY()
{
  return this->_y;
}
