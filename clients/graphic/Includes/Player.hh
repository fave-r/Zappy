//
// Player.hh for zappy in /home/fave_r/rendu/Zappy/clients/graphic
//
// Made by romaric
// Login   <fave_r@epitech.net>
//
// Started on  Mon Jun 29 12:15:40 2015 romaric
// Last update Mon Jun 29 12:52:57 2015 romaric
//

#ifndef	PLAYER_HH
#define	PLAYER_HH

#include <iostream>
#include <string>

class	Player
{
private:
  int	        _nb;
  int         _x;
  int         _y;
  int         _dir;
  int         _level;
  std::string _tn;
  int         _food;
  int         _linemate;
  int         _deraumere;
  int         _sibur;
  int         _mendiane;
  int         _phiras;
  int         _thystame;

public:
  Player(const int nb, const int x, const int y, const int dir, const int lev, const std::string &tn);
  ~Player();
};

#endif
