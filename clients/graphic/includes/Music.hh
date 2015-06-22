//
// Music.hh for Music in /home/lopez_t/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Thu Jun 18 13:09:21 2015 Thibaut Lopez
// Last update Mon Jun 22 16:37:30 2015 Thibaut Lopez
//

#ifndef __MUSIC_HH__
#define __MUSIC_HH__

#include <map>
#include <stdlib.h>
#include <iostream>
#include <stdexcept>
#include "fmod.hpp"

class Music
{
  static Music		*_music;
  FMOD::System		*_sys;
  FMOD::ChannelGroup	*_bgm;
  float			_bgmVol;
  FMOD::ChannelGroup	*_se;
  float			_seVol;
  std::map<std::string, std::pair<FMOD::Sound*, bool>>	_sons;
public:
  Music();
  ~Music();

public:
  static Music		*newinstance();
  float			getVol(bool = true) const;
  void			createSound(const char*, const char*, bool = true);
  void			playSound(const char*, bool = false);
  void			changeVolume(bool, float);
  Music			&operator+=(float);
  Music			&operator-=(float);
};

#endif
