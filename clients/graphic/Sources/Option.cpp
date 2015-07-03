//
// Option.cpp for Option in /home/lopez_t/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
// Started on  Mon Jun 22 12:20:56 2015 Thibaut Lopez
// Last update Fri Jul  3 14:08:49 2015 Thibaut Lopez
//

#include "Option.hh"

Option::Option(SDL_Renderer *ren)
  : IRefreshable()
{
  Music	*music;

  this->_bgmVol = new SlideBar(500, 200);
  this->_bgmVol->init(500, ren);
  this->_seVol = new SlideBar(500, 300);
  this->_seVol->init(500, ren);
  this->_rbs.push_back(new RadioBox(500, 400));
  this->_rbs.back()->init(ren);
  this->_rbs.push_back(new RadioBox(800, 400));
  this->_rbs.back()->init(ren);
  this->_rbs.push_back(new RadioBox(500, 535));
  this->_rbs.back()->init(ren);
  this->_rbs.back()->setSelected(true);
  this->_rbs.push_back(new RadioBox(800, 535));
  this->_rbs.back()->init(ren);
  this->_rbs.push_back(new RadioBox(1100, 535));
  this->_rbs.back()->init(ren);
  this->_rbs.push_back(new RadioBox(500, 580));
  this->_rbs.back()->init(ren);
  this->_rbs.back()->setSelected(true);
  this->_rbs.push_back(new RadioBox(800, 580));
  this->_rbs.back()->init(ren);
  this->_rbs.push_back(new RadioBox(1100, 580));
  this->_rbs.back()->init(ren);
  this->_rbs.push_back(new RadioBox(500, 625));
  this->_rbs.back()->init(ren);
  this->_rbs.back()->setSelected(true);
  this->_rbs.push_back(new RadioBox(800, 625));
  this->_rbs.back()->init(ren);
  this->_rbs.push_back(new RadioBox(1100, 625));
  this->_rbs.back()->init(ren);
  this->_rbs.push_back(new RadioBox(500, 670));
  this->_rbs.back()->init(ren);
  this->_rbs.back()->setSelected(true);
  this->_rbs.push_back(new RadioBox(800, 670));
  this->_rbs.back()->init(ren);
  this->_rbs.push_back(new RadioBox(1100, 670));
  this->_rbs.back()->init(ren);
  this->_rbs.push_back(new RadioBox(500, 715));
  this->_rbs.back()->init(ren);
  this->_rbs.back()->setSelected(true);
  this->_rbs.push_back(new RadioBox(800, 715));
  this->_rbs.back()->init(ren);
  this->_rbs.push_back(new RadioBox(1100, 715));
  this->_rbs.back()->init(ren);
  this->_rbs.push_back(new RadioBox(500, 760));
  this->_rbs.back()->init(ren);
  this->_rbs.back()->setSelected(true);
  this->_rbs.push_back(new RadioBox(800, 760));
  this->_rbs.back()->init(ren);
  this->_rbs.push_back(new RadioBox(1100, 760));
  this->_rbs.back()->init(ren);
  this->_rbs.push_back(new RadioBox(500, 805));
  this->_rbs.back()->init(ren);
  this->_rbs.back()->setSelected(true);
  this->_rbs.push_back(new RadioBox(800, 805));
  this->_rbs.back()->init(ren);
  this->_rbs.push_back(new RadioBox(1100, 805));
  this->_rbs.back()->init(ren);
  this->_rbs.push_back(new RadioBox(500, 850));
  this->_rbs.back()->init(ren);
  this->_rbs.back()->setSelected(true);
  this->_rbs.push_back(new RadioBox(800, 850));
  this->_rbs.back()->init(ren);
  this->_rbs.push_back(new RadioBox(1100, 850));
  this->_rbs.back()->init(ren);
 this->_color.r = 255;
  this->_color.b = 255;
  this->_color.g = 255; 
  this->_font = TTF_OpenFont(OPTION_TTF, 80);
  this->_texts.push_back(new TextBox(500, 30));
  this->_texts.back()->load(ren, "Settings", this->_font, this->_color);
  TTF_CloseFont(this->_font);
  this->_font = TTF_OpenFont(OPTION_TTF, 25);
  this->_texts.push_back(new TextBox(270, 210));
  this->_texts.back()->load(ren, "BGM Volume:", this->_font, this->_color);
  this->_texts.push_back(new TextBox(290, 310));
  this->_texts.back()->load(ren, "SE Volume:", this->_font, this->_color);
  this->_texts.push_back(new TextBox(530, 400));
  this->_texts.back()->load(ren, "Mute BGM", this->_font, this->_color);
  this->_texts.push_back(new TextBox(830, 400));
  this->_texts.back()->load(ren, "Mute SE", this->_font, this->_color);
  TTF_CloseFont(this->_font);
  this->_font = TTF_OpenFont(OPTION_TTF, 20);
  this->_texts.push_back(new TextBox(485, 500));
  this->_texts.back()->load(ren, "ASK", this->_font, this->_color);
  this->_texts.push_back(new TextBox(750, 500));
  this->_texts.back()->load(ren, "ALWAYS YES", this->_font, this->_color);
  this->_texts.push_back(new TextBox(1050, 500));
  this->_texts.back()->load(ren, "ALWAYS NO", this->_font, this->_color);
  this->_texts.push_back(new TextBox(200, 535));
  this->_texts.back()->load(ren, "Game restart", this->_font, this->_color);
  this->_texts.push_back(new TextBox(200, 580));
  this->_texts.back()->load(ren, "Team name", this->_font, this->_color);
  this->_texts.push_back(new TextBox(200, 625));
  this->_texts.back()->load(ren, "Player pos", this->_font, this->_color);
  this->_texts.push_back(new TextBox(200, 670));
  this->_texts.back()->load(ren, "Player lvl", this->_font, this->_color);
  this->_texts.push_back(new TextBox(200, 715));
  this->_texts.back()->load(ren, "Player kill", this->_font, this->_color);
  this->_texts.push_back(new TextBox(200, 760));
  this->_texts.back()->load(ren, "Content change", this->_font, this->_color);
  this->_texts.push_back(new TextBox(200, 805));
  this->_texts.back()->load(ren, "Map size", this->_font, this->_color);
  this->_texts.push_back(new TextBox(200, 850));
  this->_texts.back()->load(ren, "Reset", this->_font, this->_color);
  TTF_CloseFont(this->_font);
  this->_eventType[SDL_QUIT] = &Option::_etQuit;
  this->_eventType[SDL_KEYUP] = &Option::_etKeyUp;
  this->_eventType[SDL_TEXTINPUT] = &Option::_etTextInput;
  this->_eventType[SDL_MOUSEBUTTONUP] = &Option::_etMouseButtonUp;
  this->_eventType[SDL_MOUSEBUTTONDOWN] = &Option::_etMouseButtonDown;
  this->_eventType[SDL_MOUSEMOTION] = &Option::_etMouseMotion;
  this->_eventKU[SDLK_ESCAPE] = &Option::_etQuit;
  this->_eventKU[SDLK_RETURN] = &Option::_etKUEnter;
  this->_eventKU[SDLK_KP_ENTER] = &Option::_etKUEnter;
  music = Music::newinstance();
  music->createSound(TEST_SOUND, "test", false);
  this->_testSe = false;
  this->_sPausedBGM = music->getPaused(true);
  this->_sPausedSe = music->getPaused(false);
}

