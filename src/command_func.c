/*
** command_func.c for zappy in /home/fave_r/rendu/Zappy/src
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue May 12 17:12:11 2015 romaric
** Last update Thu May 14 01:49:29 2015 Thibaut Lopez
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
	  if (strcmp(tmp->team, team_name) == 0)
	    i++;
	}
      tmp = tmp->next;
    }
  return (i);
}

t_user		*in_this_cell(int x, int y, t_user *user)
{
  t_user	*tmp;

  tmp = user;
  while (tmp->prev != NULL)
    tmp = tmp->prev;
  while (tmp != NULL)
    {
      if (tmp->type == AI && tmp->x == x && tmp->y == y)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}
