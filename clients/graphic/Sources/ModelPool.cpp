//
// ModelPool.cpp for ModelPool.cpp in /home/jean_c/Dropbox/zappy
//
// Made by jean_c
// Login   <jean_c@epitech.net>
//
// Started on  Sun Jun 21 02:22:39 2015 jean_c
// Last update Tue Jun 30 11:19:00 2015 Leo Thevenet
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

  this->_crystalD.setColor(glm::vec4(1, 0, 0, 1));
  this->_crystalD.pushVertex(glm::vec3(0.0f, 1.0f, 0.0f));
  this->_crystalD.pushVertex(glm::vec3(-1.0f, -1.0f, 1.0f));
  this->_crystalD.pushVertex(glm::vec3(1.0f, -1.0f, 1.0f));
  this->_crystalD.pushUv(glm::vec2(0.0f, 0.0f));
  this->_crystalD.pushUv(glm::vec2(1.0f, 0.0f));
  this->_crystalD.pushUv(glm::vec2(1.0f, 1.0f));
  this->_crystalD.pushUv(glm::vec2(0.0f, 1.0f));

  this->_crystalD.setColor(glm::vec4(1, 0, 0, 1));
  this->_crystalD.pushVertex(glm::vec3(0.0f, 1.0f, 0.0f));
  this->_crystalD.pushVertex(glm::vec3(1.0f, -1.0f, 1.0f));
  this->_crystalD.pushVertex(glm::vec3(1.0f, -1.0f, -1.0f));
  this->_crystalD.pushUv(glm::vec2(0.0f, 0.0f));
  this->_crystalD.pushUv(glm::vec2(1.0f, 0.0f));
  this->_crystalD.pushUv(glm::vec2(1.0f, 1.0f));
  this->_crystalD.pushUv(glm::vec2(0.0f, 1.0f));

  this->_crystalD.setColor(glm::vec4(1, 0, 0, 1));
  this->_crystalD.pushVertex(glm::vec3(0.0f, 1.0f, 0.0f));
  this->_crystalD.pushVertex(glm::vec3(1.0f, -1.0f, -1.0f));
  this->_crystalD.pushVertex(glm::vec3(-1.0f, -1.0f, -1.0f));
  this->_crystalD.pushUv(glm::vec2(0.0f, 0.0f));
  this->_crystalD.pushUv(glm::vec2(1.0f, 0.0f));
  this->_crystalD.pushUv(glm::vec2(1.0f, 1.0f));
  this->_crystalD.pushUv(glm::vec2(0.0f, 1.0f));

  this->_crystalD.setColor(glm::vec4(1, 0, 0, 1));
  this->_crystalD.pushVertex(glm::vec3(0.0f, 1.0f, 0.0f));
  this->_crystalD.pushVertex(glm::vec3(-1.0f,-1.0f,-1.0f));
  this->_crystalD.pushVertex(glm::vec3(-1.0f,-1.0f, 1.0f));
  this->_crystalD.pushUv(glm::vec2(0.0f, 0.0f));
  this->_crystalD.pushUv(glm::vec2(1.0f, 0.0f));
  this->_crystalD.pushUv(glm::vec2(1.0f, 1.0f));
  this->_crystalD.pushUv(glm::vec2(0.0f, 1.0f));

  this->_crystalD.build();

  this->_crystalL.setColor(glm::vec4(0, 1, 0, 1));
  this->_crystalL.pushVertex(glm::vec3(0.0f, 1.0f, 0.0f));
  this->_crystalL.pushVertex(glm::vec3(-1.0f, -1.0f, 1.0f));
  this->_crystalL.pushVertex(glm::vec3(1.0f, -1.0f, 1.0f));
  this->_crystalL.pushUv(glm::vec2(0.0f, 0.0f));
  this->_crystalL.pushUv(glm::vec2(1.0f, 0.0f));
  this->_crystalL.pushUv(glm::vec2(1.0f, 1.0f));
  this->_crystalL.pushUv(glm::vec2(0.0f, 1.0f));

  this->_crystalL.setColor(glm::vec4(0, 1, 0, 1));
  this->_crystalL.pushVertex(glm::vec3(0.0f, 1.0f, 0.0f));
  this->_crystalL.pushVertex(glm::vec3(1.0f, -1.0f, 1.0f));
  this->_crystalL.pushVertex(glm::vec3(1.0f, -1.0f, -1.0f));
  this->_crystalL.pushUv(glm::vec2(0.0f, 0.0f));
  this->_crystalL.pushUv(glm::vec2(1.0f, 0.0f));
  this->_crystalL.pushUv(glm::vec2(1.0f, 1.0f));
  this->_crystalL.pushUv(glm::vec2(0.0f, 1.0f));

  this->_crystalL.setColor(glm::vec4(0, 1, 0, 1));
  this->_crystalL.pushVertex(glm::vec3(0.0f, 1.0f, 0.0f));
  this->_crystalL.pushVertex(glm::vec3(1.0f, -1.0f, -1.0f));
  this->_crystalL.pushVertex(glm::vec3(-1.0f, -1.0f, -1.0f));
  this->_crystalL.pushUv(glm::vec2(0.0f, 0.0f));
  this->_crystalL.pushUv(glm::vec2(1.0f, 0.0f));
  this->_crystalL.pushUv(glm::vec2(1.0f, 1.0f));
  this->_crystalL.pushUv(glm::vec2(0.0f, 1.0f));

  this->_crystalL.setColor(glm::vec4(0, 1, 0, 1));
  this->_crystalL.pushVertex(glm::vec3(0.0f, 1.0f, 0.0f));
  this->_crystalL.pushVertex(glm::vec3(-1.0f,-1.0f,-1.0f));
  this->_crystalL.pushVertex(glm::vec3(-1.0f,-1.0f, 1.0f));
  this->_crystalL.pushUv(glm::vec2(0.0f, 0.0f));
  this->_crystalL.pushUv(glm::vec2(1.0f, 0.0f));
  this->_crystalL.pushUv(glm::vec2(1.0f, 1.0f));
  this->_crystalL.pushUv(glm::vec2(0.0f, 1.0f));

  this->_crystalL.build();

  this->_crystalM.setColor(glm::vec4(0, 0, 1, 1));
  this->_crystalM.pushVertex(glm::vec3(0.0f, 1.0f, 0.0f));
  this->_crystalM.pushVertex(glm::vec3(-1.0f, -1.0f, 1.0f));
  this->_crystalM.pushVertex(glm::vec3(1.0f, -1.0f, 1.0f));
  this->_crystalM.pushUv(glm::vec2(0.0f, 0.0f));
  this->_crystalM.pushUv(glm::vec2(1.0f, 0.0f));
  this->_crystalM.pushUv(glm::vec2(1.0f, 1.0f));
  this->_crystalM.pushUv(glm::vec2(0.0f, 1.0f));

  this->_crystalM.setColor(glm::vec4(0, 0, 1, 1));
  this->_crystalM.pushVertex(glm::vec3(0.0f, 1.0f, 0.0f));
  this->_crystalM.pushVertex(glm::vec3(1.0f, -1.0f, 1.0f));
  this->_crystalM.pushVertex(glm::vec3(1.0f, -1.0f, -1.0f));
  this->_crystalM.pushUv(glm::vec2(0.0f, 0.0f));
  this->_crystalM.pushUv(glm::vec2(1.0f, 0.0f));
  this->_crystalM.pushUv(glm::vec2(1.0f, 1.0f));
  this->_crystalM.pushUv(glm::vec2(0.0f, 1.0f));

  this->_crystalM.setColor(glm::vec4(0, 0, 1, 1));
  this->_crystalM.pushVertex(glm::vec3(0.0f, 1.0f, 0.0f));
  this->_crystalM.pushVertex(glm::vec3(1.0f, -1.0f, -1.0f));
  this->_crystalM.pushVertex(glm::vec3(-1.0f, -1.0f, -1.0f));
  this->_crystalM.pushUv(glm::vec2(0.0f, 0.0f));
  this->_crystalM.pushUv(glm::vec2(1.0f, 0.0f));
  this->_crystalM.pushUv(glm::vec2(1.0f, 1.0f));
  this->_crystalM.pushUv(glm::vec2(0.0f, 1.0f));

  this->_crystalM.setColor(glm::vec4(0, 0, 1, 1));
  this->_crystalM.pushVertex(glm::vec3(0.0f, 1.0f, 0.0f));
  this->_crystalM.pushVertex(glm::vec3(-1.0f,-1.0f,-1.0f));
  this->_crystalM.pushVertex(glm::vec3(-1.0f,-1.0f, 1.0f));
  this->_crystalM.pushUv(glm::vec2(0.0f, 0.0f));
  this->_crystalM.pushUv(glm::vec2(1.0f, 0.0f));
  this->_crystalM.pushUv(glm::vec2(1.0f, 1.0f));
  this->_crystalM.pushUv(glm::vec2(0.0f, 1.0f));

  this->_crystalM.build();

  this->_crystalP.setColor(glm::vec4(1, 0, 1, 1));
  this->_crystalP.pushVertex(glm::vec3(0.0f, 1.0f, 0.0f));
  this->_crystalP.pushVertex(glm::vec3(-1.0f, -1.0f, 1.0f));
  this->_crystalP.pushVertex(glm::vec3(1.0f, -1.0f, 1.0f));
  this->_crystalP.pushUv(glm::vec2(0.0f, 0.0f));
  this->_crystalP.pushUv(glm::vec2(1.0f, 0.0f));
  this->_crystalP.pushUv(glm::vec2(1.0f, 1.0f));
  this->_crystalP.pushUv(glm::vec2(0.0f, 1.0f));

  this->_crystalP.setColor(glm::vec4(1, 0, 1, 1));
  this->_crystalP.pushVertex(glm::vec3(0.0f, 1.0f, 0.0f));
  this->_crystalP.pushVertex(glm::vec3(1.0f, -1.0f, 1.0f));
  this->_crystalP.pushVertex(glm::vec3(1.0f, -1.0f, -1.0f));
  this->_crystalP.pushUv(glm::vec2(0.0f, 0.0f));
  this->_crystalP.pushUv(glm::vec2(1.0f, 0.0f));
  this->_crystalP.pushUv(glm::vec2(1.0f, 1.0f));
  this->_crystalP.pushUv(glm::vec2(0.0f, 1.0f));

  this->_crystalP.setColor(glm::vec4(1, 0, 1, 1));
  this->_crystalP.pushVertex(glm::vec3(0.0f, 1.0f, 0.0f));
  this->_crystalP.pushVertex(glm::vec3(1.0f, -1.0f, -1.0f));
  this->_crystalP.pushVertex(glm::vec3(-1.0f, -1.0f, -1.0f));
  this->_crystalP.pushUv(glm::vec2(0.0f, 0.0f));
  this->_crystalP.pushUv(glm::vec2(1.0f, 0.0f));
  this->_crystalP.pushUv(glm::vec2(1.0f, 1.0f));
  this->_crystalP.pushUv(glm::vec2(0.0f, 1.0f));

  this->_crystalP.setColor(glm::vec4(1, 0, 1, 1));
  this->_crystalP.pushVertex(glm::vec3(0.0f, 1.0f, 0.0f));
  this->_crystalP.pushVertex(glm::vec3(-1.0f,-1.0f,-1.0f));
  this->_crystalP.pushVertex(glm::vec3(-1.0f,-1.0f, 1.0f));
  this->_crystalP.pushUv(glm::vec2(0.0f, 0.0f));
  this->_crystalP.pushUv(glm::vec2(1.0f, 0.0f));
  this->_crystalP.pushUv(glm::vec2(1.0f, 1.0f));
  this->_crystalP.pushUv(glm::vec2(0.0f, 1.0f));

  this->_crystalP.build();

  this->_crystalS.setColor(glm::vec4(0, 1, 1, 1));
  this->_crystalS.pushVertex(glm::vec3(0.0f, 1.0f, 0.0f));
  this->_crystalS.pushVertex(glm::vec3(-1.0f, -1.0f, 1.0f));
  this->_crystalS.pushVertex(glm::vec3(1.0f, -1.0f, 1.0f));
  this->_crystalS.pushUv(glm::vec2(0.0f, 0.0f));
  this->_crystalS.pushUv(glm::vec2(1.0f, 0.0f));
  this->_crystalS.pushUv(glm::vec2(1.0f, 1.0f));
  this->_crystalS.pushUv(glm::vec2(0.0f, 1.0f));

  this->_crystalS.setColor(glm::vec4(0, 1, 1, 1));
  this->_crystalS.pushVertex(glm::vec3(0.0f, 1.0f, 0.0f));
  this->_crystalS.pushVertex(glm::vec3(1.0f, -1.0f, 1.0f));
  this->_crystalS.pushVertex(glm::vec3(1.0f, -1.0f, -1.0f));
  this->_crystalS.pushUv(glm::vec2(0.0f, 0.0f));
  this->_crystalS.pushUv(glm::vec2(1.0f, 0.0f));
  this->_crystalS.pushUv(glm::vec2(1.0f, 1.0f));
  this->_crystalS.pushUv(glm::vec2(0.0f, 1.0f));

  this->_crystalS.setColor(glm::vec4(0, 1, 1, 1));
  this->_crystalS.pushVertex(glm::vec3(0.0f, 1.0f, 0.0f));
  this->_crystalS.pushVertex(glm::vec3(1.0f, -1.0f, -1.0f));
  this->_crystalS.pushVertex(glm::vec3(-1.0f, -1.0f, -1.0f));
  this->_crystalS.pushUv(glm::vec2(0.0f, 0.0f));
  this->_crystalS.pushUv(glm::vec2(1.0f, 0.0f));
  this->_crystalS.pushUv(glm::vec2(1.0f, 1.0f));
  this->_crystalS.pushUv(glm::vec2(0.0f, 1.0f));

  this->_crystalS.setColor(glm::vec4(0, 1, 1, 1));
  this->_crystalS.pushVertex(glm::vec3(0.0f, 1.0f, 0.0f));
  this->_crystalS.pushVertex(glm::vec3(-1.0f,-1.0f,-1.0f));
  this->_crystalS.pushVertex(glm::vec3(-1.0f,-1.0f, 1.0f));
  this->_crystalS.pushUv(glm::vec2(0.0f, 0.0f));
  this->_crystalS.pushUv(glm::vec2(1.0f, 0.0f));
  this->_crystalS.pushUv(glm::vec2(1.0f, 1.0f));
  this->_crystalS.pushUv(glm::vec2(0.0f, 1.0f));

  this->_crystalS.build();

  this->_crystalT.setColor(glm::vec4(1, 1, 0, 1));
  this->_crystalT.pushVertex(glm::vec3(0.0f, 1.0f, 0.0f));
  this->_crystalT.pushVertex(glm::vec3(-1.0f, -1.0f, 1.0f));
  this->_crystalT.pushVertex(glm::vec3(1.0f, -1.0f, 1.0f));
  this->_crystalT.pushUv(glm::vec2(0.0f, 0.0f));
  this->_crystalT.pushUv(glm::vec2(1.0f, 0.0f));
  this->_crystalT.pushUv(glm::vec2(1.0f, 1.0f));
  this->_crystalT.pushUv(glm::vec2(0.0f, 1.0f));

  this->_crystalT.setColor(glm::vec4(1, 1, 0, 1));
  this->_crystalT.pushVertex(glm::vec3(0.0f, 1.0f, 0.0f));
  this->_crystalT.pushVertex(glm::vec3(1.0f, -1.0f, 1.0f));
  this->_crystalT.pushVertex(glm::vec3(1.0f, -1.0f, -1.0f));
  this->_crystalT.pushUv(glm::vec2(0.0f, 0.0f));
  this->_crystalT.pushUv(glm::vec2(1.0f, 0.0f));
  this->_crystalT.pushUv(glm::vec2(1.0f, 1.0f));
  this->_crystalT.pushUv(glm::vec2(0.0f, 1.0f));

  this->_crystalT.setColor(glm::vec4(1, 1, 0, 1));
  this->_crystalT.pushVertex(glm::vec3(0.0f, 1.0f, 0.0f));
  this->_crystalT.pushVertex(glm::vec3(1.0f, -1.0f, -1.0f));
  this->_crystalT.pushVertex(glm::vec3(-1.0f, -1.0f, -1.0f));
  this->_crystalT.pushUv(glm::vec2(0.0f, 0.0f));
  this->_crystalT.pushUv(glm::vec2(1.0f, 0.0f));
  this->_crystalT.pushUv(glm::vec2(1.0f, 1.0f));
  this->_crystalT.pushUv(glm::vec2(0.0f, 1.0f));

  this->_crystalT.setColor(glm::vec4(1, 1, 0, 1));
  this->_crystalT.pushVertex(glm::vec3(0.0f, 1.0f, 0.0f));
  this->_crystalT.pushVertex(glm::vec3(-1.0f,-1.0f,-1.0f));
  this->_crystalT.pushVertex(glm::vec3(-1.0f,-1.0f, 1.0f));
  this->_crystalT.pushUv(glm::vec2(0.0f, 0.0f));
  this->_crystalT.pushUv(glm::vec2(1.0f, 0.0f));
  this->_crystalT.pushUv(glm::vec2(1.0f, 1.0f));
  this->_crystalT.pushUv(glm::vec2(0.0f, 1.0f));

  this->_crystalT.build();
}

const gdl::Geometry     &ModelPool::getGround() const
{
  return this->_ground;
}

const gdl::Geometry     &ModelPool::getCrystalD() const
{
  return this->_crystalD;
}

const gdl::Geometry     &ModelPool::getCrystalL() const
{
  return this->_crystalL;
}

const gdl::Geometry     &ModelPool::getCrystalM() const
{
  return this->_crystalM;
}

const gdl::Geometry     &ModelPool::getCrystalP() const
{
  return this->_crystalP;
}

const gdl::Geometry     &ModelPool::getCrystalS() const
{
  return this->_crystalS;
}

const gdl::Geometry     &ModelPool::getCrystalT() const
{
  return this->_crystalT;
}
