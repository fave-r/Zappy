/*
** graphic_ptr.c for graphic_ptr in /home/lopez_t/BONUS/Zappy/src
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Fri May 29 14:54:42 2015 Thibaut Lopez
** Last update Thu Jun  4 17:02:51 2015 Thibaut Lopez
*/

#include "server.h"

void		graphic_bonus(t_com *ptrs)
{
  ptrs[9].com = "stn";
  ptrs[9].ptr = my_stn;
  ptrs[10].com = "spp";
  ptrs[10].ptr = my_spp;
  ptrs[11].com = "spi";
  ptrs[11].ptr = my_spi;
  ptrs[12].com = "spl";
  ptrs[12].ptr = my_spl;
  ptrs[13].com = "spk";
  ptrs[13].ptr = my_spk;
  ptrs[14].com = "sct";
  ptrs[14].ptr = my_sct;
  ptrs[15].com = "sms";
  ptrs[15].ptr = my_sms;
  ptrs[16].com = "srs";
  ptrs[16].ptr = my_srs;
  ptrs[17].com = "agt";
  ptrs[17].ptr = my_agt;
  ptrs[18].com = "apr";
  ptrs[18].ptr = my_apr;
  ptrs[19].com = "anr";
  ptrs[19].ptr = my_anr;
}

void		graphic_ptrs(t_com *ptrs)
{
  ptrs[0].ptr = my_msz;
  ptrs[1].ptr = my_bct;
  ptrs[2].ptr = my_mct;
  ptrs[3].ptr = my_tna;
  ptrs[4].ptr = my_ppo;
  ptrs[5].ptr = my_plv;
  ptrs[6].ptr = my_pin;
  ptrs[7].ptr = my_sgt;
  ptrs[8].ptr = my_sst;
  ptrs[20].ptr = my_suc;
  ptrs[21].ptr = NULL;
}

t_com		*graphic_funcs()
{
  t_com		*ptrs;

  ptrs = xmalloc(22 * sizeof(t_com));
  ptrs[0].com = "msz";
  ptrs[1].com = "bct";
  ptrs[2].com = "mct";
  ptrs[3].com = "tna";
  ptrs[4].com = "ppo";
  ptrs[5].com = "plv";
  ptrs[6].com = "pin";
  ptrs[7].com = "sgt";
  ptrs[8].com = "sst";
  ptrs[20].com = "";
  ptrs[21].com = NULL;
  graphic_ptrs(ptrs);
  graphic_bonus(ptrs);
  return (ptrs);
}

int		count_type(t_user *usr, e_clt type)
{
  int		c;
  t_user	*tmp;

  c = 0;
  tmp = usr;
  while (tmp != NULL && tmp->prev != NULL)
    tmp = tmp->prev;
  while (tmp != NULL)
    {
      if (tmp->type == type)
	c++;
      tmp = tmp->next;
    }
  return (c);
}