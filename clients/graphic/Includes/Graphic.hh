//
// Graphic.hh for Graphic.hh in /home/jean_c/Dropbox/zappy
//
// Made by jean_c
// Login   <jean_c@epitech.net>
//
// Started on  Sat Jun 20 09:08:50 2015 jean_c
// Last update Thu Jul  2 15:11:53 2015 Leo Thevenet
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
#include <math.h>
#include <unistd.h>
#include <vector>

#include "AObject.hh"
#include "ModelPool.hh"
#include "TexturePool.hh"
#include "Ground.hh"
#include "Camera.hh"
#include "Content.hh"
#include "Food.hh"
#include "Linemate.hh"
#include "Deraumere.hh"
#include "Mendiane.hh"
#include "Phiras.hh"
#include "Sibur.hh"
#include "Thystame.hh"
#include "User.hpp"

class		Graphic
{

public:
  Graphic(size_t, size_t);
  ~Graphic();

  void			Initialize();
  bool			update();
  void			draw();
  void			initMap();
  void			setHUD();
  void			updateHUD();
  void			changeSize(size_t, size_t, std::vector<std::vector <Content *> > &);
  void			setMap(std::vector<std::vector <Content *> > &, std::list<std::pair<int, int> > &, std::list<int> &, User &);
  void			addNumberHUD();
private:
  int		_width;
  int		_height;
  size_t		_camType;
  int			_actualCase;
  bool		        _needUpdate;

  std::vector<std::vector <Content *> >     _map;
  std::list<std::pair<int, int> >           _update;
  std::list<int>                            _play;
  User                                      _user;

  gdl::SdlContext	_context;
  gdl::BasicShader	_shader;
  gdl::Input		_input;
  gdl::Clock		_clock;

  std::vector<AObject*>	_objects;
  std::vector<AObject*>	_HUD;

  ModelPool		*_modelPool;
  TexturePool		*_texturePool;

  Camera		*_cam;

  void			MoveCase(int);
  template <typename T>void	erase(std::list<std::pair<int, int> >::const_iterator it2);
template <typename T> void Elements(int mode, const gdl::Geometry &model, std::list<std::pair<int, int> >::const_iterator &it2, int one, bool two);
};

#endif
