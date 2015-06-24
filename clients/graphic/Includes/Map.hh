//
// Map.hh for Map in /home/lopez_t/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Tue Jun 09 19:21:19 2015 Thibaut Lopez
// Last update Wed Jun 24 16:29:26 2015 Leo Thevenet
//

#ifndef	MAP_HH
#define	MAP_HH

#include <iostream>
#include <string>
#include <vector>
#include "Content.hh"

enum Type
  {
    FOOD,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME
  };

class	Map
{
private:
  size_t	_length;
  size_t	_width;
  std::vector<std::vector <Content *> > _map;

public:
  Map();
  ~Map();

public:
  void		handleKeys();
  void		setLength(const size_t val);
  void		setWidth(const size_t val);
  void		init();
public:
  size_t	getLength();
  size_t	getWidth();

  void		setMap(const int x, const int y, const Type type, const int number);
  std::vector<std::vector <Content *> > getMap() const; 
};

#endif
