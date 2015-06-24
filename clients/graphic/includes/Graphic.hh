//
// Graphic.hh for Graphic.hh in /home/jean_c/Dropbox/zappy
//
// Made by jean_c
// Login   <jean_c@epitech.net>
//
// Started on  Sat Jun 20 09:08:50 2015 jean_c
// Last update Wed Jun 24 02:53:40 2015 jean_c
//

#ifndef __GRAPHIC_HH__
# define __GRAPHIC_HH__

#include <Input.hh>
#include <SdlContext.hh>
#include <AShader.hh>
#include <BasicShader.hh>
#include <stdexcept>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

#include "AObject.hh"
#include "ModelPool.hh"
#include "TexturePool.hh"
#include "Ground.hh"
#include "Camera.hh"

class		Graphic
{
public:
  Graphic(size_t width, size_t height);
  ~Graphic();

  void			Initialize();
  bool			update();
  void			draw();
  void			initMap();
  void			setHUD();
  void			updateHUD();
private:
  size_t		_width;
  size_t		_height;
  bool			_isHUD;

  gdl::SdlContext	_context;
  gdl::BasicShader	_shader;
  gdl::Input		_input;
  gdl::Clock		_clock;

  std::vector<AObject*>	_objects;
  std::vector<AObject*>	_HUD;

  ModelPool		*_modelPool;
  TexturePool		*_texturePool;

  Camera		*_cam;
};

#endif
