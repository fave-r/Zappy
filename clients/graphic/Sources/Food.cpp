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

gdl::Model  Food::_model;
int         Food::_init = false;

Food::Food(int x, int y) : AObject(x, y)
{
  if (this->_init == false)
    {
      if (this->_model.load("./Ressources/Assets/food.fbx") == false)
        throw loading_error("food model fail");
        this->_init = true;
    }
    this->scale(glm::vec3(0.009, 0.009, 0.009));
    this->translate(glm::vec3(this->_x, 1, this->_y));
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
  /*this->_geometry = geo;
  this->scale(glm::vec3(0.5, 0.5, 0.5));
  this->translate(glm::vec3(this->_x, 2, this->_y));*/
}
