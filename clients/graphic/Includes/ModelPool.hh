//
// ModelPool.hh for ModelPool.hh in /home/jean_c/Dropbox/zappy
//
// Made by jean_c
// Login   <jean_c@epitech.net>
//
// Started on  Sun Jun 21 02:21:07 2015 jean_c
// Last update Sun Jun 21 02:25:35 2015 jean_c
//

#ifndef __MODELPOOL_HH__
# define __MODELPOOL_HH__

#include <Geometry.hh>

class		ModelPool
{
public:
  ModelPool();
  ~ModelPool();

public:
  void			init();
  const gdl::Geometry   &getGround() const;

private:
  gdl::Geometry         _ground;
};

#endif
