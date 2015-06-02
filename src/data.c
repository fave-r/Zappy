/*
** data.c for data in /home/lopez_t/Zappy/src
**
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
**
** Started on  Tue May 12 10:39:02 2015 Thibaut Lopez
** Last update Tue Jun  2 17:58:30 2015 Thibaut Lopez
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
  put_team(data->teams, 1);
  printf("(Time waiting for a graphic response: %f)\n", data->asking);
}

int	base_value(t_zap *data)
{
  data->port = (data->port == -1) ? 6667 : data->port;
  data->length = (data->length == -1) ? 50 : data->length;
  data->width = (data->width == -1) ? 50 : data->width;
  if (data->teams == NULL || team_len(data->teams) < 2)
    {
      if (data->teams != NULL)
	team_free(data->teams);
      data->teams = base_team();
    }
  data->count = (data->count == -1) ? 20 : data->count;
  team_counts(data->teams, data->count);
  data->delay = (data->delay == -1) ? 100 : data->delay;
  data->asking = (data->asking == -1) ? 7.5 : data->asking;
  init_map(data);
  return (0);
}

void	init_val(t_zap *data)
{
  data->port = -1;
  data->map = NULL;
  data->length = -1;
  data->width = -1;
  data->teams = NULL;
  data->count = -1;
  data->delay = -1;
  data->end = NULL;
  data->winner = NULL;
  data->asking = -1;
  data->end_game.wait.tv_sec = 0;
  data->end_game.wait.tv_usec = 0;
  data->end_game.res = APR;
  data->end_game.ok = my_reset;
  data->end_game.ko = my_endgame;
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
  team_free(data->teams);
}
