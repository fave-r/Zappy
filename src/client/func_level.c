/*
** func_level.c for zappy in /home/fave_r/rendu/Zappy/src/client
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Fri May 22 13:37:47 2015 romaric
** Last update Fri May 22 19:54:31 2015 romaric
*/

#include "server.h"

int	level_4(t_content *cont, t_user *usr, int is_casting)
{
  if (cont->linemate >= 1 && cont->deraumere >= 1
      && cont->sibur >= 2 && cont->phiras >= 1)
    {
      if (check_nb_in_cell(is_casting, usr) >= 4)
        return (1);
    }
  return (0);
}

int	level_5(t_content *cont, t_user *usr, int is_casting)
{
  if (cont->linemate >= 1 && cont->deraumere >= 2
      && cont->sibur >= 1 && cont->mendiane >= 3)
    {
      if (check_nb_in_cell(is_casting, usr) >= 4)
        return (1);
    }
  return (0);
}

int	level_6(t_content *cont, t_user *usr, int is_casting)
{
  if (cont->linemate >= 1 && cont->deraumere >= 2
      && cont->sibur >= 3 && cont->phiras >= 1)
    {
      if (check_nb_in_cell(is_casting, usr) >= 6)
        return (1);
    }
  return (0);
}

int	level_7(t_content *cont, t_user *usr, int is_casting)
{
  if (cont->linemate >= 2 && cont->deraumere >= 2
      && cont->sibur >= 2 && cont->mendiane >= 2
      && cont->phiras >= 2 && cont->thystame >= 1)
    {
      if (check_nb_in_cell(is_casting, usr) >= 6)
        return (1);
    }
  return (0);
}

int		check_nb_in_cell(int is_casting, t_user *usr)
{
  t_user	*tmp;
  int		i;

  i = 0;
  tmp = usr;
  while (tmp->prev != NULL)
    tmp = tmp->prev;
  while ((tmp = in_this_cell(GET_X(usr), GET_Y(usr), tmp)) != NULL)
    {
      if (is_casting == 0)
	{
	  if (GET_LVL(usr) == GET_LVL(tmp) && cmp_tv(&GET_TIME(usr), &GET_TIME(tmp)) == 0)
	    i++;
	}
      else
	{
	  if (GET_LVL(usr) == GET_LVL(tmp) && !IS_CASTING(tmp))
	    i++;
	}
      tmp = tmp->next;
    }
  return (i);
}
