//
// Linemate.cpp for Linemate.cpp in /home/jean_c/Zappy/clients/graphic/Sources
//
// Made by jean_c
// Login   <jean_c@epitech.net>
//
// Started on  Sat Jun 27 01:17:57 2015 jean_c
// Last update Sat Jun 27 09:57:07 2015 jean_c
//

#include "Linemate.hh"

Linemate::Linemate(int x, int y) : AObject(x, y)
{
  if (this->_model.load("./Ressources/Assets/CyanCrystal.fbx") == false)
    throw loading_error("Fail in Linemate load");
  this->translate(glm::vec3(x, 1, y));
}

Linemate::~Linemate()
{
}

void		Linemate::draw(gdl::AShader &shader)
{
  this->_texture.bind();
  this->_model.draw(shader, getTransformation(), GL_QUADS);
}

void		Linemate::setModel(const gdl::Geometry &geo)
{
  (void)geo;
}
