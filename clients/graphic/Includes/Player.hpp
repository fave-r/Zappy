//
// Player.hh for zappy in /home/fave_r/rendu/Zappy/clients/graphic
//
// Made by romaric
// Login   <fave_r@epitech.net>
//
// Started on  Mon Jun 29 12:15:40 2015 romaric
// Last update Thu Jul  2 10:17:44 2015 romaric
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
  int	      _x1;
  int	      _y1;
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

  int	getX1(void) const
  {
    return _x1;
  };

  int	getY1(void) const
  {
    return _y1;
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

  void	setX(const int x)
  {
    _x = x;
  };

  void	setY(const int y)
  {
    _y = y;
  };

  void	setX1(const int x1)
  {
    _x1 = x1;
  };

  void	setY1(const int y1)
  {
    _y1 = y1;
  };


  void	setDir(const int dir)
  {
    _dir = dir;
  };

  void	setLevel(const int lvl)
  {
    _level = lvl;
  };

  void	setFood(const int fd)
  {
    _food = fd;
  }

  void	setLinemate(const int line)
  {
    _linemate = line;
  };

  void	setDeraumere(const int dera)
  {
    _deraumere = dera;
  };

  void	setSibur(const int sib)
  {
    _sibur = sib;
  };

  void	setMendiane(const int mend)
  {
    _mendiane = mend;
  };

  void	setPhiras(const int phi)
  {
    _phiras = phi;
  };

  void	setThystame(const int thy)
  {
    _thystame = thy;
  };
};

#endif
