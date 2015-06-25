//
// TextBox.cpp for TextBox in /home/lopez_t/BONUS/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Wed Jun 24 17:39:41 2015 Thibaut Lopez
// Last update Wed Jun 24 18:06:19 2015 Thibaut Lopez
//

#include "TextBox.hh"

TextBox::TextBox(size_t x, size_t y)
  : Rectangle(x, y)
{
}

TextBox::~TextBox()
{
}

void		TextBox::load(SDL_Renderer *ren, const std::string &text, TTF_Font *font, SDL_Color &color)
{
  SDL_Surface	*txt;

  txt = TTF_RenderText_Blended(font, text.c_str(), color);
  if (txt == NULL)
    throw std::runtime_error("TTF_RenderText_Blender.");
  this->_box = SDL_CreateTextureFromSurface(ren, txt);
  if (this->_box == NULL)
    throw std::runtime_error("SDL_CreateTextureFromSurface.");
  SDL_QueryTexture(this->_box, NULL, NULL, &this->_pos.w, &this->_pos.h);
}
