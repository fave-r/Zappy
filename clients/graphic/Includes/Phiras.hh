//
// Phiras.hh for Phiras.hh in /home/jean_c/Zappy/clients/graphic
//
// Made by jean_c
// Login   <jean_c@epitech.net>
//
// Started on  Sat Jun 27 01:07:06 2015 jean_c
// Last update Sat Jun 27 01:26:27 2015 jean_c
//

#ifndef __PHIRAS_HH__
# define __PHIRAS_HH__

#include "AObject.hh"

class		Phiras : virtual public AObject
{
public:
  Phiras(int x, int y);
  virtual ~Phiras();

public:
  virtual void		draw(gdl::AShader &shader);
  virtual void		setModel(const gdl::Geometry &);

private:
  gdl::Geometry _geometry;
};

#endif
