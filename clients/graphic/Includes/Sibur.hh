//
// Sibur.hh for Sibur.hh in /home/jean_c/Zappy/clients/graphic
//
// Made by jean_c
// Login   <jean_c@epitech.net>
//
// Started on  Sat Jun 27 01:07:06 2015 jean_c
// Last update Sat Jun 27 01:23:01 2015 jean_c
//

#ifndef __SIBUR_HH__
# define __SIBUR_HH__

#include "AObject.hh"

class		Sibur : virtual public AObject
{
public:
  Sibur(int x, int y);
  virtual ~Sibur();

public:
  virtual void		draw(gdl::AShader &shader);
  virtual void		setModel(const gdl::Geometry &);

private:
  gdl::Geometry _geometry;
};

#endif
