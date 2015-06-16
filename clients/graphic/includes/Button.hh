//
// Button.hh for Button in /home/lopez_t/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Sun Jun 14 21:52:13 2015 Thibaut Lopez
// Last update Tue Jun 16 18:12:32 2015 Thibaut Lopez
//

#ifndef	BUTTON_HH
#define	BUTTON_HH

#include "Rectangle.hh"

class	Button : public Rectangle
{
public:
  explicit Button(size_t, size_t);
  virtual ~Button();
  void		load(SDL_Renderer *, const std::string &);
};

#endif
