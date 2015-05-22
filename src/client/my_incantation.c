/*
** my_incantation.c for my_incantation in /home/lopez_t/Zappy/src/client
**
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
**
** Started on  Tue May 12 14:56:11 2015 Thibaut Lopez
** Last update Fri May 22 19:58:29 2015 romaric
*/

#include "server.h"

int		level_1(t_content *cont, t_user *usr, int is_casting)
{
  if (cont->linemate >= 1)
    {
      if (check_nb_in_cell(is_casting, usr) >= 1)
	return (1);
    }
  return (0);
}

int	level_2(t_content *cont, t_user *usr, int is_casting)
{
  if (cont->linemate >= 1 && cont->deraumere >= 1 && cont->sibur >= 1)
    {
      if (check_nb_in_cell(is_casting, usr) >= 2)
	return (1);
    }
  return (0);
}

int	level_3(t_content *cont, t_user *usr, int is_casting)
{
  if (cont->linemate >= 2 && cont->sibur >= 1 && cont->phiras >= 2)
    {
      if (check_nb_in_cell(is_casting, usr) >= 2)
	return (1);
    }
  return (0);
}

int	check_this_case(t_user *usr, t_zap *data, int is_casting)
{
  int	(*ptr[7])(t_content*, t_user*, int);

  ptr[0] = level_1;
  ptr[1] = level_2;
  ptr[2] = level_3;
  ptr[3] = level_4;
  ptr[4] = level_5;
  ptr[5] = level_6;
  ptr[6] = level_7;
  if (GET_LVL(usr) == 8)
    return (0);
  return (ptr[GET_LVL(usr) - 1](&data->map[GET_X(usr)][GET_Y(usr)], usr, is_casting));
}

int	my_incantation(char **com, t_zap *data, t_user *usr)
{
  if (sstrlen(com) != 1)
    {
      fill_cb(&usr->wr, "ko\n", 3);
      return (-1);
    }
  check_this_case(usr, data, 0);
  return (0);
}
