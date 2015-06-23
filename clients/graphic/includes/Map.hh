//
// Map.hh for Map in /home/lopez_t/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Tue Jun 09 19:21:19 2015 Thibaut Lopez
// Last update Mon Jun 22 16:14:42 2015 jean_c
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

public:
  void		handleKeys();
  void		setLength(const size_t val);
  void		setWidth(const size_t val);

public:
  size_t	getLength();
  size_t	getWidth();

};

#endif
