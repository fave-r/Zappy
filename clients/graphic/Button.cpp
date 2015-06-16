//
// Button.cpp for Button in /home/lopez_t/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Sun Jun 14 21:52:13 2015 Thibaut Lopez
// Last update Mon Jun 15 19:27:58 2015 Thibaut Lopez
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

bool		Button::load(SDL_Renderer *ren, const std::string &img)
{
  SDL_Surface	*surf;

  surf = SDL_LoadBMP(img.c_str());
  if (surf == NULL)
    return (false);
  this->_box = SDL_CreateTextureFromSurface(ren, surf);
  SDL_FreeSurface(surf);
  if (this->_box == NULL)
    throw std::runtime_error("SDL_CreateTextureFromSurface.");
  return (true);
}

bool		Button::load(SDL_Renderer *ren, size_t width, size_t height, Uint32 bgColor, Uint32 frameColor, const std::string &text)
{

}
