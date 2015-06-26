//
// Ground.hh for Ground.hh in /home/jean_c/Dropbox/zappy
//
// Made by jean_c
// Login   <jean_c@epitech.net>
//
// Started on  Sun Jun 21 02:12:29 2015 jean_c
// Last update Sat Jun 27 01:09:59 2015 jean_c
//

#ifndef __GROUND_HH__
# define __GROUND_HH__

#include <list>
#include "AObject.hh"

class		Ground : virtual public AObject
{
public:
  Ground(int x, int y);
  ~Ground();

public:
  virtual void		draw(gdl::AShader &shader);
  virtual void		setModel(const gdl::Geometry &);
  void			pushInList(const AObject *);

private:
  gdl::Geometry					_geometry;
  std::list<std::pair<float, const AObject *> >	_listRessources;
};

#endif
