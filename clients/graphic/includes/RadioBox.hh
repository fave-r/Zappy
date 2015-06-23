//
// RadioBox.hh for RadioBox in /home/lopez_t/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Tue Jun 23 15:58:55 2015 Thibaut Lopez
// Last update Tue Jun 23 18:30:28 2015 Thibaut Lopez
//

#ifndef	RADIOBOX_HH
#define	RADIOBOX_HH
#define	MAIN_RB		"tools/images/RadioBox.png"
#define SELECTED_RB	"tools/images/RadioBoxSelected.png"

#include "Rectangle.hh"

class		RadioBox : public Rectangle
{
private:
  SDL_Texture	*_boxSelected;
  bool		_selected;

public:
  explicit RadioBox(size_t, size_t);
  virtual ~RadioBox();
  bool		isSelected() const;
  void		setSelected(bool);
  void		init(SDL_Renderer *, bool = false);
  virtual void	refresh(SDL_Renderer *);
};

#endif
