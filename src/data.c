/*
** data.c for data in /home/lopez_t/Zappy/src
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Tue May 12 10:39:02 2015 Thibaut Lopez
** Last update Tue May 12 10:56:57 2015 Thibaut Lopez
*/

#include "server.h"

void	init_map(t_zap *data)
{
  int	i;
  int	j;

  data->map = xmalloc(data->width * sizeof(t_content *));
  i = -1;
  while (++i < data->width)
    {
      data->map[i] = malloc(data->length * sizeof(t_content));
      j = -1;
      while (++j < data->length)
	{
	  data->map[i][j].food = 0;
	  data->map[i][j].linemate = 0;
	  data->map[i][j].deraumere = 0;
	  data->map[i][j].sibur = 0;
	  data->map[i][j].mendiane = 0;
	  data->map[i][j].phiras = 0;
	  data->map[i][j].thystame = 0;
	}
    }
  printf("Information about the server:\nPort: %d\nMap of %dx%d cells\n\
Player max per team: %d\nDelay for each action: %d\nName of each team\n",
	 data->port, data->length, data->width, data->count, data->delay);
  putsstr(1, data->team);
}

int	base_value(t_zap *data)
{
  if (data->port == -1)
    data->port = 6667;
  if (data->length == -1)
    data->length = 100;
  if (data->width == -1)
    data->width = 100;
  if (data->team == NULL || sstrlen(data->team) < 2)
    {
      if (data->team != NULL)
	sfree(data->team);
      data->team = xmalloc(3 * sizeof(char *));
      data->team[0] = xstrdup("TeamA");
      data->team[1] = xstrdup("TeamB");
      data->team[2] = NULL;
    }
  if (data->count == -1)
    data->count = 20;
  if (data->delay == -1)
    data->delay = 100;
  init_map(data);
  return (0);
}

void	init_val(t_zap *data)
{
  data->port = -1;
  data->length = -1;
  data->width = -1;
  data->team = NULL;
  data->count = -1;
  data->delay = -1;
}
