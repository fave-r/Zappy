/*
** my_incantation.c for my_incantation in /home/lopez_t/Zappy/src/client
**
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
**
** Started on  Tue May 12 14:56:11 2015 Thibaut Lopez
** Last update Fri May 22 13:24:48 2015 Thibaut Lopez
*/

#include "server.h"

int	level_1(t_content *cont, t_user *usr)
{
  
}

int	level_2(t_content *cont, t_user *usr)
{
  
}

int	level_3(t_content *cont, t_user *usr)
{
  
}

int	check_this_case(t_user *usr, t_zap *data)
{
  int	(*ptr[7])(t_content*, t_user*);

  ptr[0] = level_1;
  ptr[1] = level_2;
  ptr[2] = level_3;
  ptr[3] = level_4;
  ptr[4] = level_5;
  ptr[5] = level_6;
  ptr[6] = level_7;
}

int	my_incantation(__attribute__((unused)) char **com
		       , t_zap *data, t_user *usr)
{
  check_this_case(usr, data);
  return (0);
}
