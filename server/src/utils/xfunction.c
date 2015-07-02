/*
** xfunction.c for zappy in /home/fave_r/rendu/Zappy/src
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue May  5 16:43:03 2015 romaric
** Last update Wed Jul  1 20:57:21 2015 Thibaut Lopez
*/

#include "utils.h"

int		xopen(const char *pathname, int flags)
{
  int		len;

  len = open(pathname, flags);
  if (len == -1)
    {
      fprintf(stderr, "open fail.\n");
      exit(EXIT_FAILURE);
    }
  return (len);
}

ssize_t		xread(int fd, void *buf, size_t count)
{
  ssize_t	len;

  len = read(fd, buf, count);
  if (len == -1)
    {
      fprintf(stderr, "read fail.\n");
      exit(EXIT_FAILURE);
    }
  return (len);
}

void		*xmalloc(size_t n)
{
  void		*mal;

  mal = malloc(n);
  if (mal == NULL)
    {
      fprintf(stderr, "malloc fail.\n");
      exit(EXIT_FAILURE);
    }
  return (mal);
}

char		*xstrdup(const char *s)
{
  char		*str;

  str = strdup(s);
  if (str == NULL)
    {
      fprintf(stderr, "strdup fail.\n");
      exit(EXIT_FAILURE);
    }
  return (str);
}

int		smod(int nb, int mod)
{
  while (nb < 0)
    nb += mod;
  return (nb % mod);
}
