/*
** getter.c for getter in /home/lopez_t/BONUS/Zappy/src
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Thu Jun  4 09:15:55 2015 Thibaut Lopez
** Last update Thu Jun  4 09:27:42 2015 Thibaut Lopez
*/

#include "server.h"

t_user	*get_by_nb(t_user *usr, int nb, e_clt type)
{
  while (usr != NULL && usr->prev != NULL)
    usr = usr->next;
  while (usr != NULL)
    {
      if (usr->type == type && usr->nb == nb)
	return (usr);
      usr = usr->next;
    }
  return (NULL);
}

t_egg	*get_egg_by_nb(t_team *teams, int nbr)
{
  t_team	*tmp;
  t_que		*eggs;
  t_egg		*egg;

  tmp = teams;
  while (tmp != NULL)
    {
      eggs = tmp->eggs;
      while (eggs != NULL)
	{
	  egg = front_q(eggs);
	  if (egg->nb == nbr)
	    return (egg);
	  eggs = eggs->next;
	}
      tmp = tmp->next;
    }
  return (NULL);
}
