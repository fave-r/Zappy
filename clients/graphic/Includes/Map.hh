//
// Map.hh for Map in /home/lopez_t/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Tue Jun 09 19:21:19 2015 Thibaut Lopez
// Last update Wed Jul  1 18:28:44 2015 romaric
//

#ifndef	MAP_HH
#define	MAP_HH

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <utility>
#include "Content.hh"
#include "User.hpp"

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

  void		putUser(const int nb, const int x, const int y, const int dir, const int lev, const std::string &tn);
  void		setMap(const int x, const int y, const Type type, const int number);
  void		movUser(const int nb, const int x, const int y, const int dir);
  void    nplayerCast(const int tmp);

public:
  std::vector<std::vector <Content *> > getMap() const;
  std::list<std::pair<int, int>> _update;
  std::list<int> _play;
  User    _user;

  void    userUp(const int nb)
  {
    _play.push_back(nb);
  };
};

#endif
