//
// TexturePool.cpp for TexturePool.cpp in /home/jean_c/Dropbox/zappy
//
// Made by jean_c
// Login   <jean_c@epitech.net>
//
// Started on  Sun Jun 21 02:33:58 2015 jean_c
// Last update Thu Jul  2 12:37:50 2015 Leo Thevenet
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
  else if (this->_textureWaterMelon.load("./Ressources/Textures/Watermelon_Cartoon.tga", true) == false)
    throw loading_error("TexturePool : Cannot load Selected WaterMelon texture");
  else if (this->_number[0].load("./Ressources/Textures/0.tga", true) == false)
    throw loading_error("TexturePool : Cannot load Selected 0 texture");
  else if (this->_number[1].load("./Ressources/Textures/1.tga", true) == false)
    throw loading_error("TexturePool : Cannot load Selected 1 texture");
  else if (this->_number[2].load("./Ressources/Textures/2.tga", true) == false)
    throw loading_error("TexturePool : Cannot load Selected WaterMelon texture");
  else if (this->_number[3].load("./Ressources/Textures/3.tga", true) == false)
    throw loading_error("TexturePool : Cannot load Selected 3 texture");
  else if (this->_number[4].load("./Ressources/Textures/4.tga", true) == false)
    throw loading_error("TexturePool : Cannot load Selected 4 texture");
  else if (this->_number[5].load("./Ressources/Textures/5.tga", true) == false)
    throw loading_error("TexturePool : Cannot load Selected 5 texture");
  else if (this->_number[6].load("./Ressources/Textures/6.tga", true) == false)
    throw loading_error("TexturePool : Cannot load Selected 6 texture");
  else if (this->_number[7].load("./Ressources/Textures/7.tga", true) == false)
    throw loading_error("TexturePool : Cannot load Selected 7 texture");
  else if (this->_number[8].load("./Ressources/Textures/8.tga", true) == false)
    throw loading_error("TexturePool : Cannot load Selected 8 texture");
  else if (this->_number[9].load("./Ressources/Textures/9.tga", true) == false)
    throw loading_error("TexturePool : Cannot load Selected 9 texture");
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

const gdl::Texture	&TexturePool::getNumber(int nb) const
{
  if (nb >= 0 && nb < 10)
    return this->_number[nb];
  return this->_number[9];
}
