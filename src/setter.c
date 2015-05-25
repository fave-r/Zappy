/*
** setter.c for setter in /home/lopez_t/Zappy/src
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Wed May  6 09:02:35 2015 Thibaut Lopez
** Last update Mon May 25 16:27:49 2015 Thibaut Lopez
*/

#include "server.h"

int	set_port(t_zap *data, char *arg, e_state *state)
{
  if (data->port == -1)
    {
      if ((data->port = my_strtol(arg)) == -1)
	fprintf(stderr, "Warning: '-p %s': wrong or negative value.\n", arg);
    }
  else
    {
      fprintf(stderr, "Error: '-p %s': redefinition of port value.\n", arg);
      return (-1);
    }
  *state = NONE;
  return (0);
}

int	set_x(t_zap *data, char *arg, e_state *state)
{
  if (data->length == -1)
    {
      if ((data->length = my_strtol(arg)) <= 0)
	fprintf(stderr, "Warning: -x %s: wrong or negative value.\n", arg);
    }
  else
    {
      fprintf(stderr, "Error: -x %s: redefinition of x value.\n", arg);
      return (-1);
    }
  *state = NONE;
  return (0);
}

int	set_y(t_zap *data, char *arg, e_state *state)
{
  if (data->width == -1)
    {
      if ((data->width = my_strtol(arg)) <= 0)
	fprintf(stderr, "Warning: -y %s: wrong or negative value.\n", arg);
    }
  else
    {
      fprintf(stderr, "Error: -y %s: redefinition of y value.\n", arg);
      return (-1);
    }
  *state = NONE;
  return (0);
}

int	set_count(t_zap *data, char *arg, e_state *state)
{
  if (data->count == -1)
    {
      if ((data->count = my_strtol(arg)) <= 0)
	fprintf(stderr, "Warning: -c %s: wrong or negative value.\n", arg);
    }
  else
    {
      fprintf(stderr, "Error: -c %s: redefinition of count value.\n", arg);
      return (-1);
    }
  *state = NONE;
  return (0);
}

int	set_delay(t_zap *data, char *arg, e_state *state)
{
  if (data->delay == -1)
    {
      if ((data->delay = my_strtol(arg)) <= 0)
	fprintf(stderr, "Warning: -t %s: wrong or negative value.\n", arg);
    }
  else
    {
      fprintf(stderr, "Error: -t %s: redefinition of delay value.\n", arg);
      return (-1);
    }
  *state = NONE;
  return (0);
}
