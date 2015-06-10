//
// Map.hh for Map in /home/lopez_t/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Tue Jun 09 19:21:19 2015 Thibaut Lopez
// Last update Wed Jun 10 15:54:00 2015 Thibaut Lopez
//

#ifndef	MAP_HH
#define	MAP_HH

#include <iostream>
#include <string>

class	Map
{
private:
  size_t	_length;
  size_t	_width;

public:
  Map();
  virtual ~Map();
  void	handleKeys();
};

#endif
