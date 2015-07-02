//
// Player.cpp for zappy in /home/fave_r/rendu/Zappy/clients/graphic
//
// Made by romaric
// Login   <fave_r@epitech.net>
//
// Started on  Mon Jun 29 12:15:56 2015 romaric
// Last update Wed Jul  1 18:20:27 2015 romaric
//

#include "Player.hpp"

gdl::Model  Player::_model;
int         Player::_init = false;

Player::Player(const int nb, const int x, const int y, const int dir, const int lev, const std::string &tn)
  : AObject(x, y)
{
  this->_nb = nb;
  this->_x = x;
  this->_y = y;
  this->_dir = dir;
  this->_level = lev;
  this->_tn = tn;
  this->_food = 0;
  this->_linemate = 0;
  this->_deraumere = 0;
  this->_sibur = 0;
  this->_mendiane = 0;
  this->_phiras = 0;
  this->_thystame = 0;
  this->_x1 = x;
  this->_y1 = y;
  if (this->_init == false)
    {
      if (this->_model.load("./Ressources/Assets/player.fbx") == false)
        throw loading_error("Player model fail");
      this->_init = true;
    }
}

Player::~Player()
{
}

void          Player::draw(gdl::AShader &shader)
{
    this->_model.draw(shader, getTransformation(), GL_QUADS);
}

void		      Player::setModel(const gdl::Geometry &geo)
{
  (void)geo;
}
