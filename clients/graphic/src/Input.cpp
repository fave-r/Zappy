//
// Input.cpp for Input in /home/lopez_t/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Thu Jun 11 11:32:20 2015 Thibaut Lopez
// Last update Wed Jun 17 11:51:50 2015 Thibaut Lopez
//

#include "Input.hh"

void		Input::_setText(SDL_Renderer *ren)
{
  SDL_Surface	*text;
  std::string	content;

  if (this->_isSelected == true || (this->_isSelected == false && this->_content.size() > 1))
    {
      content = this->_content;
      if (this->_isSelected == false || time(NULL) - this->_time == 1)
	content[this->_curPos] = ' ';
      else
	this->_time = time(NULL);
    }
  else
    content = this->_base;
  text = TTF_RenderText_Blended(this->_ttf, content.c_str(), this->_fColor);
  if (text == NULL)
    throw std::runtime_error("TTF_RenderText_Blended.");
  this->_text = SDL_CreateTextureFromSurface(ren, text);
  SDL_FreeSurface(text);
  if (this->_text == NULL)
    throw std::runtime_error("SDL_CreateTextureFromSurface.");
}

Input::Input(bool isSelected, size_t posX, size_t posY)
  : Rectangle(posX, posY), _text(NULL), _content("|"), _curPos(0), _size(0), _isSelected(isSelected), _time(time(NULL))
{
  this->_fColor.r = 255;
  this->_fColor.g = 255;
  this->_fColor.b = 255;
}

Input::~Input()
{
  SDL_DestroyTexture(this->_text);
  TTF_CloseFont(this->_ttf);
}

void		Input::init(size_t width, size_t height, const std::string &base, SDL_Renderer *ren)
{
  SDL_Surface	*box;

  this->_pos.h = height;
  this->_pos.w = width;

  this->_textPos.x = this->_pos.x + 10;
  this->_textPos.y = this->_pos.y + height / 10;

  this->_base = base;

  box = SDL_CreateRGBSurface(0, this->_pos.w, this->_pos.h, 32, 0, 0, 0, 0);
  if (box == NULL)
    throw std::runtime_error("SDL_CreateRGBSurface.");
  SDL_FillRect(box, NULL, SDL_MapRGB(box->format, 0, 0, 0));
  if ((this->_box = SDL_CreateTextureFromSurface(ren, box)) == NULL)
    throw std::runtime_error("SDL_CreateTextureFromSurface.");
  SDL_FreeSurface(box);
  SDL_SetTextureAlphaMod(this->_box, 100);

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
  std::string	str("");

  (void)ren;
  str.append(this->_content.substr(0, this->_curPos));
  str.append(c);
  str.append("|");
  str.append(this->_content.substr(this->_curPos + 1));
  this->_curPos += c.size();
  this->_content = str;
  this->_time = time(NULL);
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
  this->_time = time(NULL);
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
  this->_time = time(NULL);
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
  this->_time = time(NULL);
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
  this->_time = time(NULL);
}

std::string	Input::getInput() const
{
  std::string	ret("");

  ret.append(this->_content.substr(0, this->_curPos));
  ret.append(this->_content.substr(this->_curPos + 1));
  return (ret);
}

void		Input::refresh(SDL_Renderer *ren)
{
  SDL_Rect	src;

  Rectangle::refresh(ren);
  this->_setText(ren);
  SDL_QueryTexture(this->_text, NULL, NULL, &this->_textPos.w, &this->_textPos.h);
  src.x = this->_textPos.w - this->_pos.w;
  if (src.x < 0)
    src.x = 0;
  src.y = 0;
  src.w = this->_pos.w;
  src.h = this->_pos.h;
  this->_textPos.w = (this->_textPos.w < this->_pos.w - 10) ? this->_textPos.w : this->_pos.w - 10;
  SDL_RenderCopy(ren, this->_text, &src, &this->_textPos);
}
