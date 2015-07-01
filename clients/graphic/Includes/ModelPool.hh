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
  const gdl::Geometry   &getCrystalD() const;
  const gdl::Geometry   &getCrystalL() const;
  const gdl::Geometry   &getCrystalM() const;
  const gdl::Geometry   &getCrystalP() const;
  const gdl::Geometry   &getCrystalS() const;
  const gdl::Geometry   &getCrystalT() const;
  const gdl::Geometry   &getFood() const;

private:
  gdl::Geometry         _ground;
  gdl::Geometry         _crystalD;
  gdl::Geometry         _crystalL;
  gdl::Geometry         _crystalM;
  gdl::Geometry         _crystalP;
  gdl::Geometry         _crystalS;
  gdl::Geometry         _crystalT;
  gdl::Geometry         _food;

};

#endif
