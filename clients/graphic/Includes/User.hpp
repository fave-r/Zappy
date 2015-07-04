//
// User.hh for zappy in /home/fave_r/rendu/Zappy/clients/graphic
//
// Made by romaric
// Login   <fave_r@epitech.net>
//
// Started on  Mon Jun 29 13:02:34 2015 romaric
// Last update Thu Jul  2 10:16:16 2015 romaric
//

#ifndef	USER_HH
#define	USER_HH

#include <iostream>
#include <string>
#include <map>
#include "Player.hpp"

class	User
{
private:
  std::map<int, Player *> _users;

public:
  User();
  ~User();

public:
  std::map<int, Player *> getUser() const
  {
    return _users;
  };

  void putUser(const int nb, const int x, const int y, const int dir, const int lev, const std::string &tn)
  {
    Player *tmp = new Player(nb, x, y, dir, lev, tn);

    _users[nb] = tmp;
  }

  void movUser(const int nb, const int x, const int y, const int dir)
  {
    _users[nb]->setX1(x);
    _users[nb]->setY1(y);
    _users[nb]->setDir(dir);
  }

  void pCast(const int nb)
  {
    _users[nb]->setCasting(1);
  }
};

#endif
