//
// IRefreshable.hh for IRefreshable in /home/lopez_t/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Mon Jun 22 12:17:34 2015 Thibaut Lopez
// Last update Mon Jun 22 13:27:58 2015 Thibaut Lopez
//

#ifndef	IREFRESHABLE_HH
#define	IREFRESHABLE_HH

#include "Map.hh"
#include <SDL2/SDL.h>

typedef	enum	Ret
  {
    NOTHING,
    CHANGE,
    RETURN
  }		Ret;

class	IRefreshable
{
public:
  IRefreshable();
  virtual ~IRefreshable();
  virtual void	refresh(SDL_Renderer *) = 0;
  virtual Ret	handleKeys(SDL_Event &, Map &, std::pair<std::string, std::string> &) = 0;
};

#endif
