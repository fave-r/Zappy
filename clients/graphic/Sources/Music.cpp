//
// Music.cpp for Music in /home/lopez_t/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Thu Jun 18 13:09:15 2015 Thibaut Lopez
// Last update Tue Jun 23 14:43:11 2015 Thibaut Lopez
//

#include "Music.hh"

Music * Music::_music  = NULL;

Music::Music()
{
  if (FMOD::System_Create(&(this->_sys)) != FMOD_OK)
    return;
  int driverCount = 0;
  this->_sys->getNumDrivers(&driverCount);
  if (driverCount == 0)
    throw std::runtime_error("Can't launch music");
  this->_sys->init(42, FMOD_INIT_NORMAL, NULL);
  if (this->_sys->createChannelGroup(NULL, &this->_bgm) != FMOD_OK || this->_sys->createChannelGroup(NULL, &this->_se) != FMOD_OK)
    throw std::runtime_error("Can't create channels");
  this->_bgmVol = 1.0f;
  this->_seVol = 1.0f;
}

Music::~Music()
{
  std::map<std::string, std::pair<FMOD::Sound*, bool>>::iterator it;
  for (it = this->_sons.begin(); it != this->_sons.end(); ++it)
    (*it).second.first->release();
}

Music * Music::newinstance()
{
  if (_music == NULL)
    _music = new Music;
  return _music;
}

float		Music::getVol(bool type) const
{
  return ((type) ? this->_bgmVol : this->_seVol);
}

bool		Music::getPaused(bool type) const
{
  bool			pause;
  FMOD::ChannelGroup	*chan;

  chan = (type) ? this->_bgm : this->_se;
  chan->getPaused(&pause);
  return (pause);
}

void		Music::setPaused(bool type, bool pause)
{
  FMOD::ChannelGroup	*chan;

  chan = (type) ? this->_bgm : this->_se;
  chan->setPaused(pause);
}

void		Music::createSound(const char* pFile, const char* id, bool type)
{
  FMOD::Sound	*son;

  try
    {
      this->_sons.at(id);
    }
  catch (std::out_of_range &err)
    {
      if (type)
	{
	  if (this->_sys->createStream(pFile, FMOD_DEFAULT, 0, &son) != FMOD_OK)
	    throw std::runtime_error("Can't create the music");
	}
      else
	if (this->_sys->createSound(pFile, FMOD_DEFAULT, 0, &son) != FMOD_OK)
	  throw std::runtime_error("Can't create the music");
      this->_sons[id].first = son;
      this->_sons[id].second = type;
    }
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
  this->changeVolume(this->_sons[id].second, (this->_sons[id].second) ? this->_bgmVol : this->_seVol);
}

void		Music::changeVolume(bool type, float val)
{
  FMOD::ChannelGroup	*chan;
  float		*vol;

  chan = (type) ? this->_bgm : this->_se;
  vol = (type) ? &this->_bgmVol : &this->_seVol;
  chan->getVolume(vol);
  *vol = val;
  if (*vol < 0.0f)
    *vol = 0.0f;
  else if (*vol >= 1.0f)
    *vol = 1.0f;
  chan->setVolume(*vol);
  this->_sys->update();
}

Music		&Music::operator+=(float to_add)
{
  this->changeVolume(true, this->getVol() + to_add);
  this->changeVolume(false, this->getVol(false) + to_add);
  return (*this);
}

Music		&Music::operator-=(float to_sub)
{
  this->changeVolume(true, this->getVol() - to_sub);
  this->changeVolume(false, this->getVol(false) - to_sub);
  return (*this);
}
