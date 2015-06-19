//
// Rectangle.hh for Rectangle in /home/lopez_t/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Tue Jun 16 17:57:33 2015 Thibaut Lopez
// Last update Fri Jun 19 12:59:16 2015 Thibaut Lopez
//

#ifndef	RECTANGLE_HH
#define	RECTANGLE_HH

#include <iostream>
#include <string>
#include <stdexcept>
#include <SDL2/SDL.h>
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"

class	Rectangle
{
protected:
  SDL_Rect	_pos;
  SDL_Texture	*_box;
public:
  explicit Rectangle(size_t, size_t);
  virtual ~Rectangle();
  virtual bool	isClicked(int, int) const;
  virtual void	refresh(SDL_Renderer *);
};

#endif
