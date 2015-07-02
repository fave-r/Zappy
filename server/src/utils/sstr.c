/*
** sstr.c for sstr in /home/lopez_t/Zappy/src/utils
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Wed May  6 09:49:44 2015 Thibaut Lopez
** Last update Thu Jul  2 14:55:48 2015 Thibaut Lopez
*/

#include "utils.h"

void	sfree(char **str)
{
  int	i;

  i = 0;
  while (str != NULL && str[i] != NULL)
    {
      free(str[i]);
      i++;
    }
  if (str != NULL)
    free(str);
}

int	sstrlen(char **str)
{
  int	i;

  if (str == NULL)
    return (0);
  i = 0;
  while (str[i] != NULL)
    i++;
  return (i);
}

char	**sstrcat(char **str, char *ad)
{
  int	i;
  char	**ret;

  i = 0;
  ret = xmalloc((sstrlen(str) + 2) * sizeof(char *));
  while (str != NULL && str[i] != NULL)
    {
      ret[i] = xstrdup(str[i]);
      i++;
    }
  ret[i] = ad;
  ret[i + 1] = NULL;
  if (str != NULL)
    sfree(str);
  return (ret);
}

int	sstrchr(char **tab, char *str)
{
  int	i;

  i = 0;
  while (tab != NULL && tab[i] != NULL)
    {
      if (strcmp(tab[i], str) == 0)
	return (i);
      i++;
    }
  return (-1);
}

void	putsstr(char **str)
{
  int	i;

  i = 0;
  while (str != NULL && str[i] != NULL)
    {
      printf("%s\n", str[i]);
      i++;
    }
}
