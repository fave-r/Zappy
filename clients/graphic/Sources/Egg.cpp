//
// egg.cpp for egg.cpp in /home/jean_c/Zappy/clients/graphic
//
// Made by jean_c
// Login   <jean_c@epitech.net>
//
// Started on  Sat Jul  4 22:33:12 2015 jean_c
// Last update Sat Jul  4 22:34:02 2015 jean_c
//

#include "Egg.hh"

gdl::Model  Egg::_model;
int         Egg::_init = false;

Egg::Egg(int x, int y) : AObject(x, y)
{
  if (this->_init == false)
    {
      if (this->_model.load("./Ressources/Assets/egg.fbx") == false)
        throw loading_error("Egg model fail");
      this->_init = true;
    }
    this->scale(glm::vec3(0.003, 0.003, 0.003));
    this->translate(glm::vec3(this->_y, 1, this->_x));
}

Egg::~Egg()
{
}

inline void          Egg::draw(gdl::AShader &shader)
{
  this->_model.draw(shader, getTransformation(), GL_TRIANGLES);
}

void		      Egg::setModel(const gdl::Geometry &geo)
{
  (void)geo;
}
