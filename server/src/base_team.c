/*
** base_team.c for base_team in /home/lopez_t/Zappy
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Wed May 27 10:54:50 2015 Thibaut Lopez
** Last update Sat Jul  4 15:16:03 2015 Thibaut Lopez
*/

#include "server.h"

t_team		*base_team()
{
  t_team	*teama;
  t_team	*teamb;

  teama = malloc(sizeof(t_team));
  teamb = malloc(sizeof(t_team));
  teama->name = strdup("TeamA");
  teama->count = -1;
  teama->eggs = NULL;
  teama->next = teamb;
  teamb->name = strdup("TeamB");
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

  tmp = usr;
  while (tmp != NULL && tmp->prev != NULL)
    tmp = tmp->prev;
  while (tmp != NULL)
    {
      if (tmp->type == AI && GET_TEAM(tmp) == team && GET_LVL(tmp) == 8)
	return (1);
      tmp = tmp->next;
    }
  return (0);
}

t_team		*team_by_name(t_team *teams, char *name)
{
  while (teams != NULL && strcmp(teams->name, name) != 0)
    teams = teams->next;
  return (teams);
}
