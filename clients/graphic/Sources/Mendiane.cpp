//
// Mendiane.cpp for Mendiane.cpp in /home/jean_c/Zappy/clients/graphic
//
// Made by jean_c
// Login   <jean_c@epitech.net>
//
// Started on  Sat Jun 27 01:11:21 2015 jean_c
// Last update Sat Jul  4 22:38:23 2015 Leo Thevenet
//

#include "Mendiane.hh"

Mendiane::Mendiane(int x, int y) : AObject(x, y)
{
}

Mendiane::~Mendiane()
{
}

inline void		Mendiane::draw(gdl::AShader &shader)
{
  glDisable(GL_TEXTURE_2D);
  this->_geometry.draw(shader, getTransformation(), GL_TRIANGLES);
  glEnable(GL_TEXTURE_2D);
}

inline void		Mendiane::setModel(const gdl::Geometry &geo)
{
  this->_geometry = geo;
  this->translate(glm::vec3(this->_x + 0.2, 0.8, this->_y - 0.2));
  this->scale(glm::vec3(0.1, 0.1, 0.1));
}
