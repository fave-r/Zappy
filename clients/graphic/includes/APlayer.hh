//
// APlayer.hh for APlayer.hh in /home/jean_c/Dropbox/zappy
//
// Made by jean_c
// Login   <jean_c@epitech.net>
//
// Started on  Mon Jun 22 16:27:57 2015 jean_c
// Last update Mon Jun 22 17:10:33 2015 jean_c
//

#ifndef __APLAYER_HH__
# define __APLAYER_HH__

#include <Model.hh>

#include "AObject.hh"
#include "IUpdatable.hh"

class		APlayer : virtual public AObject, public IUpdatable
{
public:
  enum eOrientation {
    UP,
    RIGHT,
    DOWN,
    LEFT
  };

public:
  APlayer(int x, int y, const APlayer::eOrientation &orientation);
  virtual ~APlayer();

public:
  virtual void		draw(gdl::AShader &shader);

private:
  float                 _elapse;
  float                 _speed;
  eOrientation		_orientation;
  gdl::Texture		_texture;
  gdl::Model		_model;
};

#endif
