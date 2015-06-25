//
// ScreenTitle.hh for ScreenTitle in /home/lopez_t/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Mon Jun 22 12:17:03 2015 Thibaut Lopez
// Last update Thu Jun 25 18:09:37 2015 Thibaut Lopez
//

#ifndef	SCREENTITLE_HH
#define	SCREENTITLE_HH
#define	TITLE_BUTTON	"Ressources/images/Title.png"
#define	TITLE_BUTTON_MO	"Ressources/images/Title.png"
#define	START_BUTTON	"Ressources/images/Start.png"
#define	START_BUTTON_MO	"Ressources/images/StartMouseOn.png"
#define	OPTI_BUTTON	"Ressources/images/Option.png"
#define	OPTI_BUTTON_MO	"Ressources/images/OptionMouseOn.png"
#define	QUIT_BUTTON	"Ressources/images/Quit.png"
#define	QUIT_BUTTON_MO	"Ressources/images/QuitMouseOn.png"

#include "IRefreshable.hh"
#include "Input.hpp"
#include "Button.hh"
#include "Graphic.hh"

class		ScreenTitle : public IRefreshable
{
private:
  typedef	Ret	(ScreenTitle::*ptr)(std::pair<std::string, std::string> &);
  Button	*_title;
  Input		*_ip;
  Input		*_port;
  Input		*_selected;
  Button	*_start;
  Button	*_option;
  Button	*_quit;
  SDL_Event	_event;
  std::map<Uint32, ptr>	_eventType;
  std::map<Uint32, ptr>	_eventKU;
  Ret		_etQuit(std::pair<std::string, std::string> &);
  Ret		_etKURight(std::pair<std::string, std::string> &);
  Ret		_etKULeft(std::pair<std::string, std::string> &);
  Ret		_etKUBackspace(std::pair<std::string, std::string> &);
  Ret		_etKUDelete(std::pair<std::string, std::string> &);
  Ret		_etKUEnter(std::pair<std::string, std::string> &);
  Ret		_etKeyUp(std::pair<std::string, std::string> &);
  Ret		_etTextInput(std::pair<std::string, std::string> &);
  Ret		_etMouseButtonDown(std::pair<std::string, std::string> &);
  Ret		_etMouseMotion(std::pair<std::string, std::string> &);

public:
  explicit ScreenTitle(SDL_Renderer *);
  virtual ~ScreenTitle();
  virtual void	refresh(SDL_Renderer *);
  virtual Ret	handleKeys(SDL_Event &, Map &, std::pair<std::string, std::string> &);
};

#endif
