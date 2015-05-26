/*
** team.c for team in /home/lopez_t/Zappy
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Tue May 26 16:24:34 2015 Thibaut Lopez
** Last update Tue May 26 18:26:19 2015 Thibaut Lopez
*/

#include "server.h"

void		put_team(t_team *teams, int fd)
{
  t_team	*cur;

  cur = teams;
  while (cur != NULL)
    {
      dprintf(fd, "%s\n", cur->name);
      cur = cur->next;
    }
}

int		team_len(t_team *teams)
{
  int		i;
  t_team	*cur;

  i = 0;
  cur = teams;
  while (cur != NULL)
    {
      i++;
      cur = cur->next;
    }
  return (i);
}

t_team		*team_cat(t_team *teams, char *team)
{
  t_team	*new;
  t_team	*cur;

  new = xmalloc(sizeof(t_team));
  new->name = team;
  new->count = -1;
  new->eggs = NULL;
  new->next = NULL;
  cur = teams;
  while (cur != NULL && cur->next != NULL)
    cur = cur->next;
  if (cur == NULL)
    teams = new;
  else
    cur->next = new;
  return (teams);
}

t_team		*team_by_name(t_team *teams, char *team)
{
  while (teams != NULL)
    {
      if (strcmp(teams->name, team) == 0)
	return (teams);
      teams = teams->next;
    }
  return (NULL);
}

void		team_free(t_team *teams)
{
  t_team	*to_free;

  while (teams != NULL)
    {
      to_free = teams;
      teams = teams->next;
      free(to_free->name);
      free(to_free);
    }
}

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
