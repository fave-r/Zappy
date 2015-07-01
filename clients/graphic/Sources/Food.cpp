//
// Food.cpp for Food.cpp in /home/jean_c/Zappy/clients/graphic
//
// Made by jean_c
// Login   <jean_c@epitech.net>
//
// Started on  Sat Jun 27 01:11:21 2015 jean_c
// Last update Sat Jun 27 10:58:01 2015 jean_c
//

#include "Food.hh"
#include <iostream>

Food::Food(int x, int y) : AObject(x, y)
{
}

inline Food::~Food()
{
}

inline void		Food::draw(gdl::AShader &shader)
{
  this->_texture.bind();
  this->_geometry.draw(shader, getTransformation(), GL_QUADS);
}

inline void		Food::setModel(const gdl::Geometry &geo)
{
  this->_geometry = geo;
  this->scale(glm::vec3(0.5, 0.5, 0.5));
  this->translate(glm::vec3(this->_x, 2, this->_y));
}
