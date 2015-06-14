/*
** information.c for information in /home/thibaut.lopez/Corewar/Corewar/vm
**
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
**
** Started on  Sat Apr 12 22:20:42 2014 Thibaut Lopez
** Last update Sun Apr 13 19:22:45 2014 romaric
*/

#include "my.h"
#include "vm.h"

SDL_Color	init_white_color()
{
  SDL_Color	color;

  color.r = 255;
  color.g = 255;
  color.b = 255;
  return (color);
}

void		refresh_cycle(t_cor *cor, int cycle_done)
{
  char		*tmp;
  SDL_Color	color;

  color = init_white_color();
  tmp = my_nbr_to_char(cor->cycle);
  cor->graphic.cycle[1] = TTF_RenderText_Solid(cor->graphic.font, tmp, color);
  free(tmp);
  if (cor->graphic.bg != NULL)
    SDL_BlitSurface(cor->graphic.bg, &cor->graphic.cycle_pos,
		    cor->graphic.screen, &cor->graphic.cycle_pos);
  else
    SDL_FillRect(cor->graphic.screen, &cor->graphic.cycle_pos, 0x9B9B9B);
  SDL_BlitSurface(cor->graphic.cycle[1], NULL,
		  cor->graphic.screen, &cor->graphic.cycle_pos);
  tmp = my_nbr_to_char(cycle_done);
  cor->graphic.c_done[1] = TTF_RenderText_Solid(cor->graphic.font, tmp, color);
  free(tmp);
  if (cor->graphic.bg != NULL)
    SDL_BlitSurface(cor->graphic.bg, &cor->graphic.c_done_pos,
		    cor->graphic.screen, &cor->graphic.c_done_pos);
  else
    SDL_FillRect(cor->graphic.screen, &cor->graphic.c_done_pos, 0x9B9B9B);
  SDL_BlitSurface(cor->graphic.c_done[1], NULL,
		  cor->graphic.screen, &cor->graphic.c_done_pos);
  SDL_Flip(cor->graphic.screen);
}

void		refresh_ctd(t_cor *cor)
{
  char		*tmp;
  SDL_Color	color;
  int		keep;

  color = init_white_color();
  tmp = my_nbr_to_char(cor->cycle_to_die);
  cor->graphic.ctd[1] = TTF_RenderText_Solid(cor->graphic.font, tmp, color);
  free(tmp);
  if (cor->graphic.bg != NULL)
    SDL_BlitSurface(cor->graphic.bg, &cor->graphic.ctd_pos,
		    cor->graphic.screen, &cor->graphic.ctd_pos);
  else
    SDL_FillRect(cor->graphic.screen, &cor->graphic.ctd_pos,
		 SDL_MapRGB(cor->graphic.screen->format, 150, 150, 150));
  keep = cor->graphic.ctd_pos.w;
  SDL_BlitSurface(cor->graphic.ctd[1], NULL,
		  cor->graphic.screen, &cor->graphic.ctd_pos);
  cor->graphic.ctd_pos.w = keep;
  SDL_Flip(cor->graphic.screen);
}

void		save_information(SDL_Rect *src, SDL_Rect *dest,
				 SDL_Surface *to_blit, SDL_Surface *screen)
{
  SDL_BlitSurface(to_blit, NULL, screen, src);
  src->x += src->w;
  dest->x = src->x;
  dest->y = src->y;
  dest->w = src->w;
  dest->h = src->h;
  src->x -= src->w;
}

void		init_information(t_sdl *cor)
{
  char		*tmp;
  SDL_Color	color;
  SDL_Rect	position;

  color = init_white_color();
  position.x = 700;
  position.y = 10;
  cor->ctd[0] = TTF_RenderText_Blended(cor->font,
				       "CYCLE_TO_DIE = ", color);
  save_information(&(position), &(cor->ctd_pos), cor->ctd[0], cor->screen);
  tmp = my_nbr_to_char(CYCLE_TO_DIE);
  cor->ctd[1] = TTF_RenderText_Solid(cor->font, tmp, color);
  free(tmp);
  SDL_BlitSurface(cor->ctd[1], NULL, cor->screen, &(cor->ctd_pos));
  position.y += 35;
  cor->cycle[0] = TTF_RenderText_Blended(cor->font, "CYCLE = ", color);
  save_information(&(position), &(cor->cycle_pos), cor->cycle[0], cor->screen);
  cor->cycle[1] = TTF_RenderText_Solid(cor->font, "0", color);
  SDL_BlitSurface(cor->cycle[1], NULL, cor->screen, &(cor->cycle_pos));
  position.y += 35;
  cor->c_done[0] = TTF_RenderText_Blended(cor->font, "CYCLE DONE = ", color);
  save_information(&(position), &(cor->c_done_pos),
		   cor->c_done[0], cor->screen);
  cor->c_done[1] = TTF_RenderText_Solid(cor->font, "0", color);
  SDL_BlitSurface(cor->c_done[1], NULL, cor->screen, &(cor->c_done_pos));
}
