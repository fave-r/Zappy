//
// Music.cpp for Music in /home/lopez_t/Zappy/clients/graphic
// 
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
// 
// Started on  Thu Jun 18 13:09:15 2015 Thibaut Lopez
// Last update Thu Jun 18 17:16:21 2015 Thibaut Lopez
//

#include "Music.hh"

Music::Music()
{
  if (FMOD::System_Create(&(this->_sys)) != FMOD_OK)
    return;
  int driverCount = 0;
  this->_sys->getNumDrivers(&driverCount);
  if (driverCount == 0)
    throw std::runtime_error("Can't launch music");
  this->_sys->init(42, FMOD_INIT_NORMAL, NULL);
}

Music::~Music()
{
  std::map<std::string, std::pair<FMOD::Sound*, bool>>::iterator it;
  for (it = this->_sons.begin(); it != this->_sons.end(); ++it)
    (*it).second.first->release();
}

void		Music::createSound(const char* pFile, const char* id, bool type)
{
  FMOD::Sound	*son;

  if (this->_sys->createSound(pFile, FMOD_DEFAULT, 0, &son) != FMOD_OK)
    throw std::runtime_error("Can't create the music");
  this->_sons[id].first = son;
  this->_sons[id].second = type;
}

void		Music::playSound(const char* id, bool bLoop)
{
  if (!bLoop)
    this->_sons[id].first->setMode(FMOD_LOOP_OFF);
  else
    {
      this->_sons[id].first->setMode(FMOD_LOOP_NORMAL);
      this->_sons[id].first->setLoopCount(-1);
    }
  if (this->_sys->playSound(this->_sons[id].first, (this->_sons[id].second) ? this->_bgm : this->_se, false, 0) != FMOD_OK)
    throw std::runtime_error("Can't play the music");
}

void		Music::changeVolume(bool type, float to_add)
{
  FMOD::ChannelGroup	*chan;
  float			vol;

  chan = (type) ? this->_bgm : this->_se;
  chan->setPaused(false);
  chan->getVolume(&vol);
  chan->setVolume(vol + to_add);
  chan->setPaused(true);
}
