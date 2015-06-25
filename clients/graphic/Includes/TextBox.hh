//
// TextBox.hh for TextBox in /home/lopez_t/BONUS/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Wed Jun 24 17:39:41 2015 Thibaut Lopez
// Last update Wed Jun 24 17:50:24 2015 Thibaut Lopez
//

#ifndef	TEXTBOX_HH
#define	TEXTBOX_HH

#include "Rectangle.hh"

class		TextBox : public Rectangle
{
public:
  explicit TextBox(size_t, size_t);
  virtual ~TextBox();
  void		load(SDL_Renderer *, const std::string &, TTF_Font *, SDL_Color &);
};

#endif
