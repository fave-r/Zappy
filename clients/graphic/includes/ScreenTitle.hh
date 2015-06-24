//
// ScreenTitle.hh for ScreenTitle in /home/lopez_t/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Mon Jun 22 12:17:03 2015 Thibaut Lopez
// Last update Wed Jun 24 03:19:36 2015 jean_c
//

#ifndef	SCREENTITLE_HH
#define	SCREENTITLE_HH
#define	START_BUTTON	"tools/images/Start.png"
#define	START_BUTTON_MO	"tools/images/StartMouseOn.png"
#define	OPTI_BUTTON	"tools/images/Option.png"
#define	OPTI_BUTTON_MO	"tools/images/OptionMouseOn.png"
#define	QUIT_BUTTON	"tools/images/Quit.png"
#define	QUIT_BUTTON_MO	"tools/images/QuitMouseOn.png"

#include "IRefreshable.hh"
#include "Input.hpp"
#include "Button.hh"

class		ScreenTitle : public IRefreshable
{
private:
  typedef	Ret	(ScreenTitle::*ptr)(std::pair<std::string, std::string> &);
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
