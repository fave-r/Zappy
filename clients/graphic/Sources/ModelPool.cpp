//
// ModelPool.cpp for ModelPool.cpp in /home/jean_c/Dropbox/zappy
//
// Made by jean_c
// Login   <jean_c@epitech.net>
//
// Started on  Sun Jun 21 02:22:39 2015 jean_c
// Last update Sun Jun 21 02:24:57 2015 jean_c
//

#include "ModelPool.hh"

ModelPool::ModelPool()
{
}

ModelPool::~ModelPool()
{
}

void		ModelPool::init()
{
  this->_ground.pushVertex(glm::vec3(0.5, 0.5, 0.5));
  this->_ground.pushVertex(glm::vec3(0.5, 0.5, -0.5));
  this->_ground.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
  this->_ground.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
  this->_ground.pushUv(glm::vec2(0.0f, 0.0f));
  this->_ground.pushUv(glm::vec2(1.0f, 0.0f));
  this->_ground.pushUv(glm::vec2(1.0f, 1.0f));
  this->_ground.pushUv(glm::vec2(0.0f, 1.0f));

  this->_ground.build();
}

const gdl::Geometry     &ModelPool::getGround() const
{
  return this->_ground;
}
