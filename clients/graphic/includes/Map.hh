//
// Map.hh for Map in /home/lopez_t/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Tue Jun 09 19:21:19 2015 Thibaut Lopez
// Last update Fri Jun 19 18:01:24 2015 romaric
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
  ~Map();
  void		handleKeys();
  void		setLength(const size_t val);
  void		setWidth(const size_t val);
};

#endif
