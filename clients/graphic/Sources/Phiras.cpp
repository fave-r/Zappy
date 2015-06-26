//
// Phiras.cpp for Phiras.cpp in /home/jean_c/Zappy/clients/graphic
//
// Made by jean_c
// Login   <jean_c@epitech.net>
//
// Started on  Sat Jun 27 01:11:21 2015 jean_c
// Last update Sat Jun 27 01:26:36 2015 jean_c
//

#include "Phiras.hh"

Phiras::Phiras(int x, int y) : AObject(x, y)
{
}

Phiras::~Phiras()
{
}

void		Phiras::draw(gdl::AShader &shader)
{
  this->_texture.bind();
  this->_model.draw(shader, getTransformation(), GL_QUADS);
}

void		Phiras::setModel(const gdl::Geometry &geo)
{
  (void)geo;
}
