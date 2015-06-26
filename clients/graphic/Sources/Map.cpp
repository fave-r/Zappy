//
// Map.cpp for Map in /home/lopez_t/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Tue Jun 09 19:21:19 2015 Thibaut Lopez
// Last update Fri Jun 26 19:23:12 2015 jean_c
//

#include "Map.hh"

Map::Map() : _length(0), _width(0)
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

void	Map::init()
{
  std::vector<std::vector<Content *> > A(this->_length, std::vector<Content *>(this->_width));

  for (unsigned int y = 0; y < A.size(); ++y)
    for (unsigned int x = 0; x < A[y].size(); ++x)
      A[y][x] = new Content;
  this->_map = A;
}

std::vector<std::vector<Content *> > Map::getMap() const
{
  return this->_map;
}

void	Map::setMap(const int y, const int x, const Type type, const int number)
{ // ya un segfault ici quand on lance longtemps le zappy
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
