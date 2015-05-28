/*
** base_team.c for base_team in /home/lopez_t/Zappy
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Wed May 27 10:54:50 2015 Thibaut Lopez
** Last update Thu May 28 11:06:05 2015 Thibaut Lopez
*/

#include "server.h"

t_team		*base_team()
{
  t_team	*teama;
  t_team	*teamb;

  teama = xmalloc(sizeof(t_team));
  teamb = xmalloc(sizeof(t_team));
  teama->name = xstrdup("TeamA");
  teama->count = -1;
  teama->eggs = NULL;
  teama->next = teamb;
  teamb->name = xstrdup("TeamB");
  teamb->count = -1;
  teamb->eggs = NULL;
  teamb->next = NULL;
  return (teama);
}

void		team_counts(t_team *teams, int count)
{
  t_team	*cur;

  cur = teams;
  while (cur != NULL)
    {
      cur->count = count;
      cur = cur->next;
    }
}

int		count_in_team(t_team *team_name, t_user *user)
{
  t_user	*tmp;
  int		i;

  tmp = user;
  while (tmp != NULL && tmp->prev != NULL)
    tmp = tmp->prev;
  i = 0;
  while (tmp != NULL)
    {
      if (tmp->type == AI && GET_TEAM(tmp) == team_name)
	i++;
      tmp = tmp->next;
    }
  return (i);
}

int		team_winning(t_user *usr, t_team *team)
{
  t_user	*tmp;
  int		nb;

  tmp = usr;
  nb = 0;
  while (tmp != NULL && tmp->prev != NULL)
    tmp = tmp->prev;
  while (tmp != NULL)
    {
      if (tmp->type == AI && GET_TEAM(tmp) == team && GET_LVL(tmp) == 8)
	nb++;
      tmp = tmp->next;
    }
  return ((nb != 0 && nb == count_in_team(team, usr)) ? 1 : 0);
}
