/*
** command_func.c for zappy in /home/fave_r/rendu/Zappy/src
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue May 12 17:12:11 2015 romaric
** Last update Fri May 22 18:17:35 2015 Thibaut Lopez
*/

#include "server.h"

int		count_in_team(char *team_name, t_user *user)
{
  t_user	*tmp;
  int		i;

  tmp = user;
  while (tmp->prev != NULL)
    tmp = tmp->prev;
  i = 0;
  while (tmp != NULL)
    {
      if (tmp->type == AI)
	{
	  if (strcmp(GET_TEAM(tmp), team_name) == 0)
	    i++;
	}
      tmp = tmp->next;
    }
  return (i);
}

int		team_winning(t_user *usr, char *team)
{
  int		nb;

  nb = 0;
  while (usr != NULL && usr->prev != NULL)
    usr = usr->prev;
  while (usr != NULL)
    {
      if (usr->type == AI &&
	  strcmp(GET_TEAM(usr), team) == 0 && GET_LVL(usr) == 8)
	nb++;
      usr = usr->next;
    }
  return ((nb == count_in_team(team, usr)) ? 1 : 0);
}

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
	  push_q(&usr->queue, when);
	}
      usr = usr->next;
    }
}

int		find_nb(t_user *player)
{
  t_user	*tmp;
  int		nbr;

  nbr = 0;
  tmp = player;
  while (tmp != NULL)
    {
      if (tmp->type == AI && GET_NB(tmp) == nbr)
	{
	  nbr++;
	  tmp = player;
	}
      else
	tmp = tmp->next;
    }
  return (nbr);
}
