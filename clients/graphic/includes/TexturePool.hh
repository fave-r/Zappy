//
// TexturePool.hh for TexturePool.hh in /home/jean_c/Dropbox/zappy
//
// Made by jean_c
// Login   <jean_c@epitech.net>
//
// Started on  Sun Jun 21 02:31:35 2015 jean_c
// Last update Sun Jun 21 02:37:09 2015 jean_c
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
  const gdl::Texture	&getGround();

private:
  gdl::Texture		_textureGround;

};

#endif
