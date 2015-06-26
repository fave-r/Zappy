//
// TextBox.hh for TextBox in /home/lopez_t/BONUS/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Wed Jun 24 17:39:41 2015 Thibaut Lopez
// Last update Fri Jun 26 16:51:58 2015 Thibaut Lopez
//

#ifndef	TEXTBOX_HH
#define	TEXTBOX_HH

#include "Rectangle.hh"
#include <SDL2/SDL_ttf.h>

class		TextBox : public Rectangle
{
public:
  explicit TextBox(size_t, size_t);
  virtual ~TextBox();
  void		load(SDL_Renderer *, const std::string &, TTF_Font *, SDL_Color &);
};

#endif
