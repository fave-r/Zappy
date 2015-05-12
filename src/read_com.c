/*
** read_com.c for zappy in /home/fave_r/rendu/Zappy/src
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue May 12 17:51:04 2015 romaric
** Last update Tue May 12 19:09:37 2015 Thibaut Lopez
*/

#include "server.h"

void		assign_ptrs(t_com *ptrs)
{
  ptrs[0].ptr = my_avance;
  ptrs[1].ptr = my_broadcast;
  ptrs[2].ptr = my_connect_nbr;
  ptrs[3].ptr = my_droite;
  ptrs[4].ptr = my_expulse;
  ptrs[5].ptr = my_fork;
  ptrs[6].ptr = my_gauche;
  ptrs[7].ptr = my_incantation;
  ptrs[8].ptr = my_inventaire;
  ptrs[9].ptr = my_pose;
  ptrs[10].ptr = my_prend;
  ptrs[11].ptr = my_voir;
  ptrs[12].ptr = NULL;

}

t_com		*ptr_to_function()
{
  t_com		*ptrs;

  ptrs = xmalloc(13 * sizeof(t_com));
  ptrs[0].com = "avance";
  ptrs[1].com = "broadcast";
  ptrs[2].com = "connect_nbr";
  ptrs[3].com = "droite";
  ptrs[4].com = "expulse";
  ptrs[5].com = "fork";
  ptrs[6].com = "gauche";
  ptrs[7].com = "incantation";
  ptrs[8].com = "inventaire";
  ptrs[9].com = "pose";
  ptrs[10].com = "prend";
  ptrs[11].com = "voir";
  ptrs[12].com = NULL;
  assign_ptrs(ptrs);
  return (ptrs);
}

int		read_com(t_user *usr, t_zap *data)
{
  char		*gnl;
  char		**tok;
  t_com		*com;
  int		i;
  int		ret;

  ret = 0;
  if (read_cb(&usr->cb, usr->fd) <= 0)
    return (-1);
  com = ptr_to_function();
  while ((gnl = get_line_cb(&usr->cb)) != NULL)
    {
      printf("%s\n", gnl);
      if ((tok = stwt(gnl, " \t\n\r")) == NULL)
	return (0);
      i = find_ptr(com, tok[0]);
      if (i != -1)
	ret = com[i].ptr(tok, data, usr);
      else
	my_other(tok, data, usr);
      free(tok);
      free(gnl);
    }
  free(com);
  return (ret);
}
