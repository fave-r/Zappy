//
// Button.cpp for Button in /home/lopez_t/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Sun Jun 14 21:52:13 2015 Thibaut Lopez
// Last update Fri Jun 19 17:08:45 2015 Thibaut Lopez
//

#include "Button.hh"

Button::Button(size_t posX, size_t posY)
  : Rectangle(posX, posY), _mouseOn(false), _boxMouseOn(NULL)
{
  Music		*music;

  music = Music::newinstance();
  music->createSound(CLICK_SOUND, "click", false);
}

Button::~Button()
{
}

void		Button::load(SDL_Renderer *ren, const std::string &img, const std::string &mouseOn)
{
  this->_box = IMG_LoadTexture(ren, img.c_str());
  this->_boxMouseOn = IMG_LoadTexture(ren, mouseOn.c_str());
  if (this->_box == NULL || this->_boxMouseOn == NULL)
    throw std::runtime_error("SDL_CreateTextureFromSurface.");
  SDL_QueryTexture(this->_box, NULL, NULL, &this->_pos.w, &this->_pos.h);

}

void		Button::isMouseOn(int x, int y)
{
  this->_mouseOn = Rectangle::isClicked(x, y);
}

bool		Button::isClicked(int x, int y) const
{
  bool		ret;

  ret = Rectangle::isClicked(x, y);
  if (ret == true)
    (Music::newinstance())->playSound("click");
  SDL_Delay(300);
  return (ret);
}

void		Button::refresh(SDL_Renderer *ren)
{
  if (_mouseOn)
    SDL_RenderCopy(ren, this->_boxMouseOn, NULL, &this->_pos);
  else
    Rectangle::refresh(ren);
}
