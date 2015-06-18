//
// Button.hh for Button in /home/lopez_t/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Sun Jun 14 21:52:13 2015 Thibaut Lopez
// Last update Thu Jun 18 17:31:30 2015 Thibaut Lopez
//

#ifndef	BUTTON_HH
#define	BUTTON_HH

#include "Rectangle.hh"
#include "Music.hh"

class	Button : public Rectangle
{
private:
  bool		_mouseOn;
  SDL_Texture	*_boxMouseOn;
public:
  explicit Button(size_t, size_t);
  virtual ~Button();
  void		load(SDL_Renderer *, const std::string &, const std::string &);
  void		isMouseOn(int, int);
  virtual void	refresh(SDL_Renderer *);
};

#endif
