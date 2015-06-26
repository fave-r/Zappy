//
// Sibur.cpp for Sibur.cpp in /home/jean_c/Zappy/clients/graphic
//
// Made by jean_c
// Login   <jean_c@epitech.net>
//
// Started on  Sat Jun 27 01:11:21 2015 jean_c
// Last update Sat Jun 27 01:23:10 2015 jean_c
//

#include "Sibur.hh"

Sibur::Sibur(int x, int y) : AObject(x, y)
{
}

Sibur::~Sibur()
{
}

void		Sibur::draw(gdl::AShader &shader)
{
  this->_texture.bind();
  this->_model.draw(shader, getTransformation(), GL_QUADS);
}

void		Sibur::setModel(const gdl::Geometry &geo)
{
  (void)geo;
}
