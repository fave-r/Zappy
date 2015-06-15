//
// Button.hh for Button in /home/lopez_t/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Sun Jun 14 21:52:13 2015 Thibaut Lopez
// Last update Sun Jun 14 21:58:40 2015 Thibaut Lopez
//

#ifndef	BUTTON_HH
#define	BUTTON_HH

#include <iostream>
#include <string>

class	Button
{
private:
  SDL_Rect	_pos;
  SDL_Texture	*_box;
public:
  explicit Button(size_t, size_t);
  virtual ~Button();
};

#endif
