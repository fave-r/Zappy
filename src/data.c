/*
** data.c for data in /home/lopez_t/Zappy/src
**
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
**
** Started on  Tue May 12 10:39:02 2015 Thibaut Lopez
** Last update Tue May 12 11:18:12 2015 romaric
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
  i = -1;
  while (++i < data->width)
    {
      j = -1;
      while (++j < data->width)
	printf("%d %d %d %d %d %d %d\n", data->map[i][j].food, data->map[i][j].linemate, data->map[i][j].deraumere, data->map[i][j].sibur, data->map[i][j].mendiane, data->map[i][j].phiras, data->map[i][j].thystame);
    }
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
