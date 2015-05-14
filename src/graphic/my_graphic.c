/*
** my_graphic.c for my_graphic in /home/lopez_t/Zappy/src/graphic
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Thu May 14 01:07:32 2015 Thibaut Lopez
** Last update Thu May 14 12:19:50 2015 Thibaut Lopez
*/

#include "server.h"

int		my_graphic(char **com, t_zap *data, t_user *usr)
{
  t_user	*tmp;

  (void)com;
  my_msz(com, data, usr);
  my_sgt(com, data, usr);
  my_mct(com, data, usr);
  my_tna(com, data, usr);
  tmp = usr;
  while (tmp->prev != NULL)
    tmp = tmp->prev;
  while (tmp != NULL)
    {
      if (tmp->type == AI)
	my_pnw(usr, tmp);
      tmp = tmp->next;
    }
  usr->type = GRAPHIC;
  return (0);
}
