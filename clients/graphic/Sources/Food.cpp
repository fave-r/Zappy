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
  if (this->_model.load("./Ressources/Assets/food.fbx") == false)
    throw loading_error("Fail in Food load");
  this->scale(glm::vec3(0.01, 0.01, 0.01));
  this->translate(glm::vec3(x, 1, y));
}

Food::~Food()
{
}

void		Food::draw(gdl::AShader &shader)
{
  this->_texture.bind();
  this->_model.draw(shader, getTransformation(), GL_QUADS);
}

void		Food::setModel(const gdl::Geometry &geo)
{
  (void)geo;
}
