//
// Mendiane.hh for Mendiane.hh in /home/jean_c/Zappy/clients/graphic
//
// Made by jean_c
// Login   <jean_c@epitech.net>
//
// Started on  Sat Jun 27 01:07:06 2015 jean_c
// Last update Sat Jun 27 01:24:41 2015 jean_c
//

#ifndef __MENDIANE_HH__
# define __MENDIANE_HH__

#include <Model.hh>
#include "AObject.hh"

class		Mendiane : virtual public AObject
{
public:
  Mendiane(int x, int y);
  virtual ~Mendiane();

public:
  virtual void		draw(gdl::AShader &shader);
  virtual void		setModel(const gdl::Geometry &);

private:
  gdl::Model		_model;
};

#endif
