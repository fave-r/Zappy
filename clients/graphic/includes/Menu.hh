//
// Menu.hh for Menu in /home/lopez_t/Zappy
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Wed Jun 10 18:13:06 2015 Thibaut Lopez
// Last update Thu Jun 18 19:17:24 2015 Thibaut Lopez
//

#ifndef	MENU_HH
#define	MENU_HH
#define	MAIN_BG		"tools/images/Background.bmp"
#define	START_BUTTON	"tools/images/Start.png"
#define	START_BUTTON_MO	"tools/images/StartMouseOn.png"
#define	OPTI_BUTTON	"tools/images/Start.png"
#define	OPTI_BUTTON_MO	"tools/images/StartMouseOn.png"
#define	QUIT_BUTTON	"tools/images/Start.png"
#define	QUIT_BUTTON_MO	"tools/images/StartMouseOn.png"
#define	MAIN_BGM	"tools/OST/ScreenTitle.mp3"

#include "Input.hh"
#include "Button.hh"
#include "Map.hh"

class	Menu
{
public:
  Menu();
  virtual ~Menu();
  std::pair<std::string, std::string>	run(Map &);
private:
  typedef	void	(Menu::*ptr)(bool &, std::pair<std::string, std::string> &);
  SDL_Window	*_screen;
  SDL_Renderer	*_ren;
  SDL_Texture	*_bg;
  Input		*_ip;
  Input		*_port;
  Input		*_selected;
  Button	*_start;
  Button	*_option;
  Button	*_quit;
  SDL_Event	_event;
  std::map<Uint32, ptr>	_eventType;
  void		_etQuit(bool &, std::pair<std::string, std::string> &);
  void		_etKeyUp(bool &, std::pair<std::string, std::string> &);
  void		_etTextInput(bool &, std::pair<std::string, std::string> &);
  void		_etMouseButtonDown(bool &, std::pair<std::string, std::string> &);
  void		_etMouseMotion(bool &, std::pair<std::string, std::string> &);
  void		_refresh();
};

#endif
