//
// Menu.cpp for Menu in /home/lopez_t/Zappy
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Wed Jun 10 18:13:06 2015 Thibaut Lopez
// Last update Sun Jun 14 18:55:07 2015 Thibaut Lopez
//

#include "Menu.hh"

Menu::Menu()
  : _ip(true), _port(false)
{
  SDL_Surface	*bg;

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
  this->_ip.init(250, 300, 400, 70, this->_ren);
  this->_port.init(850, 300, 400, 70, this->_ren);
  this->_selected = &this->_ip;
  this->_refresh();
}

Menu::~Menu()
{
  SDL_DestroyTexture(this->_bg);
  SDL_DestroyRenderer(this->_ren);
  SDL_DestroyWindow(this->_screen);
  TTF_Quit();
  SDL_Quit();
}

void	Menu::_refresh()
{
  SDL_RenderClear(this->_ren);
  SDL_RenderCopy(this->_ren, this->_bg, NULL, NULL);
  this->_ip.refresh(this->_ren);
  this->_port.refresh(this->_ren);
  SDL_RenderPresent(this->_ren);
}

void	Menu::run(Map &map)
{
  (void)map;
  while (SDL_WaitEvent(&this->_event))
    {
      if (this->_event.type == SDL_QUIT || this->_event.key.keysym.sym == SDLK_ESCAPE)
	return ;
      if (this->_selected != NULL && this->_event.type == SDL_KEYUP)
	{
	  if (this->_event.key.keysym.sym == SDLK_RIGHT)
	    {
	      this->_selected->curRight();
	      this->_refresh();
	    }
	  else if (this->_event.key.keysym.sym == SDLK_LEFT)
	    {
	      this->_selected->curLeft();
	      this->_refresh();
	    }
	  else if (this->_event.key.keysym.sym == SDLK_BACKSPACE)
	    {
	      this->_selected->deleteChar();
	      this->_refresh();
	    }
	  else if (this->_event.key.keysym.sym == SDLK_DELETE)
	    {
	      this->_selected->supprChar();
	      this->_refresh();
	    }
	  usleep(100000);
	}
      else if (this->_selected != NULL && this->_event.type == SDL_TEXTINPUT)
	{
	  this->_selected->addChar(this->_event.text.text, this->_ren);
	  this->_refresh();
	}
      else if (this->_event.type == SDL_MOUSEBUTTONDOWN && this->_event.button.button == SDL_BUTTON_LEFT)
	{
	  if (this->_event.button.x >= 250 && this->_event.button.x <= 650 && this->_event.button.y >= 300 && this->_event.button.y <= 370)
	    {
	      this->_selected = &this->_ip;
	      this->_ip.setSelected(true);
	      this->_port.setSelected(false);
	    }
	  else if (this->_event.button.x >= 850 && this->_event.button.x <= 1250 && this->_event.button.y >= 300 && this->_event.button.y <= 370)
	    {
	      this->_selected = &this->_port;
	      this->_ip.setSelected(false);
	      this->_port.setSelected(true);
	    }
	  else
	    {
	      this->_selected = NULL;
	      this->_ip.setSelected(false);
	      this->_port.setSelected(false);
	    }
	  this->_refresh();
	}
    }
}