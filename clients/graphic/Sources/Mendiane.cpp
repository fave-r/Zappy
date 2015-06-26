//
// Mendiane.cpp for Mendiane.cpp in /home/jean_c/Zappy/clients/graphic
//
// Made by jean_c
// Login   <jean_c@epitech.net>
//
// Started on  Sat Jun 27 01:11:21 2015 jean_c
// Last update Sat Jun 27 01:24:29 2015 jean_c
//

#include "Mendiane.hh"

Mendiane::Mendiane(int x, int y) : AObject(x, y)
{
}

Mendiane::~Mendiane()
{
}

void		Mendiane::draw(gdl::AShader &shader)
{
  this->_texture.bind();
  this->_model.draw(shader, getTransformation(), GL_QUADS);
}

void		Mendiane::setModel(const gdl::Geometry &geo)
{
  (void)geo;
}