Option::~Option()
{
  std::vector<RadioBox *>::iterator	it;
  std::list<TextBox *>::iterator	it2;

  delete this->_bgmVol;
  delete this->_seVol;
  it = this->_rbs.begin();
  while (it != this->_rbs.end())
    {
      delete (*it);
      ++it;
    }
  it2 = this->_texts.begin();
  while (it2 != this->_texts.end())
    {
      delete (*it2);
      ++it2;
    }
}

Ret	Option::_etQuit(std::pair<std::string, std::string> &ret)
{
  (void)ret;
  throw std::exception();
}

Ret	Option::_etKUEnter(std::pair<std::string, std::string> &ret)
{
  (void)ret;
  return (CHANGE);
}

Ret	Option::_etKeyUp(std::pair<std::string, std::string> &ret)
{
  Ret	eventRet;

  eventRet = NOTHING;
  try
    {
      eventRet = (this->*(this->_eventKU.at(this->_event.key.keysym.sym)))(ret);
    }
  catch (std::out_of_range &err)
    {
    }
  return (eventRet);
}

Ret	Option::_etTextInput(std::pair<std::string, std::string> &ret)
{
  Music	*music;

  (void)ret;
  music = Music::newinstance();
  if (this->_event.text.text[0] == '+')
    *music += 0.01f;
  else if (this->_event.text.text[0] == '-')
    *music -= 0.01f;
  else if (!this->_testSe && this->_event.text.text[0] == 'p')
    {
      this->_rbs[0]->setSelected(!music->getPaused(true));
      music->setPaused(true, !music->getPaused(true));
      this->_rbs[1]->setSelected(!music->getPaused(false));
      music->setPaused(false, !music->getPaused(false));
    }
  return (NOTHING);
}

