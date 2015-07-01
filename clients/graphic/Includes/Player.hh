//
// Player.hh for zappy in /home/fave_r/rendu/Zappy/clients/graphic
//
// Made by romaric
// Login   <fave_r@epitech.net>
//
// Started on  Mon Jun 29 12:15:40 2015 romaric
// Last update Wed Jul  1 10:44:38 2015 romaric
//

#ifndef	PLAYER_HH
#define	PLAYER_HH

#include <iostream>
#include <string>

class	Player
{
private:
  int	      _nb;
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

public:
  int	getNb(void) const
  {
    return _nb;
  };

  int	getX(void) const
  {
    return _x;
  };

  int	getY(void) const
  {
    return _y;
  };

  int	getDir(void) const
  {
    return _dir;
  };

  int	getLevel(void) const
  {
    return _level;
  };

  std::string	getTn(void) const
  {
    return _tn;
  };

  int	getFood(void) const
  {
    return _food;
  }

  int	getLinemate(void) const
  {
    return _linemate;
  };

  int	getDeraumere(void) const
  {
    return _deraumere;
  };

  int	getSibur(void) const
  {
    return _sibur;
  };

  int	getMendiane(void) const
  {
    return _mendiane;
  };

  int	getPhiras(void) const
  {
    return _phiras;
  };

  int	getThystame(void) const
  {
    return _thystame;
  };
};

#endif
