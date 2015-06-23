//
// Option.cpp for Option in /home/lopez_t/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Mon Jun 22 12:20:56 2015 Thibaut Lopez
// Last update Tue Jun 23 15:32:35 2015 Thibaut Lopez
//

#include "Option.hh"

Option::Option(SDL_Renderer *ren)
  : IRefreshable()
{
  Music	*music;

  this->_bgmVol = new SlideBar(100, 100);
  this->_bgmVol->init(500, ren);
  this->_seVol = new SlideBar(100, 200);
  this->_seVol->init(500, ren);
  this->_eventType[SDL_QUIT] = &Option::_etQuit;
  this->_eventType[SDL_KEYUP] = &Option::_etKeyUp;
  this->_eventType[SDL_TEXTINPUT] = &Option::_etTextInput;
  this->_eventType[SDL_MOUSEBUTTONUP] = &Option::_etMouseButtonUp;
  this->_eventType[SDL_MOUSEBUTTONDOWN] = &Option::_etMouseButtonDown;
  this->_eventType[SDL_MOUSEMOTION] = &Option::_etMouseMotion;
  this->_eventKU[SDLK_ESCAPE] = &Option::_etQuit;
  this->_eventKU[SDLK_RETURN] = &Option::_etKUEnter;
  this->_eventKU[SDLK_KP_ENTER] = &Option::_etKUEnter;
  music = Music::newinstance();
  music->createSound(TEST_SOUND, "test", false);
  this->_testSe = false;
  this->_sPausedBGM = music->getPaused(true);
  this->_sPausedSe = music->getPaused(false);
}

Option::~Option()
{
  delete this->_bgmVol;
  delete this->_seVol;
}

Ret	Option::_etQuit(std::pair<std::string, std::string> &ret)
{
  (void)ret;
  throw std::exception();
}

Ret	Option::_etKUEnter(std::pair<std::string, std::string> &ret)
{
  (void)ret;
  return (CHANGE);
}

Ret	Option::_etKeyUp(std::pair<std::string, std::string> &ret)
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

Ret	Option::_etTextInput(std::pair<std::string, std::string> &ret)
{
  Music	*music;

  (void)ret;
  music = Music::newinstance();
  if (this->_event.text.text[0] == '+')
    *music += 0.01f;
  else if (this->_event.text.text[0] == '-')
    *music -= 0.01f;
  else if (!this->_testSe && this->_event.text.text[0] == 'p')
    {
      music->setPaused(true, !music->getPaused(true));
      music->setPaused(false, !music->getPaused(false));
    }
  return (NOTHING);
}

Ret	Option::_etMouseButtonUp(std::pair<std::string, std::string> &ret)
{
  Music	*music;

  (void)ret;
  if (this->_event.button.button == SDL_BUTTON_LEFT)
    {
      this->_bgmVol->isSelected(false);
      this->_seVol->isSelected(false);
      if (this->_testSe)
	{
	  music = Music::newinstance();
	  this->_testSe = false;
	  this->_repeat = Timeval();
	  music->setPaused(true, this->_sPausedBGM);
	  music->setPaused(false, this->_sPausedSe);
	}
    }
  return (NOTHING);
}

Ret	Option::_etMouseButtonDown(std::pair<std::string, std::string> &ret)
{
  Music	*music;

  (void)ret;
  if (this->_event.button.button == SDL_BUTTON_LEFT)
    {
      if (this->_bgmVol->isClicked(this->_event.button.x, this->_event.button.y))
	this->_bgmVol->isSelected(true);
      else if (this->_seVol->isClicked(this->_event.button.x, this->_event.button.y))
	{
	  music = Music::newinstance();
	  this->_sPausedBGM = music->getPaused(true);
	  this->_sPausedSe = music->getPaused(false);
	  music->setPaused(true, true);
	  music->setPaused(false, false);
	  this->_seVol->isSelected(true);
	  this->_testSe = true;
	}
    }
  return (NOTHING);
}

Ret	Option::_etMouseMotion(std::pair<std::string, std::string> &ret)
{
  size_t	tmpBGM;
  size_t	tmpSe;
  float		tmp;
  Music		*music;

  (void)ret;
  music = Music::newinstance();
  tmpBGM = this->_bgmVol->getPercent();
  tmpSe = this->_seVol->getPercent();
  this->_bgmVol->mouseMotion(this->_event.motion.x);
  this->_seVol->mouseMotion(this->_event.motion.x);
  if (tmpBGM != this->_bgmVol->getPercent())
    {
      tmp = this->_bgmVol->getPercent();
      tmp /= 100.0f;
      music->changeVolume(true, tmp);
    }
  else if (tmpSe != this->_seVol->getPercent())
    {
      tmp = this->_seVol->getPercent();
      tmp /= 100.0f;
      music->changeVolume(false, tmp);
    }
  return (NOTHING);
}

void	Option::refresh(SDL_Renderer *ren)
{
  Music	*music;

  music = Music::newinstance();
  this->_bgmVol->setPercent(music->getVol() * 100);
  this->_bgmVol->refresh(ren);
  this->_seVol->setPercent(music->getVol(false) * 100);
  this->_seVol->refresh(ren);
  if (this->_testSe && this->_repeat.cmp(Timeval()) <= 0)
    {
      music->playSound("test", false);
      this->_repeat = Timeval();
      this->_repeat += TS_DELAY;
    }
}

Ret	Option::handleKeys(SDL_Event &event, Map &map, std::pair<std::string, std::string> &ret)
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

