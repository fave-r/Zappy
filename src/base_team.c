/*
** base_team.c for base_team in /home/lopez_t/Zappy
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Wed May 27 10:54:50 2015 Thibaut Lopez
** Last update Wed May 27 10:55:17 2015 Thibaut Lopez
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
