/*
** my_graphic.c for my_graphic in /home/lopez_t/Zappy/src/graphic
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Thu May 14 01:07:32 2015 Thibaut Lopez
** Last update Fri May 29 17:37:55 2015 Thibaut Lopez
*/

#include "server.h"

void		my_enw(t_zap *data, t_user *usr)
{
  t_team	*tmp;
  t_que		*eggs;
  t_egg		*egg;
  char		str[64];

  tmp = data->teams;
  while (tmp != NULL)
    {
      eggs = tmp->eggs;
      while (eggs != NULL)
	{
	  egg = front_q(eggs);
	  bzero(str, 64);
	  sprintf(str, "enw #%d #%d %d %d\n",
		  egg->nb, egg->dad, egg->pos.f, egg->pos.s);
	  fill_cb(&usr->wr, str, strlen(str));
	  eggs = eggs->next;
	}
      tmp = tmp->next;
    }
}

int		my_graphic(char **com, t_zap *data, t_user *usr)
{
  t_user	*tmp;

  if (sstrlen(com) != 1)
    return (0);
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
  my_enw(data, usr);
  my_agt(com, data, usr);
  usr->nb = find_nb(usr, GRAPHIC);
  usr->type = GRAPHIC;
  return (0);
}
