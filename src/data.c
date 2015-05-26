/*
** data.c for data in /home/lopez_t/Zappy/src
**
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
**
** Started on  Tue May 12 10:39:02 2015 Thibaut Lopez
** Last update Tue May 26 15:06:46 2015 Thibaut Lopez
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
	  data->map[i][j].food = rand() % 10;
	  data->map[i][j].linemate = rand() % 8;
	  data->map[i][j].deraumere = rand() % 8;
	  data->map[i][j].sibur = rand() % 6;
	  data->map[i][j].mendiane = rand() % 5;
	  data->map[i][j].phiras = rand() % 4;
	  data->map[i][j].thystame = rand() % 2;
	}
    }
  printf("Information about the server:\nPort: %d\nMap of %dx%d cells\n\
Player max per team: %d\nDelay for each action: %d\nName of each team\n",
	 data->port, data->length, data->width, data->count, data->delay);
  putsstr(1, data->team);
}

int	base_value(t_zap *data)
{
  int	i;
  int	c;

  data->port = (data->port == -1) ? 6667 : data->port;
  data->length = (data->length == -1) ? 100 : data->length;
  data->width = (data->width == -1) ? 100 : data->width;
  if (data->team == NULL || sstrlen(data->team) < 2)
    {
      if (data->team != NULL)
	sfree(data->team);
      data->team = xmalloc(3 * sizeof(char *));
      data->team[0] = xstrdup("TeamA");
      data->team[1] = xstrdup("TeamB");
      data->team[2] = NULL;
    }
  data->count = (data->count == -1) ? 20 : data->count;
  c = sstrlen(data->team);
  data->counts = xmalloc(c * sizeof(int));
  i = -1;
  while (++i < c)
    data->counts[i] = data->count;
  data->delay = (data->delay == -1) ? 100 : data->delay;
  init_map(data);
  return (0);
}

void	init_val(t_zap *data)
{
  data->port = -1;
  data->map = NULL;
  data->length = -1;
  data->width = -1;
  data->team = NULL;
  data->count = -1;
  data->counts = NULL;
  data->delay = -1;
  data->end = NULL;
  data->winner = NULL;
}

void	free_zap(t_zap *data)
{
  int	i;

  i = 0;
  while (i < data->width)
    {
      free(data->map[i]);
      i++;
    }
  free(data->map);
  sfree(data->team);
}
