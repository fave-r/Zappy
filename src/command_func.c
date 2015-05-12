/*
** command_func.c for zappy in /home/fave_r/rendu/Zappy/src
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue May 12 17:12:11 2015 romaric
** Last update Tue May 12 17:20:44 2015 romaric
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
      if (tmp->team != NULL)
	{
	  if (strcmp(tmp->team, team_name) == 0)
	    i++;
	}
      tmp = tmp->next;
    }
  return (i);
}
