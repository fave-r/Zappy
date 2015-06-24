//
// Ground.hh for Ground.hh in /home/jean_c/Dropbox/zappy
//
// Made by jean_c
// Login   <jean_c@epitech.net>
//
// Started on  Sun Jun 21 02:12:29 2015 jean_c
// Last update Sun Jun 21 02:16:08 2015 jean_c
//

#ifndef __GROUND_HH__
# define __GROUND_HH__

#include "AObject.hh"

class		Ground : virtual public AObject
{
public:
  Ground(int x, int y);
  ~Ground();

public:
  void			draw(gdl::AShader &shader);
  void			setModel(const gdl::Geometry &);

private:
  gdl::Geometry		_geometry;
};

#endif
