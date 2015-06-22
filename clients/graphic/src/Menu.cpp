//
// Menu.cpp for Menu in /home/lopez_t/Zappy
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Wed Jun 10 18:13:06 2015 Thibaut Lopez
// Last update Mon Jun 22 13:50:15 2015 Thibaut Lopez
//

#include "Menu.hh"

Menu::Menu()
{
  SDL_Surface	*bg;
  Music		*music;

  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    throw std::runtime_error("SDL_Init.");
  if (TTF_Init() == -1)
    throw std::runtime_error("TTF_Init.");
  if ((this->_screen = SDL_CreateWindow("Zappy", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1500, 900, SDL_WINDOW_SHOWN)) == NULL)
    throw std::runtime_error("SDL_CreateWindow.");
  if ((this->_ren = SDL_CreateRenderer(this->_screen, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)) == NULL)
    throw std::runtime_error("SDL_CreateRenderer.");
  bg = SDL_LoadBMP(MAIN_BG);
  if (bg == NULL)
    {
      if ((bg = SDL_CreateRGBSurface(0, 1500, 900, 32, 0, 0, 0, 0)) == NULL)
	throw std::runtime_error("SDL_CreateRenderer.");
      SDL_FillRect(bg, NULL, SDL_MapRGB(bg->format, 150, 150, 150));
    }
  this->_bg = SDL_CreateTextureFromSurface(this->_ren, bg);
  SDL_FreeSurface(bg);
  if (this->_bg == NULL)
    throw std::runtime_error("SDL_CreateTextureFromSurface.");
  music = Music::newinstance();
  music->createSound(MAIN_BGM, "title");
  music->playSound("title", true);
  this->_st = new ScreenTitle(this->_ren);
  this->_opt = new Option(this->_ren);
  this->_current = this->_st;
  this->_refresh();
}

Menu::~Menu()
{
  Music		*music;

  SDL_DestroyTexture(this->_bg);
  SDL_DestroyRenderer(this->_ren);
  SDL_DestroyWindow(this->_screen);
  TTF_Quit();
  SDL_Quit();
  music = Music::newinstance();
  delete music;
}

void	Menu::_refresh()
{
  SDL_RenderClear(this->_ren);
  SDL_RenderCopy(this->_ren, this->_bg, NULL, NULL);
  this->_current->refresh(this->_ren);
  SDL_RenderPresent(this->_ren);
}

std::pair<std::string, std::string>	Menu::run(Map &map)
{
  std::pair<std::string, std::string>	ret;
  bool					loop;
  Ret					eventRet;

  ret.first = "";
  ret.second = "";
  SDL_StartTextInput();
  loop = true;
  while (loop)
    {
      while (SDL_PollEvent(&this->_event))
	{
	  eventRet = this->_current->handleKeys(this->_event, map, ret);
	  if (eventRet == CHANGE)
	    {
	      if (this->_current == this->_st)
		this->_current = this->_opt;
	      else
		this->_current = this->_st;
	    }
	  else if (eventRet == RETURN)
	    loop = false;
	}
      this->_refresh();
    }
  SDL_StopTextInput();
  return (ret);
}
