//
// Menu.cpp for Menu in /home/lopez_t/Zappy
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Wed Jun 10 18:13:06 2015 Thibaut Lopez
// Last update Wed Jun 10 19:01:50 2015 Thibaut Lopez
//

#include "Menu.hh"

Menu::Menu()
{
  SDL_Rect	pos;

  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    throw std::runtime_error("SDL_Init.");
  if ((this->_screen = SDL_SetVideoMode(1500, 900, 32, SDL_SWSURFACE)) == NULL)
    throw std::runtime_error("SDL_SetVideoMode.");
  SDL_WM_SetCaption("Zappy", NULL);
  SDL_FillRect(this->_screen, NULL, SDL_MapRGB(this->_screen->format, 150, 150, 150));
  pos.x = 0;
  pos.y = 0;
  this->_bg = SDL_LoadBMP(MAIN_BG);
  if (this->_bg != NULL)
    SDL_BlitSurface(this->_bg, NULL, this->_screen, &pos);
  SDL_Flip(this->_screen);
}

Menu::~Menu()
{
  SDL_FreeSurface(this->_bg);
  SDL_Quit();
}
