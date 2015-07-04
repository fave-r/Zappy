/*
** strflat.c for strflat in /home/lopez_t/Zappy/server
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Thu Jul  2 02:56:40 2015 Thibaut Lopez
** Last update Sat Jul  4 19:15:48 2015 Thibaut Lopez
*/

#include "server.h"

int	flatlen(char **tab, char *sep)
{
  int	i;
  int	len;

  i = 0;
  len = 2;
  while (tab[i] != NULL)
    {
      len += strlen(tab[i]);
      if (tab[++i] != NULL)
	len += strlen(sep);
    }
  return (len);
}

char	*strflat(char **tab, char *sep)
{
  char	*new;
  int	i;
  int	len;

  if (tab == NULL)
    return (NULL);
  len = flatlen(tab, sep);
  if ((new = malloc(len * sizeof(char))) == NULL)
    return (NULL);
  bzero(new, len);
  i = 0;
  while (tab[i] != NULL)
    {
      sprintf(new + strlen(new), "%s%s", tab[i],
	      (tab[i + 1] == NULL) ? "" : sep);
      i++;
    }
  new[strlen(new)] = '\n';
  return (new);
}

char	*flat_ask(char **tab, int ig, int ask_nb)
{
  char	ret[32];
  char	*flat;
  char	*result;

  flat = strflat(tab + 1, " ");
  if (flat == NULL)
    return (NULL);
  bzero(ret, 32);
  sprintf(ret, "%s %d %d ", tab[0], ig, ask_nb);
  result = my_strcat(ret, flat);
  free(flat);
  return (result);
}

int	teamflatlen(t_team *teams, char *sep)
{
  int	len;

  len = 2;
  while (teams != NULL)
    {
      len += strlen(teams->name);
      teams = teams->next;
      if (teams != NULL)
	len += strlen(sep);
    }
  return (len);
}

char	*teamflat(t_team *teams, char *sep)
{
  char	*new;
  int	len;

  len = teamflatlen(teams, sep);
  if ((new = malloc(len * sizeof(char))) == NULL)
    return (NULL);
  bzero(new, len);
  while (teams != NULL)
    {
      sprintf(new + strlen(new), "%s%s", teams->name,
	      (teams->next == NULL) ? "\n" : sep);
      teams = teams->next;
    }
  return (new);
}
