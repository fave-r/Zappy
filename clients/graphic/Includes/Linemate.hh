//
// Linemate.hh for Linemate.hh in /home/jean_c/Zappy/clients/graphic/Includes
//
// Made by jean_c
// Login   <jean_c@epitech.net>
//
// Started on  Sat Jun 27 01:18:38 2015 jean_c
// Last update Sat Jun 27 01:18:57 2015 jean_c
//

#ifndef __LINEMATE_HH__
# define __LINEMATE_HH__

#include <Model.hh>
#include "AObject.hh"

class		Linemate : virtual public AObject
{
public:
  Linemate(int x, int y);
  virtual ~Linemate();

public:
  virtual void		draw(gdl::AShader &shader);
  virtual void		setModel(const gdl::Geometry &);

private:
  gdl::Model		_model;
};

#endif
