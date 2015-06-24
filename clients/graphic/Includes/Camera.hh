//
// Camera.hh for Camera in /home/theven_l/Dropbox/zappy/Sources
//
// Made by Leo Thevenet
// Login   <theven_l@epitech.net>
//
// Started on  Mon Jun 22 16:21:49 2015 Leo Thevenet
// Last update Wed Jun 24 17:49:21 2015 Leo Thevenet
//

#ifndef __CAMERA_HH__
#define __CAMERA_HH__

#include <SdlContext.hh>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
//#include <AShader.hh>
//#include <BasicShader.hh>
//#include <stdexcept>
#include <map>
//#include <unistd.h>

class	Camera
{
  float _x, _y, _z;
  float _x2, _y2, _z2;
  std::map<int, void(Camera::*)()> _keys;
public:
  Camera(float, float, float);
  ~Camera();
  const glm::mat4 getCam();
  const glm::mat4 getCam2();
  const glm::vec3 getPosHUD();
  void	setCam(float, float, float);
  void	setCam2(float, float, float);
  void	getKey(gdl::Input &input);
  void	camLeft();
  void	camRight();
  void	camDown();
  void	camUp();
  void	camMinus();
  void	camPlus();
};

#endif
