//
// Input.hh for Input in /home/lopez_t/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Thu Jun 11 11:32:20 2015 Thibaut Lopez
// Last update Sun Jun 14 18:52:13 2015 Thibaut Lopez
//

#ifndef	INPUT_HH
#define	INPUT_HH
#define	MAIN_TTF	"tools/Nintendo-DS-BIOS.ttf"

#include <iostream>
#include <string>
#include <stdexcept>
#include <SDL2/SDL.h>
#include "SDL2/SDL_ttf.h"

class		Input
{
private:
  SDL_Rect	_bgPos;
  SDL_Texture	*_bg;

  SDL_Rect	_textPos;
  SDL_Color	_fColor;
  SDL_Texture	*_text;
  std::string	_content;
  int		_curPos;

  TTF_Font	*_ttf;
  int		_size;

  bool		_isSelected;

  void		_setText(SDL_Renderer *);
public:
  explicit Input(bool);
  virtual ~Input();
  void		init(size_t, size_t, size_t, size_t, SDL_Renderer *);
  void		setSelected(bool);
  void		addChar(const std::string &, SDL_Renderer *);
  void		curRight();
  void		curLeft();
  void		deleteChar();
  void		supprChar();
  std::string	getInput() const;
  void		refresh(SDL_Renderer *);
};

#endif