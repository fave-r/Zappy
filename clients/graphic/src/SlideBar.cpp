//
// SlideBar.cpp for SlideBar in /home/lopez_t/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Mon Jun 22 14:10:10 2015 Thibaut Lopez
// Last update Mon Jun 22 17:23:15 2015 Thibaut Lopez
//

#include "SlideBar.hh"

SlideBar::SlideBar(size_t x, size_t y)
  : Rectangle(x, y), _selected(false)
{
  this->_barPos.x = x;
  this->_barPos.y = y;
}


SlideBar::~SlideBar()
{
  SDL_DestroyTexture(this->_bar);
}

size_t		SlideBar::getPercent() const
{
  size_t	percent;
  
  percent = this->_pos.x - this->_barPos.x;
  percent *= 100;
  percent /= this->_barPos.w;
  return (percent);
}

void		SlideBar::setPercent(size_t percent)
{
  if (percent > 100)
    percent = 100;
  percent *= this->_barPos.w;
  percent /= 100;
  this->_pos.x = this->_barPos.x + percent;
}

void		SlideBar::init(size_t width, SDL_Renderer *ren)
{
  this->_bar = IMG_LoadTexture(ren, MAIN_BAR);
  this->_box = IMG_LoadTexture(ren, MAIN_CURSOR);
  SDL_QueryTexture(this->_box, NULL, NULL, &this->_pos.w, &this->_pos.h);
  SDL_QueryTexture(this->_bar, NULL, NULL, &this->_barPos.w, &this->_barPos.h);
  this->_barPos.y += this->_pos.h / 2 - this->_barPos.h / 2;
  this->_barPos.w = width;
}

void		SlideBar::refresh(SDL_Renderer *ren)
{
  SDL_RenderCopy(ren, this->_bar, NULL, &this->_barPos);
  Rectangle::refresh(ren);
}

void		SlideBar::isSelected(bool selected)
{
  this->_selected = selected;
}

void		SlideBar::mouseMotion(int x)
{
  if (this->_selected)
    {
      x -= this->_barPos.x;
      if (x > 0)
	{
	  x *= 100;
	  x /= this->_barPos.w;
	}
      else
	x = 0;
      this->setPercent(x);
    }
}
