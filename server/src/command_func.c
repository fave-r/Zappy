/*
** command_func.c for zappy in /home/fave_r/rendu/Zappy/src
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue May 12 17:12:11 2015 romaric
** Last update Sat Jul  4 19:34:16 2015 Thibaut Lopez
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
	  xfill_cb(usr, &usr->wr, com);
	  xpush_q(usr, &usr->queue, NULL, clone_tv);
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
  while (tmp != NULL && tmp->prev != NULL)
    tmp = tmp->prev;
  while (tmp != NULL)
    {
      if (tmp->type == type && tmp->nb == nbr)
	{
	  nbr++;
	  tmp = player;
	  while (tmp != NULL && tmp->prev != NULL)
	    tmp = tmp->prev;
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

void		fill_cell(int i, int x, t_content **map, t_zap *data)
{
  int		j;

  j = -1;
  while (++j < x)
    {
      if (i < data->length && j < data->width)
	{
	  map[i][j].food = data->map[i][j].food;
	  map[i][j].linemate = data->map[i][j].linemate;
	  map[i][j].deraumere = data->map[i][j].deraumere;
	  map[i][j].sibur = data->map[i][j].sibur;
	  map[i][j].mendiane = data->map[i][j].mendiane;
	  map[i][j].phiras = data->map[i][j].phiras;
	  map[i][j].thystame = data->map[i][j].thystame;
	  return ;
	}
      map[i][j].food = rand() % 10;
      map[i][j].linemate = rand() % 8;
      map[i][j].deraumere = rand() % 8;
      map[i][j].sibur = rand() % 6;
      map[i][j].mendiane = rand() % 5;
      map[i][j].phiras = rand() % 4;
      map[i][j].thystame = rand() % 2;
    }
}
