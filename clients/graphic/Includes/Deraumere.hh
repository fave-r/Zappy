//
// Deraumere.hh for Deraumere.hh in /home/jean_c/Zappy/clients/graphic
//
// Made by jean_c
// Login   <jean_c@epitech.net>
//
// Started on  Sat Jun 27 01:07:06 2015 jean_c
// Last update Sat Jun 27 01:20:53 2015 jean_c
//

#ifndef __DERAUMERE_HH__
# define __DERAUMERE_HH__

#include "AObject.hh"

class		Deraumere : virtual public AObject
{
public:
  Deraumere(int x, int y);
  virtual ~Deraumere();

public:
  virtual void		draw(gdl::AShader &shader);
  virtual void		setModel(const gdl::Geometry &);

private:
  gdl::Geometry         _geometry;
};

#endif
