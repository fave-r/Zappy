//
// TexturePool.cpp for TexturePool.cpp in /home/jean_c/Dropbox/zappy
//
// Made by jean_c
// Login   <jean_c@epitech.net>
//
// Started on  Sun Jun 21 02:33:58 2015 jean_c
// Last update Wed Jun 24 09:44:17 2015 jean_c
//

#include "TexturePool.hh"

TexturePool::TexturePool()
{
}

TexturePool::~TexturePool()
{
}

void                    TexturePool::init()
{
  if (this->_textureGround.load("./Ressources/Textures/ground.tga", true) == false)
    throw loading_error("TexturePool : Cannot load Ground texture");
}

const gdl::Texture      &TexturePool::getGround()
{
  return this->_textureGround;
}
