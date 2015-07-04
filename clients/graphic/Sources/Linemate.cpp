//
// Linemate.cpp for Linemate.cpp in /home/jean_c/Zappy/clients/graphic/Sources
//
// Made by jean_c
// Login   <jean_c@epitech.net>
//
// Started on  Sat Jun 27 01:17:57 2015 jean_c
// Last update Sat Jul  4 22:38:43 2015 Leo Thevenet
//

#include "Linemate.hh"

Linemate::Linemate(int x, int y) : AObject(x, y)
{
}

Linemate::~Linemate()
{
}

inline void		Linemate::draw(gdl::AShader &shader)
{
  glDisable(GL_TEXTURE_2D);
  this->_geometry.draw(shader, getTransformation(), GL_TRIANGLES);
  glEnable(GL_TEXTURE_2D);
}

inline void		Linemate::setModel(const gdl::Geometry &geo)
{
  this->_geometry = geo;
  this->translate(glm::vec3(this->_x + 0.2, 0.8, this->_y + 0.2));
  this->scale(glm::vec3(0.1, 0.1, 0.1));
}
