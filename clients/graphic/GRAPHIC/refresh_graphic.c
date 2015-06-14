/*
** refresh_graphic.c for refresh_graphic in /home/thibaut.lopez/Corewar/Corewar/vm/Graphic
**
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
**
** Started on  Wed Mar 19 09:40:14 2014 Thibaut Lopez
<<<<<<< HEAD
** Last update Mon Apr 28 23:57:42 2014 Thibaut Lopez
=======
** Last update Sun Apr 13 19:24:01 2014 romaric
>>>>>>> 19677e7912d8e528a11ae947fa7a4281d20f824f
*/

#include "vm.h"
#include "my.h"

int		my_pause()
{
  int		wait;
  SDL_Event	event;

  wait = 0;
  while (wait == 0)
    {
      SDL_WaitEvent(&event);
      if (event.key.keysym.sym == SDLK_ESCAPE)
	return (1);
      else if (event.key.keysym.sym == SDLK_SPACE &&
	       event.type == SDL_KEYDOWN)
	wait = 1;
    }
  return (0);
}

int		get_escape(t_cor *cor)
{
  SDL_Event	event;

  (void)cor;
  if (SDL_PollEvent(&event) &&
      (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP))
    {
      if (event.key.keysym.sym == SDLK_ESCAPE)
	return (1);
      else if (event.key.keysym.sym == SDLK_SPACE && event.type == SDL_KEYDOWN)
	if (my_pause() == 1)
	  return (1);
    }
  return (0);
}

void		put_dump(t_sdl *cor, int dump)
{
  char		*tmp;
  SDL_Rect	position;
  SDL_Color	color;

  position.x = 700;
  position.y = 115;
  color.r = 255;
  color.g = 255;
  color.b = 255;
  cor->dump[0] = TTF_RenderText_Blended(cor->font, "DUMP = ", color);
  SDL_BlitSurface(cor->dump[0], NULL, cor->screen, &position);
  tmp = (dump >= 240000) ? my_strdup("NONE") : my_nbr_to_char(dump);
  position.x += position.w;
  cor->dump[1] = TTF_RenderText_Solid(cor->font, tmp, color);
  free(tmp);
  SDL_BlitSurface(cor->dump[1], NULL, cor->screen, &position);
}

void		change_case_mem(int case_mem, Uint32 color, t_sdl *cor)
{
  int		i;
  SDL_Rect	position;

  i = 0;
  position.w = 10;
  position.h = 20;
  while (i < 4)
    {
      position.x = mod_mem(case_mem + i) % 149 * 10;
      position.y = mod_mem(case_mem + i) / 149 * 20;
      SDL_FillRect(cor->arena, &position, color);
      i++;
    }
  position.x = 20;
  position.y = 150;
  SDL_BlitSurface(cor->arena, NULL, cor->screen, &position);
  SDL_Flip(cor->screen);
}