Ret	Option::_etMouseButtonUp(std::pair<std::string, std::string> &ret)
{
  Music	*music;

  (void)ret;
  if (this->_event.button.button == SDL_BUTTON_LEFT)
    {
      this->_bgmVol->isSelected(false);
      this->_seVol->isSelected(false);
      if (this->_testSe)
	{
	  music = Music::newinstance();
	  this->_testSe = false;
	  this->_repeat = Timeval();
	  music->setPaused(true, this->_sPausedBGM);
	  music->setPaused(false, this->_sPausedSe);
	}
    }
  return (NOTHING);
}

Ret	Option::_etMouseButtonDown(std::pair<std::string, std::string> &ret)
{
  Music	*music;
  int	i;
  int	j;
  int	base;

  (void)ret;
  music = Music::newinstance();
  if (this->_event.button.button == SDL_BUTTON_LEFT)
    {
      if (this->_bgmVol->isClicked(this->_event.button.x, this->_event.button.y))
	this->_bgmVol->isSelected(true);
      else if (this->_seVol->isClicked(this->_event.button.x, this->_event.button.y))
	{
	  this->_sPausedBGM = music->getPaused(true);
	  this->_sPausedSe = music->getPaused(false);
	  music->setPaused(true, true);
	  music->setPaused(false, false);
	  this->_seVol->isSelected(true);
	  this->_testSe = true;
	}
      else
	{
	  i = 0;
	  while (i != static_cast<int>(this->_rbs.size()))
	    {
	      if (this->_rbs[i]->isClicked(this->_event.button.x, this->_event.button.y))
		{
		  if (i == 0 || i == 1)
		    {
		      this->_rbs[i]->setSelected(!this->_rbs[i]->isSelected());
		      if (i == 0)
			music->setPaused(true, this->_rbs[i]->isSelected());
		      else
			music->setPaused(false, this->_rbs[i]->isSelected());
		    }
		  else if (this->_rbs[i]->isSelected() == false)
		    {
		      this->_rbs[i]->setSelected(true);
		      j = (i - 1) % 3;
		      base = i - (i - 2) % 3;
		      while (base + j != i)
			{
			  this->_rbs[base + j]->setSelected(false);
			  j++;
			  j %= 3;
			}
		    }
		}
	      i++;
	    }
	}
    }
  return (NOTHING);
}

Ret	Option::_etMouseMotion(std::pair<std::string, std::string> &ret)
{
  size_t	tmpBGM;
  size_t	tmpSe;
  float		tmp;
  Music		*music;

  (void)ret;
  music = Music::newinstance();
  tmpBGM = this->_bgmVol->getPercent();
  tmpSe = this->_seVol->getPercent();
  this->_bgmVol->mouseMotion(this->_event.motion.x);
  this->_seVol->mouseMotion(this->_event.motion.x);
  if (tmpBGM != this->_bgmVol->getPercent())
    {
      tmp = this->_bgmVol->getPercent();
      tmp /= 100.0f;
      music->changeVolume(true, tmp);
    }
  else if (tmpSe != this->_seVol->getPercent())
    {
      tmp = this->_seVol->getPercent();
      tmp /= 100.0f;
      music->changeVolume(false, tmp);
    }
  return (NOTHING);
}

void	Option::refresh(SDL_Renderer *ren)
{
  Music	*music;
  std::vector<RadioBox *>::iterator	it;
  std::list<TextBox *>::iterator	it2;

  music = Music::newinstance();
  this->_bgmVol->setPercent(music->getVol() * 100);
  this->_bgmVol->refresh(ren);
  this->_seVol->setPercent(music->getVol(false) * 100);
  this->_seVol->refresh(ren);
  it = this->_rbs.begin();
  while (it != this->_rbs.end())
    {
      (*it)->refresh(ren);
      ++it;
    }
  it2 = this->_texts.begin();
  while (it2 != this->_texts.end())
    {
      (*it2)->refresh(ren);
      ++it2;
    }
  if (this->_rbs[0]->isSelected() != music->getPaused(true))
    this->_rbs[0]->setSelected(music->getPaused(true));
  if (this->_rbs[1]->isSelected() != music->getPaused(false))
    this->_rbs[1]->setSelected(music->getPaused(false));
  if (this->_testSe && this->_repeat.cmp(Timeval()) <= 0)
    {
      music->playSound("test", false);
      this->_repeat = Timeval();
      this->_repeat += TS_DELAY;
    }
}

Ret	Option::handleKeys(SDL_Event &event, Map &map, std::pair<std::string, std::string> &ret)
{
  Ret	eventRet;

  (void)map;
  eventRet = NOTHING;
  this->_event = event;
  try
    {
      eventRet = (this->*(this->_eventType.at(this->_event.type)))(ret);
    }
  catch (std::out_of_range &err)
    {
    }
  return (eventRet);
}

