//
// ScreenTitle.cpp for ScreenTitle in /home/lopez_t/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Mon Jun 22 12:17:03 2015 Thibaut Lopez
// Last update Wed Jun 24 09:31:38 2015 jean_c
//

#include "ScreenTitle.hh"

ScreenTitle::ScreenTitle(SDL_Renderer *ren)
  : IRefreshable()
{
  this->_ip = new Input(false, 250, 350);
  this->_ip->init(400, 70, "IP", ren);
  this->_port = new Input(false, 850, 350);
  this->_port->init(400, 70, "Port", ren);
  this->_selected = NULL;
  this->_start = new Button(550, 550);
  this->_start->load(ren, START_BUTTON, START_BUTTON_MO);
  this->_option = new Button(550, 660);
  this->_option->load(ren, OPTI_BUTTON, OPTI_BUTTON_MO);
  this->_quit = new Button(550, 770);
  this->_quit->load(ren, QUIT_BUTTON, QUIT_BUTTON_MO);
  this->_eventType[SDL_QUIT] = &ScreenTitle::_etQuit;
  this->_eventType[SDL_KEYUP] = &ScreenTitle::_etKeyUp;
  this->_eventType[SDL_TEXTINPUT] = &ScreenTitle::_etTextInput;
  this->_eventType[SDL_MOUSEBUTTONDOWN] = &ScreenTitle::_etMouseButtonDown;
  this->_eventType[SDL_MOUSEMOTION] = &ScreenTitle::_etMouseMotion;
  this->_eventKU[SDLK_ESCAPE] = &ScreenTitle::_etQuit;
  this->_eventKU[SDLK_RIGHT] = &ScreenTitle::_etKURight;
  this->_eventKU[SDLK_LEFT] = &ScreenTitle::_etKULeft;
  this->_eventKU[SDLK_BACKSPACE] = &ScreenTitle::_etKUBackspace;
  this->_eventKU[SDLK_DELETE] = &ScreenTitle::_etKUDelete;
  this->_eventKU[SDLK_RETURN] = &ScreenTitle::_etKUEnter;
  this->_eventKU[SDLK_KP_ENTER] = &ScreenTitle::_etKUEnter;
}

ScreenTitle::~ScreenTitle()
{
  delete this->_ip;
  delete this->_port;
  delete this->_start;
  delete this->_option;
  delete this->_quit;
}

Ret	ScreenTitle::_etQuit(std::pair<std::string, std::string> &ret)
{
  (void)ret;
  throw std::exception();
}

Ret	ScreenTitle::_etKURight(std::pair<std::string, std::string> &ret)
{
  (void)ret;
  if (this->_selected != NULL)
    this->_selected->curRight();
  return (NOTHING);
}

Ret	ScreenTitle::_etKULeft(std::pair<std::string, std::string> &ret)
{
  (void)ret;
  if (this->_selected != NULL)
    this->_selected->curLeft();
  return (NOTHING);
}

Ret	ScreenTitle::_etKUBackspace(std::pair<std::string, std::string> &ret)
{
  (void)ret;
  if (this->_selected != NULL)
    this->_selected->deleteChar();
  return (NOTHING);
}

Ret	ScreenTitle::_etKUDelete(std::pair<std::string, std::string> &ret)
{
  (void)ret;
  if (this->_selected != NULL)
    this->_selected->supprChar();
  return (NOTHING);
}

Ret	ScreenTitle::_etKUEnter(std::pair<std::string, std::string> &ret)
{
  ret.first = this->_ip->getInput();
  ret.second = this->_port->getInput();
  return (RETURN);
}

Ret	ScreenTitle::_etKeyUp(std::pair<std::string, std::string> &ret)
{
  Ret	eventRet;

  eventRet = NOTHING;
  try
    {
      eventRet = (this->*(this->_eventKU.at(this->_event.key.keysym.sym)))(ret);
    }
  catch (std::out_of_range &err)
    {
    }
  return (eventRet);
}

Ret	ScreenTitle::_etTextInput(std::pair<std::string, std::string> &ret)
{
  Music	*music;

  (void)ret;
  if (this->_selected == NULL)
    {
      music = Music::newinstance();
      if (this->_event.text.text[0] == '+')
	*music += 0.01f;
      else if (this->_event.text.text[0] == '-')
	*music -= 0.01f;
      else if (this->_event.text.text[0] == 'p')
	{
	  music->setPaused(true, !music->getPaused(true));
	  music->setPaused(false, !music->getPaused(false));
	}
    }
  else
    this->_selected->addChar(this->_event.text.text);
  return (NOTHING);
}

Ret	ScreenTitle::_etMouseButtonDown(std::pair<std::string, std::string> &ret)
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
      else
	{
	  this->_selected = NULL;
	  this->_ip->setSelected(false);
	  this->_port->setSelected(false);
	  if (this->_start->isClicked(this->_event.button.x, this->_event.button.y))
	    {
	      ret.first = this->_ip->getInput();
	      ret.second = this->_port->getInput();
	      return (RETURN);
	    }
	  else if (this->_option->isClicked(this->_event.button.x, this->_event.button.y))
	    return (CHANGE);
	  else if (this->_quit->isClicked(this->_event.button.x, this->_event.button.y))
	    throw std::exception();
	}
    }
  return (NOTHING);
}

Ret	ScreenTitle::_etMouseMotion(std::pair<std::string, std::string> &ret)
{
  (void)ret;
  this->_start->isMouseOn(this->_event.motion.x, this->_event.motion.y);
  this->_option->isMouseOn(this->_event.motion.x, this->_event.motion.y);
  this->_quit->isMouseOn(this->_event.motion.x, this->_event.motion.y);
  return (NOTHING);
}

void	ScreenTitle::refresh(SDL_Renderer *ren)
{
  this->_ip->refresh(ren);
  this->_port->refresh(ren);
  this->_start->refresh(ren);
  this->_option->refresh(ren);
  this->_quit->refresh(ren);
}

Ret	ScreenTitle::handleKeys(SDL_Event &event, Map &map, std::pair<std::string, std::string> &ret)
{
  Ret	eventRet;

  (void)map;
  eventRet = NOTHING;
  this->_event = event;
  try
    {
      eventRet = (this->*(this->_eventType.at(this->_event.type)))(ret);
    }
  catch (std::out_of_range &err)
    {
    }
  return (eventRet);
}
