//
// Ground.cpp for Ground.cpp in /home/jean_c/Dropbox/zappy
//
// Made by jean_c
// Login   <jean_c@epitech.net>
//
// Started on  Sun Jun 21 02:16:23 2015 jean_c
// Last update Sun Jun 21 02:17:52 2015 jean_c
//

#include "Ground.hh"

Ground::Ground(int x, int y) : AObject(x, y)
{
}

Ground::~Ground()
{
}

void                    Ground::draw(gdl::AShader &shader)
{
  this->_texture.bind();
  this->_geometry.draw(shader, getTransformation(), GL_QUADS);
}

void                    Ground::setModel(const gdl::Geometry &geo)
{
  this->_geometry = geo;
}
