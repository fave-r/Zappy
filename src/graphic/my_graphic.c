/*
** my_graphic.c for my_graphic in /home/lopez_t/Zappy/src/graphic
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Thu May 14 01:07:32 2015 Thibaut Lopez
** Last update Thu May 14 01:37:02 2015 Thibaut Lopez
*/

#include "server.h"

int	my_graphic(char **com, t_zap *data, t_user *usr)
{
  (void)com;
  (void)data;
  usr->type = GRAPHIC;
  return (0);
}
