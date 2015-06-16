//
// Button.cpp for Button in /home/lopez_t/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Sun Jun 14 21:52:13 2015 Thibaut Lopez
// Last update Tue Jun 16 18:27:59 2015 Thibaut Lopez
//

#include "Button.hh"

Button::Button(size_t posX, size_t posY)
  : Rectangle(posX, posY)
{
}

Button::~Button()
{
}

void		Button::load(SDL_Renderer *ren, const std::string &img)
{
  SDL_Surface	*surf;

  surf = SDL_LoadBMP(img.c_str());
  if (surf == NULL)
    throw std::runtime_error("SDL_LoadBMP.");
  this->_box = SDL_CreateTextureFromSurface(ren, surf);
  SDL_FreeSurface(surf);
  if (this->_box == NULL)
    throw std::runtime_error("SDL_CreateTextureFromSurface.");
  SDL_QueryTexture(this->_box, NULL, NULL, &this->_pos.w, &this->_pos.h);
}
