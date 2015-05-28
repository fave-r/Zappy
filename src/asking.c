/*
** asking.c for asking in /home/lopez_t/BONUS/Zappy
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Thu May 28 13:49:58 2015 Thibaut Lopez
** Last update Thu May 28 14:22:42 2015 Thibaut Lopez
*/

#include "server.h"

int	set_asking(t_zap *data, char *arg, e_state *state)
{
  if (data->asking == -1)
    {
      if ((data->asking = my_strtof(arg)) == -1)
	fprintf(stderr, "Warning: '-a %s': wrong or negative value.\n", arg);
    }
  else
    {
      fprintf(stderr, "Error: '-a %s': redefinition of asking value.\n", arg);
      return (-1);
    }
  *state = NONE;
  return (0);
}
