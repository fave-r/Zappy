//
// Menu.hh for Menu in /home/lopez_t/Zappy
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Wed Jun 10 18:13:06 2015 Thibaut Lopez
// Last update Sun Jun 14 20:55:19 2015 Thibaut Lopez
//

#ifndef	MENU_HH
#define	MENU_HH
#define	MAIN_BG	"tools/Background.bmp"

#include <iostream>
#include <string>
#include <stdexcept>
#include <unistd.h>
#include "Input.hh"
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
  SDL_Event				_event;
  void					_refresh();
public:
  Menu();
  virtual ~Menu();
  std::pair<std::string, std::string>	run(Map &);
};

#endif
