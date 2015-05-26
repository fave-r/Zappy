/*
** command_func.c for zappy in /home/fave_r/rendu/Zappy/src
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue May 12 17:12:11 2015 romaric
** Last update Tue May 26 18:36:55 2015 Thibaut Lopez
*/

#include "server.h"

int		count_in_team(t_team *team_name, t_user *user)
{
  t_user	*tmp;
  int		i;

  tmp = user;
  while (tmp != NULL && tmp->prev != NULL)
    tmp = tmp->prev;
  i = 0;
  while (tmp != NULL)
    {
      if (tmp->type == AI && GET_TEAM(tmp) == team_name)
	i++;
      tmp = tmp->next;
    }
  return (i);
}

int		team_winning(t_user *usr, t_team *team)
{
  t_user	*tmp;
  int		nb;

  tmp = usr;
  nb = 0;
  while (tmp != NULL && tmp->prev != NULL)
    tmp = tmp->prev;
  while (tmp != NULL)
    {
      if (tmp->type == AI && GET_TEAM(tmp) == team && GET_LVL(tmp) == 8)
	nb++;
      tmp = tmp->next;
    }
  return ((nb != 0 && nb == count_in_team(team, usr)) ? 1 : 0);
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
	  push_q(&usr->queue, when, clone_tv);
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
