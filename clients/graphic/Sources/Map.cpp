//
// Map.cpp for Map in /home/lopez_t/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Tue Jun 09 19:21:19 2015 Thibaut Lopez
// Last update Wed Jun 24 01:06:52 2015 jean_c
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

size_t	Map::getWidth()
{
  return this->_width;
}

void	Map::setMap(const int x, const int y, const Type type, const int number)
{
  switch (type)
    {
    case FOOD :
      this->_map[y][x]->setFood(number);
      break;
    case LINEMATE :
      this->_map[y][x]->setLinemate(number);
      break;
    case DERAUMERE :
      this->_map[y][x]->setDeraumere(number);
      break;
    case SIBUR :
      this->_map[y][x]->setSibur(number);
      break;
    case MENDIANE :
      this->_map[y][x]->setMendiane(number);
      break;
    case PHIRAS :
      this->_map[y][x]->setPhiras(number);
      break;
    case THYSTAME :
      this->_map[y][x]->setThystame(number);
      break;
    }
}