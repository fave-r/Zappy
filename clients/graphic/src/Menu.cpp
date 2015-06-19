//
// Menu.cpp for Menu in /home/lopez_t/Zappy
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Wed Jun 10 18:13:06 2015 Thibaut Lopez
// Last update Fri Jun 19 18:52:28 2015 Thibaut Lopez
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
  this->_ip = new Input(false, 250, 350);
  this->_ip->init(400, 70, "IP", this->_ren);
  this->_port = new Input(false, 850, 350);
  this->_port->init(400, 70, "Port", this->_ren);
  this->_selected = NULL;
  this->_start = new Button(550, 550);
  this->_start->load(this->_ren, START_BUTTON, START_BUTTON_MO);
  this->_option = new Button(550, 660);
  this->_option->load(this->_ren, OPTI_BUTTON, OPTI_BUTTON_MO);
  this->_quit = new Button(550, 770);
  this->_quit->load(this->_ren, QUIT_BUTTON, QUIT_BUTTON_MO);
  music = Music::newinstance();
  music->createSound(MAIN_BGM, "title");
  music->playSound("title", true);
  this->_eventType[SDL_QUIT] = &Menu::_etQuit;
  this->_eventType[SDL_KEYUP] = &Menu::_etKeyUp;
  this->_eventType[SDL_TEXTINPUT] = &Menu::_etTextInput;
  this->_eventType[SDL_MOUSEBUTTONDOWN] = &Menu::_etMouseButtonDown;
  this->_eventType[SDL_MOUSEMOTION] = &Menu::_etMouseMotion;
  this->_eventKU[SDLK_ESCAPE] = &Menu::_etQuit;
  this->_eventKU[SDLK_RIGHT] = &Menu::_etKURight;
  this->_eventKU[SDLK_LEFT] = &Menu::_etKULeft;
  this->_eventKU[SDLK_BACKSPACE] = &Menu::_etKUBackspace;
  this->_eventKU[SDLK_DELETE] = &Menu::_etKUDelete;
  this->_eventKU[SDLK_RETURN] = &Menu::_etKUEnter;
  this->_eventKU[SDLK_KP_ENTER] = &Menu::_etKUEnter;
  this->_refresh();
}

Menu::~Menu()
{
  Music		*music;

  delete this->_ip;
  delete this->_port;
  delete this->_start;
  delete this->_option;
  delete this->_quit;
  SDL_DestroyTexture(this->_bg);
  SDL_DestroyRenderer(this->_ren);
  SDL_DestroyWindow(this->_screen);
  TTF_Quit();
  SDL_Quit();
  music = Music::newinstance();
  delete music;
}

void	Menu::_etQuit(bool &loop, std::pair<std::string, std::string> &ret)
{
  (void)loop;
  (void)ret;
  throw std::exception();
}

void	Menu::_etKURight(bool &loop, std::pair<std::string, std::string> &ret)
{
  (void)loop;
  (void)ret;
  if (this->_selected != NULL)
    this->_selected->curRight();
}

void	Menu::_etKULeft(bool &loop, std::pair<std::string, std::string> &ret)
{
  (void)loop;
  (void)ret;
  if (this->_selected != NULL)
    this->_selected->curLeft();
}

void	Menu::_etKUBackspace(bool &loop, std::pair<std::string, std::string> &ret)
{
  (void)loop;
  (void)ret;
  if (this->_selected != NULL)
    this->_selected->deleteChar();
}

void	Menu::_etKUDelete(bool &loop, std::pair<std::string, std::string> &ret)
{
  (void)loop;
  (void)ret;
  if (this->_selected != NULL)
    this->_selected->supprChar();
}

void	Menu::_etKUEnter(bool &loop, std::pair<std::string, std::string> &ret)
{
  (void)loop;
  (void)ret;
  ret.first = this->_ip->getInput();
  ret.second = this->_port->getInput();
  loop = false;
}

void	Menu::_etKeyUp(bool &loop, std::pair<std::string, std::string> &ret)
{
  try
    {
      (this->*(this->_eventKU.at(this->_event.key.keysym.sym)))(loop, ret);
    }
  catch (std::out_of_range &err)
    {
    }
}

void	Menu::_etTextInput(bool &loop, std::pair<std::string, std::string> &ret)
{
  (void)loop;
  (void)ret;
  if (this->_selected == NULL)
    {
      if (this->_event.text.text[0] == '+')
	*(Music::newinstance()) += 0.01f;
      else if (this->_event.text.text[0] == '-')
	*(Music::newinstance()) -= 0.01f;
    }
  else 
    this->_selected->addChar(this->_event.text.text, this->_ren);
}

void	Menu::_etMouseButtonDown(bool &loop, std::pair<std::string, std::string> &ret)
{
  if (this->_event.button.button == SDL_BUTTON_LEFT)
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
      else if (this->_start->isClicked(this->_event.button.x, this->_event.button.y))
	{
	  ret.first = this->_ip->getInput();
	  ret.second = this->_port->getInput();
	  loop = false;
	}
      else if (this->_quit->isClicked(this->_event.button.x, this->_event.button.y))
	throw std::exception();
      else
	{
	  this->_selected = NULL;
	  this->_ip->setSelected(false);
	  this->_port->setSelected(false);
	}
    }
}

void	Menu::_etMouseMotion(bool &loop, std::pair<std::string, std::string> &ret)
{
  (void)loop;
  (void)ret;
  this->_start->isMouseOn(this->_event.motion.x, this->_event.motion.y);
  this->_option->isMouseOn(this->_event.motion.x, this->_event.motion.y);
  this->_quit->isMouseOn(this->_event.motion.x, this->_event.motion.y);
}

void	Menu::_refresh()
{
  SDL_RenderClear(this->_ren);
  SDL_RenderCopy(this->_ren, this->_bg, NULL, NULL);
  this->_ip->refresh(this->_ren);
  this->_port->refresh(this->_ren);
  this->_start->refresh(this->_ren);
  this->_option->refresh(this->_ren);
  this->_quit->refresh(this->_ren);
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
	  try
	    {
	      (this->*(this->_eventType.at(this->_event.type)))(loop, ret);
	    }
	  catch (std::out_of_range &err)
	    {
	    }
	}
      this->_refresh();
    }
  SDL_StopTextInput();
  return (ret);
}
