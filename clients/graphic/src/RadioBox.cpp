//
// RadioBox.cpp for RadioBox in /home/lopez_t/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Tue Jun 23 15:58:55 2015 Thibaut Lopez
// Last update Tue Jun 23 18:31:51 2015 Thibaut Lopez
//

#include "RadioBox.hh"

RadioBox::RadioBox(size_t x, size_t y)
  : Rectangle(x, y)
{
}

RadioBox::~RadioBox()
{
  SDL_DestroyTexture(this->_boxSelected);
}

bool	RadioBox::isSelected() const
{
  return (this->_selected);
}

void	RadioBox::setSelected(bool selected)
{
  this->_selected = selected;
}

void	RadioBox::init(SDL_Renderer *ren, bool selected)
{
  this->_box = IMG_LoadTexture(ren, MAIN_RB);
  this->_boxSelected = IMG_LoadTexture(ren, SELECTED_RB);
  if (this->_box == NULL || this->_boxSelected == NULL)
    throw std::runtime_error("SDL_CreateTextureFromSurface.");
  SDL_QueryTexture(this->_box, NULL, NULL, &this->_pos.w, &this->_pos.h);
  this->_selected = selected;
}

void	RadioBox::refresh(SDL_Renderer *ren)
{
  if (this->_selected)
    SDL_RenderCopy(ren, this->_boxSelected, NULL, &this->_pos);
  else
    Rectangle::refresh(ren);
}
