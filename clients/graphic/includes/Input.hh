//
// Input.hh for Input in /home/lopez_t/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Thu Jun 11 11:32:20 2015 Thibaut Lopez
// Last update Wed Jun 17 10:43:41 2015 Thibaut Lopez
//

#ifndef	INPUT_HH
#define	INPUT_HH
#define	MAIN_TTF	"tools/Nintendo-DS-BIOS.ttf"

#include "Rectangle.hh"

class		Input : public Rectangle
{
private:
  SDL_Rect	_textPos;
  SDL_Color	_fColor;
  SDL_Texture	*_text;
  std::string	_content;
  std::string	_base;
  int		_curPos;

  TTF_Font	*_ttf;
  int		_size;

  bool		_isSelected;
  time_t	_time;

  void		_renderTexture(SDL_Texture *, SDL_Renderer *, SDL_Rect *, SDL_Rect *);
  void		_setText(SDL_Renderer *);
public:
  explicit Input(bool, size_t, size_t);
  virtual ~Input();
  void		init(size_t, size_t, const std::string &, SDL_Renderer *);
  void		setSelected(bool);
  void		addChar(const std::string &, SDL_Renderer *);
  void		curRight();
  void		curLeft();
  void		deleteChar();
  void		supprChar();
  std::string	getInput() const;
  virtual void	refresh(SDL_Renderer *);
};

#endif
