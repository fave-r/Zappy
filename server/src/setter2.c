/*
** setter2.c for setter2 in /home/lopez_t/Zappy/server/src
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Sat Jul  4 14:15:01 2015 Thibaut Lopez
** Last update Sat Jul  4 14:20:48 2015 Thibaut Lopez
*/

#include "server.h"

int	set_verbose(t_zap *data, char *arg, e_state *state)
{
  if (strcmp(arg, "yes") == 0 || strcmp(arg, "y") == 0)
    data->verbose = 1;
  else if (strcmp(arg, "no") == 0 || strcmp(arg, "n") == 0)
    data->verbose = 0;
  else
    fprintf(stderr, "Warning: '-v %s': %s not a good answer.\n", arg, arg);
  *state = NONE;
  return (0);
}

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

int		set_team(t_zap *data, char *arg, e_state *state)
{
  (void)state;
  if (strlen(arg) < 200 && strcmp(arg, "GRAPHIC") != 0 &&
      my_strchr(arg, ' ') == -1)
    {
      if ((data->teams = team_cat(data->teams, strdup(arg))) == NULL)
	return (-1);
    }
  else
    {
      fprintf(stderr, "Warning: %s: ", arg);
      if (strlen(arg) >= 200)
	fprintf(stderr, "Team name too long\n");
      else
	fprintf(stderr, "Team name not allowed\n");
    }
  return (0);
}
