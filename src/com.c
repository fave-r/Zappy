/*
** com.c for zappy in /home/fave_r/rendu/Zappy/src
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Mon May 18 11:16:04 2015 romaric
** Last update Mon May 18 11:49:01 2015 romaric
*/

#include "server.h"

void	check_com(t_com *com, t_user *usr, int *ret, t_zap *data)
{
  int	i;
  char	*gnl;
  char	**tok;

  while ((gnl = get_line_cb(&usr->cb)) != NULL)
    {
      if ((tok = stwt(gnl, " \t\n\r", usr->type)) == NULL)
	{
	  *ret = 0;
	  return;
	}
      if ((i = find_ptr(com, tok[0])) != -1
	  &&  (*ret = com[i].ptr(tok, data, usr)) != -1)
	usr->nb_ncom = 0;
      else
	{
	  usr->nb_ncom += 1;
	  if (usr->nb_ncom == 10)
	    usr->tokill = 1;
	}
      free(tok);
      free(gnl);
    }
}
