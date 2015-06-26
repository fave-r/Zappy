//
// Thystame.cpp for Thystame.cpp in /home/jean_c/Zappy/clients/graphic
//
// Made by jean_c
// Login   <jean_c@epitech.net>
//
// Started on  Sat Jun 27 01:11:21 2015 jean_c
// Last update Sat Jun 27 01:28:00 2015 jean_c
//

#include "Thystame.hh"

Thystame::Thystame(int x, int y) : AObject(x, y)
{
}

Thystame::~Thystame()
{
}

void		Thystame::draw(gdl::AShader &shader)
{
  this->_texture.bind();
  this->_model.draw(shader, getTransformation(), GL_QUADS);
}

void		Thystame::setModel(const gdl::Geometry &geo)
{
  (void)geo;
}
