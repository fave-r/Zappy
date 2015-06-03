/*
** graphic_ptr.c for graphic_ptr in /home/lopez_t/BONUS/Zappy/src
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Fri May 29 14:54:42 2015 Thibaut Lopez
** Last update Wed Jun  3 14:38:11 2015 Thibaut Lopez
*/

#include "server.h"

void		graphic_ask(t_com *ptrs)
{
  ptrs[19].com = "agt";
  ptrs[19].ptr = my_agt;
  ptrs[20].com = "apr";
  ptrs[20].ptr = my_apr;
  ptrs[21].com = "anr";
  ptrs[21].ptr = my_anr;
}

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
  ptrs[14].com = "sep";
  ptrs[14].ptr = my_sep;
  ptrs[15].com = "sek";
  ptrs[15].ptr = my_sek;
  ptrs[16].com = "sct";
  ptrs[16].ptr = my_sct;
  ptrs[17].com = "sms";
  ptrs[17].ptr = my_sms;
  ptrs[18].com = "srs";
  ptrs[18].ptr = my_srs;
  graphic_ask(ptrs);
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
  ptrs[22].ptr = my_suc;
  ptrs[23].ptr = NULL;
}

t_com		*graphic_funcs()
{
  t_com		*ptrs;

  ptrs = xmalloc(24 * sizeof(t_com));
  ptrs[0].com = "msz";
  ptrs[1].com = "bct";
  ptrs[2].com = "mct";
  ptrs[3].com = "tna";
  ptrs[4].com = "ppo";
  ptrs[5].com = "plv";
  ptrs[6].com = "pin";
  ptrs[7].com = "sgt";
  ptrs[8].com = "sst";
  ptrs[22].com = "";
  ptrs[23].com = NULL;
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
