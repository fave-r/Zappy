//
// Egg.hh for Egg.hh in /home/jean_c/Zappy/clients/graphic
//
// Made by jean_c
// Login   <jean_c@epitech.net>
//
// Started on  Sat Jul  4 22:37:17 2015 jean_c
// Last update Sat Jul  4 22:37:51 2015 jean_c
//

#ifndef __EGG_HH__
# define __EGG_HH__

#include <Model.hh>
#include "AObject.hh"

class      Egg : virtual public AObject
{
public:
  Egg(int, int);
  virtual ~Egg();

public:
  virtual void          draw(gdl::AShader &shader);
  virtual void		      setModel(const gdl::Geometry &);

private:
  static gdl::Model  _model;
  static int          _init;
};

#endif
