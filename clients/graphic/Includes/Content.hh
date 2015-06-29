//
// Content.hh for zappy in /home/fave_r/rendu/Zappy/clients/graphic
//
// Made by romaric
// Login   <fave_r@epitech.net>
//
// Started on  Tue Jun 23 15:25:07 2015 romaric
// Last update Tue Jun 23 20:48:44 2015 romaric
//

#ifndef	CONTENT_HH
#define	CONTENT_HH

#include <iostream>
#include <string>

class	Content
{
private:
  int	_food;
  int	_linemate;
  int	_deraumere;
  int	_sibur;
  int	_mendiane;
  int	_phiras;
  int	_thystame;
  bool _boolF;

public:
  Content();
  ~Content();

public:
  void	setFood(const int);
  void	setLinemate(const int);
  void	setDeraumere(const int);
  void	setSibur(const int);
  void	setMendiane(const int);
  void	setPhiras(const int);
  void	setThystame(const int);
  int	getFood(void) const;
  int	getLinemate(void) const;
  int	getDeraumere(void) const;
  int	getSibur(void) const;
  int	getMendiane(void) const;
  int	getPhiras(void) const;
  int	getThystame(void) const;
  bool    getBoolF() const;
  void    setBoolF(const bool);
};

#endif
