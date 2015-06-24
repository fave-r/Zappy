//
// SlideBar.hh for SlideBar in /home/lopez_t/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Mon Jun 22 14:10:10 2015 Thibaut Lopez
// Last update Wed Jun 24 03:31:47 2015 jean_c
//

#ifndef	SLIDEBAR_HH
#define	SLIDEBAR_HH
#define	MAIN_BAR	"Ressources/images/SlideBar.png"
#define	MAIN_CURSOR	"Ressources/images/Cursor.png"

#include "Rectangle.hh"

class		SlideBar : public Rectangle
{
private:
  SDL_Rect	_barPos;
  SDL_Texture	*_bar;
  bool		_selected;
public:
  explicit SlideBar(size_t, size_t);
  virtual ~SlideBar();
  size_t	getPercent() const;
  void		setPercent(size_t);
  void		init(size_t, SDL_Renderer *);
  virtual void	refresh(SDL_Renderer *);
  void		isSelected(bool);
  void		mouseMotion(int);
};

#endif