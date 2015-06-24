//
// APlayer.cpp for APlayer.cpp in /home/jean_c/Dropbox/zappy
//
// Made by jean_c
// Login   <jean_c@epitech.net>
//
// Started on  Mon Jun 22 16:36:00 2015 jean_c
// Last update Mon Jun 22 17:11:23 2015 jean_c
//

#include "APlayer.hh"

APlayer::APlayer(int x, int y, const APlayer::eOrientation &orientation) : AObject(x, y), _speed(2)
{
  (void)orientation;
  this->_elapse = 1.0; // TO REMOVE
}

APlayer::~APlayer()
{
}

void		APlayer::draw(gdl::AShader &shader)
{
  this->_texture.bind();
  this->_model.draw(shader, getTransformation(), this->_elapse / 3 * this->_speed);
}
