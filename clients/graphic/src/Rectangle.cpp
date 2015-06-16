//
// Rectangle.cpp for Rectangle in /home/lopez_t/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Tue Jun 16 17:57:33 2015 Thibaut Lopez
// Last update Tue Jun 16 18:15:00 2015 Thibaut Lopez
//

#include "Rectangle.hh"

Rectangle::Rectangle(size_t posX, size_t posY)
  : _box(NULL)
{
  this->_pos.x = posX;
  this->_pos.y = posY;
  this->_pos.h = 0;
  this->_pos.w = 0;
}

Rectangle::~Rectangle()
{
  SDL_DestroyTexture(this->_box);
}

bool	Rectangle::isClicked(int x, int y) const
{
  return (x >= this->_pos.x && x <= this->_pos.x + this->_pos.w && y >= this->_pos.y && y <= this->_pos.y + this->_pos.h);
}

void	Rectangle::refresh(SDL_Renderer *ren)
{
  SDL_RenderCopy(ren, this->_box, NULL, &this->_pos);
}
