//
// Button.cpp for Button in /home/lopez_t/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Sun Jun 14 21:52:13 2015 Thibaut Lopez
// Last update Sun Jun 14 22:01:10 2015 Thibaut Lopez
//

#include "Button.hh"

Button::Button(size_t posX, size_t posY)
  : _box(NULL)
{
  this->_pos.x = posX;
  this->_pos.y = posY;
  this->_pos.h = 0;
  this->_pos.w = 0;
}

Button::~Button()
{
  SDL_DestroyTexture(this->_box);
}
