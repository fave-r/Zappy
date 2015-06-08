/*
** my_apr.c for apr in /home/lopez_t/BONUS/Zappy/src/graphic
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Fri May 29 15:07:54 2015 Thibaut Lopez
** Last update Wed Jun  3 10:37:11 2015 Thibaut Lopez
*/

#include "server.h"

t_ask		*get_asking(t_user *usr, int ig, int ask_nb)
{
  t_user	*tmp;
  t_que		*q;
  int		i;

  tmp = usr;
  while (tmp != NULL && tmp->prev != NULL)
    tmp = tmp->prev;
  while (tmp != NULL)
    {
      if (tmp->type == GRAPHIC && tmp->nb == ig)
	{
	  q = (t_que *)tmp->info;
	  i = 0;
	  while (q != NULL && i != ask_nb)
	    {
	      i++;
	      q = q->next;
	    }
	  return ((q == NULL) ? NULL : q->e);
	}
      tmp = tmp->next;
    }
  return (NULL);
}

int	my_apr(char **com, t_zap *data, t_user *usr)
{
  int		ig;
  int		ask_nb;
  t_ask		*ask;

  if (sstrlen(com) > 3 || sstrlen(com) == 2 ||
      (sstrlen(com) == 3 && (com[1][0] != '#' || com[2][0] != '#')))
    return (my_sbp(usr));
  if (sstrlen(com) == 1)
    return (aeg_response(data, usr, APR));
  if ((ig = my_strtol(com[1] + 1)) == -1 ||
      (ask_nb = my_strtol(com[2] + 1)) == -1)
    return (my_sbp(usr));
  if ((ask = get_asking(usr, ig, ask_nb)) == NULL)
    return (my_sbp(usr));
  ask->res |= APR;
  return (0);
}
