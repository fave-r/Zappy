//
// Menu.hh for Menu in /home/lopez_t/Zappy
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Wed Jun 10 18:13:06 2015 Thibaut Lopez
// Last update Wed Jun 17 19:35:58 2015 Thibaut Lopez
//

#ifndef	MENU_HH
#define	MENU_HH
#define	MAIN_BG		"tools/Background.bmp"
#define	START_BUTTON	"tools/Start.png"
#define	START_BUTTON_MO	"tools/StartMouseOn.png"
#define	OPTI_BUTTON	"tools/Start.png"
#define	OPTI_BUTTON_MO	"tools/StartMouseOn.png"
#define	QUIT_BUTTON	"tools/Start.png"
#define	QUIT_BUTTON_MO	"tools/StartMouseOn.png"

#include "Input.hh"
#include "Button.hh"
#include "Map.hh"

class	Menu
{
private:
  SDL_Window				*_screen;
  SDL_Renderer				*_ren;
  SDL_Texture				*_bg;
  Input					*_ip;
  Input					*_port;
  Input					*_selected;
  Button				*_start;
  Button				*_option;
  Button				*_quit;
  SDL_Event				_event;
  void					_refresh();
public:
  Menu();
  virtual ~Menu();
  std::pair<std::string, std::string>	run(Map &);
};

#endif
