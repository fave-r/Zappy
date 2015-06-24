//
// AObject.hh for AObject.hh in /home/jean_c/Dropbox/zappy
//
// Made by jean_c
// Login   <jean_c@epitech.net>
//
// Started on  Sun Jun 21 01:57:23 2015 jean_c
// Last update Tue Jun 23 11:46:39 2015 Leo Thevenet
//

#ifndef __AOBJECT_HH__
# define __AOBJECT_HH__

#include <Geometry.hh>
#include <AShader.hh>
#include <BasicShader.hh>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <Texture.hh>

class		AObject
{
public:
  AObject(float x, float y);
  virtual ~AObject();

public:
  virtual void          draw(gdl::AShader &shader) = 0;
  void                  scale(const glm::vec3 &scale);
  void                  translate(const glm::vec3 &v);
  void                  setPos(const glm::vec3 &v);
  void			rotate(const glm::vec3 &axis, const float &angle);

public:
  const glm::mat4	getTransformation();

public:
  virtual void		setModel(const gdl::Geometry &) = 0;
  void                  setTexture(const gdl::Texture &old);

protected:
  float			_x;
  float			_y;
  glm::vec3             _position;
  glm::vec3             _rotation;
  glm::vec3             _scale;
  gdl::Texture		_texture;

};

#endif
