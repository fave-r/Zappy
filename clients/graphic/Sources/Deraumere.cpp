//
// Deraumere.cpp for Deraumere.cpp in /home/jean_c/Zappy/clients/graphic
//
// Made by jean_c
// Login   <jean_c@epitech.net>
//
// Started on  Sat Jun 27 01:11:21 2015 jean_c
// Last update Sat Jun 27 01:21:33 2015 jean_c
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
  this->_texture.bind();
  this->_model.draw(shader, getTransformation(), GL_QUADS);
}

void		Deraumere::setModel(const gdl::Geometry &geo)
{
  (void)geo;
}