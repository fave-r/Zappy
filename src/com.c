/*
** com.c for zappy in /home/fave_r/rendu/Zappy/src
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Mon May 18 11:16:04 2015 romaric
** Last update Tue May 19 10:42:46 2015 Thibaut Lopez
*/

#include "server.h"

int	send_prend(t_user *usr, int item, t_content *cnt)
{
  char	tmp[256];
  int	nbr;

  nbr = find_nb(usr);
  bzero(tmp, 256);
  sprintf(tmp, "pgt #%d %d\n\
pin #%d %d %d %d %d %d %d %d %d %d\n\
bct %d %d %d %d %d %d %d %d %d\n",
	  nbr, item, nbr, GET_X(usr), GET_Y(usr), GET_INV(usr).food,
	  GET_INV(usr).linemate, GET_INV(usr).deraumere, GET_INV(usr).sibur,
	  GET_INV(usr).mendiane, GET_INV(usr).phiras, GET_INV(usr).thystame,
	  GET_X(usr), GET_Y(usr), cnt->food, cnt->linemate, cnt->deraumere,
	  cnt->sibur, cnt->mendiane, cnt->phiras, cnt->thystame
	  );
  send_to_graphic(tmp, usr);
  return (0);
}

int	send_pose(t_user *usr, int item, t_content *cnt)
{
  char	tmp[256];
  int	nbr;

  nbr = find_nb(usr);
  bzero(tmp, 256);
  sprintf(tmp, "%d %d\n\
pin #%d %d %d %d %d %d %d %d %d %d\n\
bct %d %d %d %d %d %d %d %d %d\n",
	  nbr, item, nbr, GET_X(usr), GET_Y(usr), GET_INV(usr).food,
	  GET_INV(usr).linemate, GET_INV(usr).deraumere, GET_INV(usr).sibur,
	  GET_INV(usr).mendiane, GET_INV(usr).phiras, GET_INV(usr).thystame,
	  GET_X(usr), GET_Y(usr), cnt->food, cnt->linemate, cnt->deraumere,
	  cnt->sibur, cnt->mendiane, cnt->phiras, cnt->thystame
	  );
  send_to_graphic(tmp, usr);
  return (0);
}

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
