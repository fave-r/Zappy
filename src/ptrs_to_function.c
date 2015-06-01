/*
** ptrs_to_functions.c for zappy in /home/fave_r/rendu/Zappy/src
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Mon May 18 11:16:04 2015 romaric
** Last update Fri May 29 14:54:59 2015 Thibaut Lopez
*/

#include "server.h"

t_com		*unknown_funcs()
{
  t_com		*ptrs;

  ptrs = xmalloc(3 * sizeof(t_com));
  ptrs[0].com = "GRAPHIC";
  ptrs[0].ptr = my_graphic;
  ptrs[1].com = "";
  ptrs[1].ptr = my_other;
  ptrs[2].com = NULL;
  ptrs[2].ptr = NULL;
  return (ptrs);
}

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

t_com		*ptr_to_function(e_clt type)
{
  t_com		*ptrs;

  if (type == UNKNOWN)
    return (unknown_funcs());
  else if (type == GRAPHIC)
    return (graphic_funcs());
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
