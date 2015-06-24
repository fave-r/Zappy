//
// Menu.hh for Menu in /home/lopez_t/Zappy
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Wed Jun 10 18:13:06 2015 Thibaut Lopez
// Last update Wed Jun 24 03:30:43 2015 jean_c
//

#ifndef	MENU_HH
#define	MENU_HH
#define	MAIN_BG		"Ressources/images/Background.bmp"
#define	MAIN_BGM	"Ressources/OST/ScreenTitle.mp3"

#include "ScreenTitle.hh"
#include "Option.hh"

class	Menu
{
public:
  Menu();
  virtual ~Menu();
  std::pair<std::string, std::string>	run(Map &);
private:
  SDL_Window	*_screen;
  SDL_Renderer	*_ren;
  SDL_Texture	*_bg;
  ScreenTitle	*_st;
  Option	*_opt;
  IRefreshable	*_current;
  SDL_Event	_event;
  void		_refresh();
};

#endif
