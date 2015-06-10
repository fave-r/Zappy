//
// Menu.hh for Menu in /home/lopez_t/Zappy
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Wed Jun 10 18:13:06 2015 Thibaut Lopez
// Last update Wed Jun 10 18:56:48 2015 Thibaut Lopez
//

#ifndef	MENU_HH
#define	MENU_HH
#define	MAIN_BG	"./tools/Background.bmp"

#include <iostream>
#include <string>
#include <stdexcept>
#include <SDL/SDL.h>

class	Menu
{
private:
  SDL_Surface	*_screen;
  SDL_Surface	*_bg;
public:
  Menu();
  virtual ~Menu();
};

#endif
