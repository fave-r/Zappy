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

gdl::Model Food::_model;
bool Food::_isInit = false;

Food::Food(int x, int y) : AObject(x, y)
{
  if (this->_isInit == false)
  {
    if (this->_model.load("./Ressources/Assets/food.fbx") == false)
      throw loading_error("Fail in Food load");
    this->_isInit = true;
  }
  this->scale(glm::vec3(0.005, 0.005, 0.005));
  this->translate(glm::vec3(x, 0.5, y));
}

inline Food::~Food()
{
}

inline void		Food::draw(gdl::AShader &shader)
{
  //this->_texture.bind();
  this->_model.draw(shader, getTransformation(), GL_QUADS);
}

inline void		Food::setModel(const gdl::Geometry &geo)
{
  (void)geo;
  //this->scale(glm::vec3(0.1, 0.1, 0.1));
  //this->translate(glm::vec3(this->_x, 1, this->_y));
  //this->_geometry = geo;
}
