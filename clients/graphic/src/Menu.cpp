//
// Menu.cpp for Menu in /home/lopez_t/Zappy
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Wed Jun 10 18:13:06 2015 Thibaut Lopez
// Last update Wed Jun 17 11:52:45 2015 Thibaut Lopez
//

#include "Menu.hh"

Menu::Menu()
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
  if (this->_bg == NULL)
    throw std::runtime_error("SDL_CreateTextureFromSurface.");
  this->_ip = new Input(false, 250, 350);
  this->_ip->init(400, 70, "IP", this->_ren);
  this->_port = new Input(false, 850, 350);
  this->_port->init(400, 70, "Port", this->_ren);
  this->_selected = this->_ip;
  this->_ok = new Button(550, 600);
  this->_ok->load(this->_ren, MAIN_BUTTON);
  this->_refresh();
}

Menu::~Menu()
{
  delete this->_ip;
  delete this->_port;
  delete this->_ok;
  SDL_DestroyTexture(this->_bg);
  SDL_DestroyRenderer(this->_ren);
  SDL_DestroyWindow(this->_screen);
  TTF_Quit();
  SDL_Quit();
}

void					Menu::_refresh()
{
  SDL_RenderClear(this->_ren);
  SDL_RenderCopy(this->_ren, this->_bg, NULL, NULL);
  this->_ip->refresh(this->_ren);
  this->_port->refresh(this->_ren);
  this->_ok->refresh(this->_ren);
  SDL_RenderPresent(this->_ren);
}

std::pair<std::string, std::string>	Menu::run(Map &map)
{
  std::pair<std::string, std::string>	ret;
  bool					loop;

  (void)map;
  ret.first = "";
  ret.second = "";
  SDL_StartTextInput();
  loop = true;
  while (loop)
    {
      while (SDL_PollEvent(&this->_event))
	{
	  if (this->_event.type == SDL_QUIT || this->_event.key.keysym.sym == SDLK_ESCAPE)
	    loop = false;
	  if (this->_selected != NULL && this->_event.type == SDL_KEYUP)
	    {
	      if (this->_event.key.keysym.sym == SDLK_RIGHT)
		this->_selected->curRight();
	      else if (this->_event.key.keysym.sym == SDLK_LEFT)
		this->_selected->curLeft();
	      else if (this->_event.key.keysym.sym == SDLK_BACKSPACE)
		this->_selected->deleteChar();
	      else if (this->_event.key.keysym.sym == SDLK_DELETE)
		this->_selected->supprChar();
	      else if (this->_event.key.keysym.sym == SDLK_RETURN || this->_event.key.keysym.sym == SDLK_KP_ENTER)
		{
		  ret.first = this->_ip->getInput();
		  ret.second = this->_port->getInput();
		  loop = false;
		}
	    }
	  else if (this->_selected != NULL && this->_event.type == SDL_TEXTINPUT)
	    this->_selected->addChar(this->_event.text.text, this->_ren);
	  else if (this->_event.type == SDL_MOUSEBUTTONDOWN && this->_event.button.button == SDL_BUTTON_LEFT)
	    {
	      if (this->_ip->isClicked(this->_event.button.x, this->_event.button.y))
		{
		  this->_selected = this->_ip;
		  this->_ip->setSelected(true);
		  this->_port->setSelected(false);
		}
	      else if (this->_port->isClicked(this->_event.button.x, this->_event.button.y))
		{
		  this->_selected = this->_port;
		  this->_ip->setSelected(false);
		  this->_port->setSelected(true);
		}
	      else if (this->_ok->isClicked(this->_event.button.x, this->_event.button.y))
		{
		  ret.first = this->_ip->getInput();
		  ret.second = this->_port->getInput();
		  loop = false;
		}
	      else
		{
		  this->_selected = NULL;
		  this->_ip->setSelected(false);
		  this->_port->setSelected(false);
		}
	    }
	}
      this->_refresh();
    }
  SDL_StopTextInput();
  return (ret);
}
