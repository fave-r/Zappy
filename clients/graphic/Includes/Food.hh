//
// Food.hh for Food.hh in /home/jean_c/Zappy/clients/graphic
//
// Made by jean_c
// Login   <jean_c@epitech.net>
//
// Started on  Sat Jun 27 01:07:06 2015 jean_c
// Last update Sat Jun 27 01:15:02 2015 jean_c
//

#ifndef __FOOD_HH__
# define __FOOD_HH__

#include "AObject.hh"

class		Food : virtual public AObject
{
public:
  Food(int x, int y);
  virtual ~Food();

public:
  virtual void		draw(gdl::AShader &shader);
  virtual void		setModel(const gdl::Geometry &);

private:
  gdl::Geometry _geometry;
};

#endif
