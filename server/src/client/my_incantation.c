/*
** my_incantation.c for my_incantation in /home/lopez_t/Zappy/src/client
**
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
**
** Started on  Tue May 12 14:56:11 2015 Thibaut Lopez
** Last update Wed Jun 10 19:47:35 2015 Thibaut Lopez
*/

#include "server.h"

int		level_1(t_content *cont, t_user *usr, int is_casting)
{
  if (cont->linemate >= 1)
    {
      if (check_nb_in_cell(is_casting, usr) >= 1)
	{
	  if (is_casting == 1)
	    cont->linemate -= 1;
	  return (1);
	}
    }
  return (0);
}

int		level_2(t_content *cont, t_user *usr, int is_casting)
{
  if (cont->linemate >= 1 && cont->deraumere >= 1 && cont->sibur >= 1)
    {
      if (check_nb_in_cell(is_casting, usr) >= 2)
	{
	  if (is_casting == 1)
	    {
	      cont->linemate -= 1;
	      cont->deraumere -= 1;
	      cont->sibur -= 1;
	    }
	  return (1);
	}
    }
  return (0);
}

int		level_3(t_content *cont, t_user *usr, int is_casting)
{
  if (cont->linemate >= 2 && cont->sibur >= 1 && cont->phiras >= 2)
    {
      if (check_nb_in_cell(is_casting, usr) >= 2)
	{
	  if (is_casting == 1)
	    {
	      cont->linemate -= 2;
	      cont->sibur -= 1;
	      cont->phiras -= 2;
	    }
	  return (1);
	}
    }
  return (0);
}

int		check_this_case(t_user *usr, t_zap *data, int is_casting)
{
  int		(*ptr[7])(t_content*, t_user*, int);

  ptr[0] = level_1;
  ptr[1] = level_2;
  ptr[2] = level_3;
  ptr[3] = level_4;
  ptr[4] = level_5;
  ptr[5] = level_6;
  ptr[6] = level_7;
  if (GET_LVL(usr) == 8)
    return (0);
  return (ptr[GET_LVL(usr) - 1](&data->map[GET_X(usr)][GET_Y(usr)],
				usr, is_casting));
}

int		my_incantation(char **com, t_zap *data, t_user *usr)
{
  t_user	*tmp;
  t_tv		now;

  if (sstrlen(com) != 1 || check_this_case(usr, data, 0) == 0)
    {
      fill_cb(&usr->wr, "ko\n", 3);
      return (-1);
    }
  tmp = usr;
  send_elev_in(usr);
  while (tmp->prev != NULL)
    tmp = tmp->prev;
  gettimeofday(&now, NULL);
  add_tv(&now, 300000000 / data->delay);
  while ((tmp = in_this_cell(GET_X(usr), GET_Y(usr), tmp)) != NULL)
    {
      if (GET_LVL(usr) == GET_LVL(tmp) && !IS_CASTING(tmp))
	{
	  fill_cb(&tmp->wr, "elevation en cours\n", 19);
	  GET_CAST(tmp).tv_sec = now.tv_sec;
	  GET_CAST(tmp).tv_usec = now.tv_usec;
	}
      tmp = tmp->next;
    }
  return (0);
}
