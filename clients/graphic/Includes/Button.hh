//
// Button.hh for Button in /home/lopez_t/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Sun Jun 14 21:52:13 2015 Thibaut Lopez
// Last update Wed Jun 24 03:30:14 2015 jean_c
//

#ifndef	BUTTON_HH
#define	BUTTON_HH
#define	CLICK_SOUND	"Ressources/OST/Click.ogg"

#include "Rectangle.hh"
#include "Music.hh"
#include <thread>

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
  virtual bool	isClicked(int, int) const;
  virtual void	refresh(SDL_Renderer *);
};

#endif