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
  this->_boolD = false;
  this->_boolL = false;
  this->_boolM = false;
  this->_boolP = false;
  this->_boolS = false;
  this->_boolT = false;
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

bool    Content::getBoolD() const
{
  return this->_boolD;
}

void    Content::setBoolD(const bool boolD)
{
  this->_boolD = boolD;
}

bool    Content::getBoolL() const
{
  return this->_boolL;
}

void    Content::setBoolL(const bool boolL)
{
  this->_boolL = boolL;
}

bool    Content::getBoolM() const
{
  return this->_boolM;
}

void    Content::setBoolM(const bool boolM)
{
  this->_boolM = boolM;
}

bool    Content::getBoolP() const
{
  return this->_boolP;
}

void    Content::setBoolP(const bool boolP)
{
  this->_boolP = boolP;
}

bool    Content::getBoolS() const
{
  return this->_boolS;
}

void    Content::setBoolS(const bool boolS)
{
  this->_boolS = boolS;
}

bool    Content::getBoolT() const
{
  return this->_boolT;
}

void    Content::setBoolT(const bool boolT)
{
  this->_boolT = boolT;
}
