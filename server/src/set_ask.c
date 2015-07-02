/*
** set_ask.c for set_ask in /home/lopez_t/Zappy/server
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Thu Jul  2 04:13:52 2015 Thibaut Lopez
** Last update Thu Jul  2 04:39:26 2015 Thibaut Lopez
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

int	set_wait(t_zap *data, char *arg, e_state *state)
{
  if (strcmp(arg, "yes") == 0 || strcmp(arg, "y") == 0)
    data->wait = 0;
  else if (strcmp(arg, "no") == 0 || strcmp(arg, "n") == 0)
    data->wait = 1;
  else
    fprintf(stderr, "Warning: '-w %s': %s not a good answer.\n", arg, arg);
  *state = NONE;
  return (0);
}
