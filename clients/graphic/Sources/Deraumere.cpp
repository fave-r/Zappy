//
// Deraumere.cpp for Deraumere.cpp in /home/jean_c/Zappy/clients/graphic
//
// Made by jean_c
// Login   <jean_c@epitech.net>
//
// Started on  Sat Jun 27 01:11:21 2015 jean_c
// Last update Sat Jun 27 09:57:59 2015 jean_c
//

#include "Deraumere.hh"

Deraumere::Deraumere(int x, int y) : AObject(x, y)
{
  if (this->_model.load("./Ressources/Assets/YellowCrystal.fbx") == false)
    throw loading_error("Fail in Deraumere load");
  this->translate(glm::vec3(x, 1, y));
}

Deraumere::~Deraumere()
{
}

void		Deraumere::draw(gdl::AShader &shader)
{
  this->_texture.bind();
  this->_model.draw(shader, getTransformation(), GL_QUADS);
}

void		Deraumere::setModel(const gdl::Geometry &geo)
{
  (void)geo;
}
