//
// TexturePool.hh for TexturePool.hh in /home/jean_c/Dropbox/zappy
//
// Made by jean_c
// Login   <jean_c@epitech.net>
//
// Started on  Sun Jun 21 02:31:35 2015 jean_c
// Last update Thu Jul  2 12:37:45 2015 Leo Thevenet
//

#ifndef __TEXTUREPOOL_HH__
# define __TEXTUREPOOL_HH__

#include <Texture.hh>

#include "Error.hh"

class		TexturePool
{
public:
  TexturePool();
  ~TexturePool();

public:
  void			init();

public:
  const gdl::Texture	&getGround() const;
  const gdl::Texture    &getSelectedGround() const;
  const gdl::Texture    &getWaterMelon() const;
  const gdl::Texture	&getNumber(int nb) const;

private:
  gdl::Texture		_textureGround;
  gdl::Texture		_textureSelectedGround;
  gdl::Texture		_textureWaterMelon;
  gdl::Texture		_number[10];
};

#endif
