/*
** str.c for zappy in /home/fave_r/rendu/Zappy/src/utils
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue May  5 17:47:45 2015 romaric
** Last update Wed May  6 09:50:02 2015 Thibaut Lopez
*/

#include "utils.h"

int	my_strstr(char **tab, char *str)
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

char	*my_strcat(char *s1, char *s2)
{
  int	i;
  int	j;
  char	*ret;

  if (s1 == NULL && s2 == NULL)
    return (NULL);
  else if (s1 == NULL && s2 != NULL)
    return (strdup(s2));
  else if (s1 != NULL && s2 == NULL)
    return (strdup(s1));
  ret = malloc((strlen(s1) + strlen(s2) + 1) * sizeof(char));
  if (ret == NULL)
    return (NULL);
  i = -1;
  while (s1[++i] != 0)
    ret[i] = s1[i];
  j = -1;
  while (s2[++j] != 0)
    ret[i + j] = s2[j];
  ret[i + j] = 0;
  return (ret);
}
