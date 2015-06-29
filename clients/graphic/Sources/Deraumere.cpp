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
}

Deraumere::~Deraumere()
{
}

void		Deraumere::draw(gdl::AShader &shader)
{
  this->_geometry.draw(shader, getTransformation(), GL_TRIANGLES);
}

void		Deraumere::setModel(const gdl::Geometry &geo)
{
  this->_geometry = geo;
  this->translate(glm::vec3(this->_x - 0.2, 1, this->_y - 0.2));
  this->scale(glm::vec3(0.1, 0.1, 0.1));
}
