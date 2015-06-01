/*
** command_func.c for zappy in /home/fave_r/rendu/Zappy/src
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue May 12 17:12:11 2015 romaric
** Last update Fri May 29 14:20:52 2015 Thibaut Lopez
*/

#include "server.h"

t_user		*in_this_cell(int x, int y, t_user *user)
{
  while (user != NULL)
    {
      if (user->type == AI && GET_X(user) == x && GET_Y(user) == y)
	return (user);
      user = user->next;
    }
  return (NULL);
}

void		send_to_graphic(char *com, t_user *usr, t_tv *when)
{
  while (usr != NULL && usr->prev != NULL)
    usr = usr->prev;
  while (usr != NULL)
    {
      if (usr->type == GRAPHIC)
	{
	  fill_cb(&usr->wr, com, strlen(com));
	  push_q(&usr->queue, when, clone_tv);
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
