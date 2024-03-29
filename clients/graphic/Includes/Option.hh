//
// Option.hh for Option in /home/lopez_t/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Mon Jun 22 12:20:56 2015 Thibaut Lopez
// Last update Fri Jul  3 04:03:59 2015 Thibaut Lopez
//

#ifndef	OPTION_HH
#define	OPTION_HH
#define	OPTION_TTF	"Ressources/font/batmfa__.ttf"
#define	TEST_SOUND	"Ressources/OST/DeathSound.mp3"
#define	TS_DELAY	1000000

#include "IRefreshable.hh"
#include "SlideBar.hh"
#include "RadioBox.hh"
#include "Music.hh"
#include "Timeval.hh"
#include "TextBox.hh"
#include <list>
#include <map>

class		Option : public IRefreshable
{
private:
  typedef	Ret	(Option::*ptr)(std::pair<std::string, std::string> &);
  SlideBar	*_bgmVol;
  SlideBar	*_seVol;
  SDL_Color	_color;
  TTF_Font	*_font;
  std::list<TextBox *>	_texts;
  std::vector<RadioBox *>	_rbs;
  SDL_Event	_event;
  bool		_testSe;
  bool		_sPausedBGM;
  bool		_sPausedSe;
  Timeval	_repeat;
  std::map<Uint32, ptr>	_eventType;
  std::map<Uint32, ptr>	_eventKU;
  Ret		_etQuit(std::pair<std::string, std::string> &);
  Ret		_etKUEnter(std::pair<std::string, std::string> &);
  Ret		_etKeyUp(std::pair<std::string, std::string> &);
  Ret		_etTextInput(std::pair<std::string, std::string> &);
  Ret		_etMouseButtonUp(std::pair<std::string, std::string> &);
  Ret		_etMouseButtonDown(std::pair<std::string, std::string> &);
  Ret		_etMouseMotion(std::pair<std::string, std::string> &);

public:
  explicit Option(SDL_Renderer *);
  virtual ~Option();
  virtual void	refresh(SDL_Renderer *);
  virtual Ret	handleKeys(SDL_Event &, Map &, std::pair<std::string, std::string> &);
};

#endif
