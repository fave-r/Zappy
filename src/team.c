/*
** team.c for team in /home/lopez_t/Zappy
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Tue May 26 16:24:34 2015 Thibaut Lopez
** Last update Wed May 27 11:23:22 2015 Thibaut Lopez
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

void		*clone_egg(void *to_clone)
{
  t_egg		*egg;
  t_egg		*new;

  egg = (t_egg *)to_clone;
  new = xmalloc(sizeof(t_egg));
  new->pos.f = egg->pos.f;
  new->pos.s = egg->pos.s;
  new->hatch.tv_sec = egg->hatch.tv_sec;
  new->hatch.tv_usec = egg->hatch.tv_usec;
  return (new);
}
