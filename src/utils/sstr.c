/*
** sstr.c for sstr in /home/lopez_t/Zappy/src/utils
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Wed May  6 09:49:44 2015 Thibaut Lopez
** Last update Wed May  6 10:35:16 2015 Thibaut Lopez
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

void	putsstr(int fd, char **str)
{
  int	i;

  i = 0;
  while (str != NULL && str[i] != NULL)
    {
      dprintf(fd, "%s\n", str[i]);
      i++;
    }
}
