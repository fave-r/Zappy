//
// Thystame.hh for Thystame.hh in /home/jean_c/Zappy/clients/graphic
//
// Made by jean_c
// Login   <jean_c@epitech.net>
//
// Started on  Sat Jun 27 01:07:06 2015 jean_c
// Last update Sat Jun 27 01:27:50 2015 jean_c
//

#ifndef __THYSTAME_HH__
# define __THYSTAME_HH__

#include "AObject.hh"

class		Thystame : virtual public AObject
{
public:
  Thystame(int x, int y);
  virtual ~Thystame();

public:
  virtual void		draw(gdl::AShader &shader);
  virtual void		setModel(const gdl::Geometry &);

private:
  gdl::Geometry _geometry;
};

#endif
