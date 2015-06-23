//
// Option.hh for Option in /home/lopez_t/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Mon Jun 22 12:20:56 2015 Thibaut Lopez
// Last update Tue Jun 23 15:24:04 2015 Thibaut Lopez
//

#ifndef	OPTION_HH
#define	OPTION_HH
#define	TEST_SOUND	"tools/OST/DeathSound.mp3"
#define	TS_DELAY	1000000

#include "IRefreshable.hh"
#include "SlideBar.hh"
#include "Music.hh"
#include "Timeval.hh"
#include <map>

class		Option : public IRefreshable
{
private:
  typedef	Ret	(Option::*ptr)(std::pair<std::string, std::string> &);
  SlideBar	*_bgmVol;
  SlideBar	*_seVol;
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
