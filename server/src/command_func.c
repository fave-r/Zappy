/*
** command_func.c for zappy in /home/fave_r/rendu/Zappy/src
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue May 12 17:12:11 2015 romaric
** Last update Mon Jun 15 18:24:22 2015 Thibaut Lopez
*/

#include "server.h"

t_user		*in_this_cell(int x, int y, t_user *user)
{
  while (user != NULL)
    {
      if (user->type == AI && GET_X(user) == x &&
	  GET_Y(user) == y && GET_GHOST(user) == 0)
	return (user);
      user = user->next;
    }
  return (NULL);
}

void		send_to_graphic(char *com, t_user *usr)
{
  while (usr != NULL && usr->prev != NULL)
    usr = usr->prev;
  while (usr != NULL)
    {
      if (usr->type == GRAPHIC)
	{
	  fill_cb(&usr->wr, com, strlen(com));
	  push_q(&usr->queue, NULL, clone_tv);
	}
      usr = usr->next;
    }
}

int		find_nb(t_user *player, e_clt type)
{
  t_user	*tmp;
  int		nbr;

  nbr = 0;
  tmp = player;
  while (tmp != NULL)
    {
      if (tmp->type == type && tmp->nb == nbr)
	{
	  nbr++;
	  tmp = player;
	}
      else
	tmp = tmp->next;
    }
  return (nbr);
}

int		find_egg_nb(t_team *teams)
{
  t_team	*tmp;
  t_que		*eggs;
  t_egg		*egg;
  int		nbr;

  nbr = 0;
  tmp = teams;
  while (tmp != NULL)
    {
      eggs = tmp->eggs;
      while (eggs != NULL)
	{
	  egg = front_q(eggs);
	  if (egg->nb == nbr)
	    {
	      nbr++;
	      tmp = teams;
	      eggs = tmp->eggs;
	    }
	  else
	    eggs = eggs->next;
	}
      tmp = tmp->next;
    }
  return (nbr);
}

void		fill_cell(int x, int y, t_content **map, t_zap *data)
{
  if (x < data->length && y < data->width)
    {
      map[x][y].food = data->map[x][y].food;
      map[x][y].linemate = data->map[x][y].linemate;
      map[x][y].deraumere = data->map[x][y].deraumere;
      map[x][y].sibur = data->map[x][y].sibur;
      map[x][y].mendiane = data->map[x][y].mendiane;
      map[x][y].phiras = data->map[x][y].phiras;
      map[x][y].thystame = data->map[x][y].thystame;
      return ;
    }
  map[x][y].food = rand() % 10;
  map[x][y].linemate = rand() % 8;
  map[x][y].deraumere = rand() % 8;
  map[x][y].sibur = rand() % 6;
  map[x][y].mendiane = rand() % 5;
  map[x][y].phiras = rand() % 4;
  map[x][y].thystame = rand() % 2;
}
