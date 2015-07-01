//
// Player.cpp for zappy in /home/fave_r/rendu/Zappy/clients/graphic
//
// Made by romaric
// Login   <fave_r@epitech.net>
//
// Started on  Mon Jun 29 12:15:56 2015 romaric
// Last update Wed Jul  1 10:49:16 2015 romaric
//

#include "Player.hpp"

Player::Player(const int nb, const int x, const int y, const int dir, const int lev, const std::string &tn)
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
}

Player::~Player()
{
}
