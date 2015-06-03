/*
** common_func.c for common_func in /home/lopez_t/PSU_2014_myirc
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Mon Apr  6 17:09:17 2015 Thibaut Lopez
** Last update Wed Jun  3 17:45:05 2015 Thibaut Lopez
*/

#include "utils.h"

int		find_ptr(t_com *com, char *str)
{
  int		j;
  size_t	len;

  j = 0;
  while (com[j].com != NULL)
    {
      len = strlen(com[j].com);
      if (len == 0)
	return (j);
      if (len <= strlen(str) && strncmp(str, com[j].com, len) == 0)
	return (j);
      j++;
    }
  return (-1);
}

int		my_strtol(char *nbr)
{
  long		ret;
  char		*err;

  ret = strtol(nbr, &err, 10);
  if (err[0] != 0)
    return (-1);
  if (ret > INT_MAX || ret < 0)
    return (-1);
  return (ret);
}

float		my_strtof(char *nbr)
{
  float		ret;
  char		*err;

  ret = strtof(nbr, &err);
  if (err[0] != 0)
    return (-1);
  if (ret == FLT_MAX || ret < 0)
    return (-1);
  return (ret);
}

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
  char	*cur;
  int	i;

  if (tab == NULL)
    return (NULL);
  new = xmalloc(flatlen(tab, sep) * sizeof(char));
  cur = new;
  i = 0;
  while (tab[i] != NULL)
    {
      strcpy(cur, tab[i]);
      cur += strlen(tab[i]);
      if (tab[++i] != NULL)
	{
	  strcpy(cur, sep);
	  cur += strlen(sep);
	}
    }
  cur[0] = '\n';
  cur[1] = 0;
  return (new);
}
