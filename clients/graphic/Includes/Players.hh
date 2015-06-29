//
// Players.hh for zappy in /home/fave_r/rendu/Zappy/clients/graphic
//
// Made by romaric
// Login   <fave_r@epitech.net>
//
// Started on  Mon Jun 29 12:15:40 2015 romaric
// Last update Mon Jun 29 12:23:14 2015 romaric
//

#ifndef	PLAYERS_HH
#define	PLAYERS_HH

#include <iostream>
#include <string>

class	Players
{
private:
  int	_nb;
  int   _food;
  int   _linemate;
  int   _deraumere;
  int   _sibur;
  int   _mendiane;
  int   _phiras;
  int   _thystame;

public:
  Players(const int nb);
  ~Players();
};

#endif
