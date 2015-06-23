//
// Content.cpp for zappy in /home/fave_r/rendu/Zappy/clients/graphic
//
// Made by romaric
// Login   <fave_r@epitech.net>
//
// Started on  Tue Jun 23 15:25:38 2015 romaric
// Last update Tue Jun 23 15:47:56 2015 romaric
//

#include "Content.hh"

Content::Content()
{
}

Content::~Content()
{
}

void		setLinemate(const int val)
{
  this->_linemate = val;
}

void		setDeraumere(const int val)
{
  this->_deraumere = val;
}

void		setSibur(const int val)
{
  this->_sibur = val;
}

void  setMendiane(const int val)
{
  this->_mendiane = val;
}

void  setPhiras(const int val)
{
  this->_phiras = val;
}

void  setThystame(const int val)
{
  this->_phiras = val;
}

int   getLinemate(void) const
{
  return _linemate;
}

int   getDeraumere(void) const
{
  return _deraumere;
}

int   getSibur(void) const
{
  return _sibur;
}

int   getMendiane(void) const
{
  return _mendiane;
}

int   getPhiras(void) const
{
  return _phiras;
}

int   getThystame(void) const
{
  return _thystame;
}
