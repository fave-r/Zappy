//
// Content.cpp for zappy in /home/fave_r/rendu/Zappy/clients/graphic
//
// Made by romaric
// Login   <fave_r@epitech.net>
//
// Started on  Tue Jun 23 15:25:38 2015 romaric
// Last update Tue Jun 23 20:57:01 2015 romaric
//

#include "Content.hh"

Content::Content()
{
  this->_food = 0;
  this->_linemate = 0;
  this->_deraumere = 0;
  this->_sibur = 0;
  this->_mendiane = 0;
  this->_phiras = 0;
  this->_thystame = 0;
  this->_boolF = false;
}

Content::~Content()
{
}

void		Content::setFood(const int val)
{
  this->_food = val;
}

void		Content::setLinemate(const int val)
{
  this->_linemate = val;
}

void		Content::setDeraumere(const int val)
{
  this->_deraumere = val;
}

void		Content::setSibur(const int val)
{
  this->_sibur = val;
}

void		Content::setMendiane(const int val)
{
  this->_mendiane = val;
}

void		Content::setPhiras(const int val)
{
  this->_phiras = val;
}

void		Content::setThystame(const int val)
{
  this->_phiras = val;
}

int		Content::getFood(void) const
{
  return _food;
}

int		Content::getLinemate(void) const
{
  return _linemate;
}

int		Content::getDeraumere(void) const
{
  return _deraumere;
}

int		Content::getSibur(void) const
{
  return _sibur;
}

int		Content::getMendiane(void) const
{
  return _mendiane;
}

int		Content::getPhiras(void) const
{
  return _phiras;
}

int		Content::getThystame(void) const
{
  return _thystame;
}

bool    Content::getBoolF() const
{
  return this->_boolF;
}

void    Content::setBoolF(const bool boolF)
{
  this->_boolF = boolF;
}
