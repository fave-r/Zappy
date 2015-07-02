//
// TexturePool.cpp for TexturePool.cpp in /home/jean_c/Dropbox/zappy
//
// Made by jean_c
// Login   <jean_c@epitech.net>
//
// Started on  Sun Jun 21 02:33:58 2015 jean_c
// Last update Wed Jun 24 17:19:48 2015 jean_c
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
  else if (this->_textureSelectedGround.load("./Ressources/Textures/selectedGround.tga", true) == false)
    throw loading_error("TexturePool : Cannot load Selected Ground texture");
/*  else if (this->_textureWaterMelon.load("./Ressources/Textures/Watermelon_Cartoon.tga", true) == false)
    throw loading_error("TexturePool : Cannot load Selected WaterMelon texture");
      else if (this->_White.load("./Ressources/Textures/white.tga", true) == false)
    throw loading_error("TexturePool : Cannot load Selected WaterMelon texture");*/
}

const gdl::Texture      &TexturePool::getGround() const
{
  return this->_textureGround;
}

const gdl::Texture      &TexturePool::getSelectedGround() const
{
  return this->_textureSelectedGround;
}

const gdl::Texture      &TexturePool::getWaterMelon() const
{
  return this->_textureWaterMelon;
}

const gdl::Texture      &TexturePool::getWhite() const{
  return this->_White;
}
