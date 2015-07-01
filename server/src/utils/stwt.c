/*
** stwt.c for stwt in /home/lopez_t/Zappy
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Tue May  5 18:33:45 2015 Thibaut Lopez
** Last update Wed Jul  1 18:22:14 2015 Thibaut Lopez
*/

#include "utils.h"

char	*skip_delim(char *str, char *delim)
{
  while (str[0] != 0 && strchr(delim, str[0]) != NULL)
    str++;
  return (str);
}

int	skip_word(char *str, char *delim, int nb_word)
{
  int	i;

  i = 0;
  if (nb_word > 1 && str[0] == ':')
    while (str[i] != 0)
      i++;
  else
    while (str[i] != 0 && strchr(delim, str[i]) == NULL)
      i++;
  return (i);
}

int	lenword(char *str, int *nb_letters, char *delim, int nb_word)
{
  int	len;

  len = 0;
  while (str != NULL && (str = skip_delim(str, delim))[0] != 0
	 && (nb_word == -1 || len < nb_word))
    {
      len++;
      *nb_letters += (skip_word(str, delim, len) + 1) * sizeof(char);
      str += skip_word(str, delim, len);
    }
  if (str[0] != 0)
    *nb_letters += strlen(str);
  return (len);
}

void	word_limitation(char **ret, char *str, char *delim)
{
  int	i;
  int	len;

  if ((skip_delim(str, delim))[0] != 0)
    {
      i = 0;
      while (ret[i + 1] != NULL)
	i++;
      len = strlen(ret[i]) + strlen(str);
      strcpy(ret[i] + strlen(ret[i]), str);
      ret[i][len] = 0;
    }
}

char	**stwt(char *str, char *delim, int nb_word)
{
  int	i;
  int	nb_letters;
  char	**ret;
  char	*cur;

  nb_letters = strlen(str);
  if ((nb_word = lenword(str, &nb_letters, delim, nb_word)) == 0)
    return (NULL);
  ret = xmalloc((nb_word + 1) * sizeof(char *) + nb_letters);
  nb_letters = 0;
  cur = (char *)ret + (nb_word + 1) * sizeof(char *);
  i = -1;
  while (nb_word > ++i)
    {
      str = skip_delim(str, delim);
      nb_letters = skip_word(str, delim, i);
      strncpy(cur, str, nb_letters);
      cur[nb_letters] = 0;
      ret[i] = cur;
      str += nb_letters;
      cur += nb_letters + 1;
    }
  ret[i] = NULL;
  word_limitation(ret, str, delim);
  return (ret);
}
