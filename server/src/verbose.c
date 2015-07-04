/*
** verbose.c for verbose in /home/lopez_t/Zappy/server
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Thu Jul  2 15:37:29 2015 Thibaut Lopez
** Last update Sat Jul  4 13:54:52 2015 Thibaut Lopez
*/

#include "server.h"

void	verbose_receive(t_user *usr, char *rec, t_zap *data)
{
  if (data->verbose == 0)
    return ;
  verbose_base(usr, "\033[35m");
  printf(" send '%s'\n", rec);
  if (isatty(1))
    printf("\033[0m");
  printf("\n");
}

void	verbose_send(t_user *usr, char *to_send, t_zap *data)
{
  if (data->verbose == 0)
    return ;
  verbose_base(usr, "\033[33m");
  printf(" will receive '%s'\n", to_send);
  if (isatty(1))
    printf("\033[0m");
  printf("\n");
}

void	verbose_eat(t_user *usr, int x, int y, t_zap *data)
{
  if (data->verbose == 0)
    return ;
  verbose_base(usr, "\033[34m");
  printf(" ate (%d food left). Food added at %dx%d\n",
	 GET_INV(usr).food, x, y);
  if (isatty(1))
    printf("\033[0m");
  printf("\n");
}

void	verbose_new(t_user *usr, int is_hatching, e_clt type, t_zap *data)
{
  char		*stype;

  if (data->verbose == 0)
    return ;
  verbose_base(usr, "\033[32m");
  stype = (type == UNKNOWN) ? "unknown" : (type == AI) ? "AI" : "GUI";
  printf(" is now a %s.", stype);
  if (is_hatching != -1)
    printf(" He hatched from an egg at %dx%d.", GET_X(usr), GET_Y(usr));
  if (isatty(1))
    printf("\033[0m");
  printf("\n\n");
}

void	verbose_death(t_user *usr, t_zap *data)
{
  if (data->verbose == 0)
    return ;
  verbose_base(usr, "\033[31m");
  printf(" is dead\n");
  if (isatty(1))
    printf("\033[0m");
  printf("\n");
}
