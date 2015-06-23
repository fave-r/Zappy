//
// Map.cpp for Map in /home/lopez_t/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Tue Jun 09 19:21:19 2015 Thibaut Lopez
// Last update Mon Jun 22 16:14:08 2015 jean_c
//

#include "Map.hh"

Map::Map()
{
}

Map::~Map()
{
}

void	Map::handleKeys()
{
}

void	Map::setLength(const size_t val)
{
  this->_length = val;
}
void	Map::setWidth(const size_t val)
{
  this->_width = val;
}

size_t	Map::getLength()
{
  return this->_length;
}

size_t	Map::getwidth()
{
  return this->_width;
}
