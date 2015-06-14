//
// Input.cpp for Input in /home/lopez_t/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Thu Jun 11 11:32:20 2015 Thibaut Lopez
// Last update Sun Jun 14 21:36:52 2015 Thibaut Lopez
//

#include "Input.hh"

void		Input::_renderTexture(SDL_Texture *tex, SDL_Renderer *ren, SDL_Rect *dst)
{
  SDL_QueryTexture(tex, NULL, NULL, &dst->w, &dst->h);
  SDL_RenderCopy(ren, tex, NULL, dst);
}

void		Input::_setText(SDL_Renderer *ren)
{
  SDL_Surface	*text;
  std::string	content;

  content = this->_content;
  if (this->_isSelected == false)
    content[this->_curPos] = ' ';
  text = TTF_RenderText_Blended(this->_ttf, content.c_str(), this->_fColor);
  if (text == NULL)
    throw std::runtime_error("TTF_RenderText_Blended.");
  this->_text = SDL_CreateTextureFromSurface(ren, text);
  SDL_FreeSurface(text);
  if (this->_text == NULL)
    throw std::runtime_error("SDL_CreateTextureFromSurface.");
}

Input::Input(bool isSelected)
  : _bg(NULL), _text(NULL), _content("|"), _curPos(0), _size(0), _isSelected(isSelected)
{
  this->_fColor.r = 255;
  this->_fColor.g = 255;
  this->_fColor.b = 255;
}

Input::~Input()
{
  SDL_DestroyTexture(this->_text);
  SDL_DestroyTexture(this->_bg);
  TTF_CloseFont(this->_ttf);
}

void		Input::init(size_t posX, size_t posY, size_t width, size_t height, SDL_Renderer *ren)
{
  SDL_Surface	*bg;

  this->_bgPos.x = posX;
  this->_bgPos.y = posY;
  this->_bgPos.h = height;
  this->_bgPos.w = width;

  this->_textPos.x = posX + 10;
  this->_textPos.y = posY + height / 10;

  bg = SDL_CreateRGBSurface(0, this->_bgPos.w, this->_bgPos.h, 32, 0, 0, 0, 0);
  if (bg == NULL)
    throw std::runtime_error("SDL_CreateRGBSurface.");
  SDL_FillRect(bg, NULL, SDL_MapRGB(bg->format, 0, 0, 0));
  if ((this->_bg = SDL_CreateTextureFromSurface(ren, bg)) == NULL)
    throw std::runtime_error("SDL_CreateTextureFromSurface.");
  SDL_FreeSurface(bg);
  SDL_SetTextureAlphaMod(this->_bg, 100);

  this->_size = height;
  this->_ttf = TTF_OpenFont(MAIN_TTF, this->_size);
  if (this->_ttf == NULL)
    throw std::runtime_error("TTF_OpenFont.");
}

void		Input::setSelected(bool isSelected)
{
  this->_isSelected = isSelected;
}

void		Input::addChar(const std::string &c, SDL_Renderer *ren)
{
  int		h;
  int		w;
  std::string	str("");
  SDL_Surface	*text;

  str.append(this->_content.substr(0, this->_curPos));
  str.append(c);
  str.append("|");
  str.append(this->_content.substr(this->_curPos + 1));
  this->_curPos += c.size();
  text = TTF_RenderText_Blended(this->_ttf, str.c_str(), this->_fColor);
  if (text == NULL)
    throw std::runtime_error("TTF_RenderText_Blended.");
  this->_text = SDL_CreateTextureFromSurface(ren, text);
  SDL_FreeSurface(text);
  if (this->_text == NULL)
    throw std::runtime_error("SDL_CreateTextureFromSurface.");
  SDL_QueryTexture(this->_text, NULL, NULL, &w, &h);
  if (w > this->_bgPos.w)
    this->_curPos -= c.size();
  else
    this->_content = str;
}

void		Input::curRight()
{
  std::string	str("");

  if (this->_curPos == static_cast<int>(this->_content.size() - 1))
    return ;
  str.append(this->_content.substr(0, this->_curPos));
  str.append(1, this->_content.at(this->_curPos + 1));
  str.append("|");
  this->_curPos++;
  str.append(this->_content.substr(this->_curPos + 1));
  this->_content = str;
}

void		Input::curLeft()
{
  std::string	str("");

  if (this->_curPos == 0)
    return ;
  str.append(this->_content.substr(0, this->_curPos - 1));
  str.append("|");
  this->_curPos--;
  str.append(1, this->_content.at(this->_curPos));
  str.append(this->_content.substr(this->_curPos + 2));
  this->_content = str;
}

void		Input::deleteChar()
{
  std::string	str("");

  if (this->_curPos == 0)
    return ;
  str.append(this->_content.substr(0, this->_curPos - 1));
  str.append("|");
  this->_curPos--;
  str.append(this->_content.substr(this->_curPos + 2));
  this->_content = str;
}

void		Input::supprChar()
{
  std::string	str("");

  if (this->_curPos == static_cast<int>(this->_content.size() - 1))
    return ;
  str.append(this->_content.substr(0, this->_curPos));
  str.append("|");
  str.append(this->_content.substr(this->_curPos + 2));
  this->_content = str;
}

std::string	Input::getInput() const
{
  std::string	ret("");

  ret.append(this->_content.substr(0, this->_curPos));
  ret.append(this->_content.substr(this->_curPos + 1));
  return (ret);
}

bool		Input::isClicked(int x, int y) const
{
  return (x >= this->_bgPos.x && x <= this->_bgPos.x + this->_bgPos.w && y >= this->_bgPos.y && y <= this->_bgPos.y + this->_bgPos.h);
}

void		Input::refresh(SDL_Renderer *ren)
{
  this->_renderTexture(this->_bg, ren, &this->_bgPos);
  this->_setText(ren);
  this->_renderTexture(this->_text, ren, &this->_textPos);
}
