/*
** my_mct.c for my_mct in /home/lopez_t/Zappy/src/mct
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Thu May 14 01:07:32 2015 Thibaut Lopez
** Last update Thu May 14 11:28:52 2015 Thibaut Lopez
*/

#include "server.h"

int	my_mct(char **com, t_zap *data, t_user *usr)
{
  int	x;
  int	y;

  (void)com;
  y = 0;
  while (y < data->width)
    {
      x = 0;
      while (x < data->length)
	{
	  my_send_bct(data, usr, x, y);
	  x++;
	}
      y++;
    }
  return (0);
}
