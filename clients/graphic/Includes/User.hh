//
// User.hh for zappy in /home/fave_r/rendu/Zappy/clients/graphic
//
// Made by romaric
// Login   <fave_r@epitech.net>
//
// Started on  Mon Jun 29 13:02:34 2015 romaric
// Last update Mon Jun 29 13:25:13 2015 romaric
//

#ifndef	USER_HH
#define	USER_HH

#include <iostream>
#include <string>
#include <list>
#include "Player.hh"

class	User
{
private:
std::list<Player *> _users;

public:
  User();
  ~User();

public:
  std::list<Player *> getUser() const
  {
    return _users;
  };

  void putUser(const int nb, const int x, const int y, const int dir, const int lev, const std::string &tn)
  {
    Player tmp(nb, x, y, dir, lev, tn);

    _users.push_back(&tmp);
  }
};

#endif
