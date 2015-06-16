//
// Button.hh for Button in /home/lopez_t/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Sun Jun 14 21:52:13 2015 Thibaut Lopez
// Last update Mon Jun 15 19:27:23 2015 Thibaut Lopez
//

#ifndef	BUTTON_HH
#define	BUTTON_HH

#include <iostream>
#include <string>
#include <stdexcept>
#include <SDL2/SDL.h>
#include "SDL2/SDL_ttf.h"

class	Button
{
private:
  SDL_Rect	_pos;
  SDL_Texture	*_box;
public:
  explicit Button(size_t, size_t);
  virtual ~Button();
  bool		load(SDL_Renderer *, const std::string &);
  bool		load(SDL_Renderer *, size_t, size_t, Uint32, Uint32, const std::string &);
};

#endif
