/*
** my_graphic.c for my_graphic in /home/lopez_t/Zappy/src/graphic
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Thu May 14 01:07:32 2015 Thibaut Lopez
** Last update Thu Jul  2 04:31:56 2015 Thibaut Lopez
*/

#include "server.h"

void		my_enw(t_zap *data, t_user *usr)
{
  t_team	*tmp;
  t_que		*eggs;
  t_egg		*egg;
  char		str[64];

  tmp = data->teams;
  while (tmp != NULL)
    {
      eggs = tmp->eggs;
      while (eggs != NULL)
	{
	  egg = front_q(eggs);
	  bzero(str, 64);
	  sprintf(str, "enw #%d #%d %d %d\n",
		  egg->nb, egg->dad, egg->pos.f, egg->pos.s);
	  fill_cb(&usr->wr, str, strlen(str));
	  eggs = eggs->next;
	}
      tmp = tmp->next;
    }
}

int		my_graphic(char **com, t_zap *data, t_user *usr)
{
  t_user	*tmp;

  if (sstrlen(com) != 1)
    return (0);
  my_msz(com, data, usr);
  my_sgt(com, data, usr);
  my_mct(com, data, usr);
  my_tna(com, data, usr);
  tmp = usr;
  while (tmp->prev != NULL)
    tmp = tmp->prev;
  while (tmp != NULL)
    {
      if (tmp->type == AI)
	my_pnw(usr, tmp);
      tmp = tmp->next;
    }
  my_enw(data, usr);
  my_agt(com, data, usr);
  usr->nb = find_nb(usr, GRAPHIC);
  usr->type = GRAPHIC;
  return (0);
}

void		my_reset(t_ask *ask, t_user *usr, t_zap *data)
{
  char		**com;

  (void)ask;
  com = malloc(2 * sizeof(char *));
  com[0] = "GRAPHIC";
  com[1] = NULL;
  my_graphic(com, data, usr);
  free(com);
}

void		my_endgame(t_ask *ask, t_user *usr, t_zap *data)
{
  char		tmp[256];

  (void)ask;
  bzero(tmp, 256);
  sprintf(tmp, "seg %s\n", data->win->name);
  fill_cb(&usr->wr, tmp, strlen(tmp));
  while (cb_taken(&usr->wr) > 0)
    write_cb(&usr->wr, usr->fd, NULL);
}

void		my_reset_map(t_user **usr, t_zap *data, t_ask *ask)
{
  int		i;
  int		j;

  (void)usr;
  (void)ask;
  i = -1;
  while (++i < data->width)
    {
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
