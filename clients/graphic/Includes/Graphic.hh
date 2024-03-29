//
// Graphic.hh for Graphic.hh in /home/jean_c/Dropbox/zappy
//
// Made by jean_c
// Login   <jean_c@epitech.net>
//
// Started on  Sat Jun 20 09:08:50 2015 jean_c
// Last update Sat Jul  4 22:38:12 2015 Leo Thevenet
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
#include "Map.hh"
#include "Egg.hh"

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
  void			setMap(std::vector<std::vector <Content *> > &, std::list<std::pair<int, int> > &,
                    std::list<int> &, User &, std::list<std::string> &_teamnames, std::map<int, std::pair<int, int> > &);
  void			addNumberHUD();
private:
  int		_width;
  int		_height;
  size_t		_camType;
  int			_actualCase;
  bool		        _needUpdate;
  int			_selectedP;
  std::list<std::string> _teamnames;

  std::vector<std::vector <Content *> >     _map;
  std::list<std::pair<int, int> >           _update;
  std::list<Egg *>                          _listOfEggs;
  std::list<int>                            _play;
  User                                      _user;

  gdl::SdlContext	_context;
public:
  gdl::BasicShader	_shader;
private:
  gdl::Input		_input;
  gdl::Clock		_clock;

  std::vector<AObject*>	_objects;
  std::vector<AObject*>	_HUD;

  ModelPool		*_modelPool;
  TexturePool		*_texturePool;
  std::map<int, std::pair<int, int> > _eggs;
  Camera		*_cam;

  void			MoveCase(int);
  template <typename T>void	erase(std::list<std::pair<int, int> >::const_iterator it2);
template <typename T> void Elements(int mode, const gdl::Geometry &model, std::list<std::pair<int, int> >::const_iterator &it2, int one, bool two);
};

#endif
