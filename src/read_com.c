/*
** read_com.c for zappy in /home/fave_r/rendu/Zappy/src
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue May 12 17:51:04 2015 romaric
** Last update Mon May 25 17:30:42 2015 Thibaut Lopez
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

t_com		*graphic_funcs()
{
  t_com		*ptrs;

  ptrs = xmalloc(11 * sizeof(t_com));
  ptrs[0].com = "msz";
  ptrs[0].ptr = my_msz;
  ptrs[1].com = "bct";
  ptrs[1].ptr = my_bct;
  ptrs[2].com = "mct";
  ptrs[2].ptr = my_mct;
  ptrs[3].com = "tna";
  ptrs[3].ptr = my_tna;
  ptrs[4].com = "ppo";
  ptrs[4].ptr = my_ppo;
  ptrs[5].com = "plv";
  ptrs[5].ptr = my_plv;
  ptrs[6].com = "pin";
  ptrs[6].ptr = my_pin;
  ptrs[7].com = "sgt";
  ptrs[7].ptr = my_sgt;
  ptrs[8].com = "sst";
  ptrs[8].ptr = my_sst;
  ptrs[9].com = "";
  ptrs[9].ptr = my_suc;
  ptrs[10].com = NULL;
  ptrs[10].ptr = NULL;
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

int		read_com(t_user *usr, t_zap *data)
{
  t_com		*com;
  int		ret;

  ret = 0;
  if (cb_taken(&usr->cb) == 0 && read_cb(&usr->cb, usr->fd) <= 0)
    {
      usr->tokill = 1;
      return (-1);
    }
  com = ptr_to_function(usr->type);
  check_com(com, usr, &ret, data);
  free(com);
  return (ret);
}
