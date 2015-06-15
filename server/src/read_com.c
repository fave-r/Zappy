/*
** read_com.c for zappy in /home/fave_r/rendu/Zappy/src
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue May 12 17:51:04 2015 romaric
** Last update Mon Jun 15 18:57:40 2015 Thibaut Lopez
*/

#include "server.h"

int	send_prend(t_user *usr, int item, t_content *cnt)
{
  char	tmp[256];
  int	nbr;

  nbr = usr->nb;
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

  nbr = usr->nb;
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

  while (usr->queue == NULL && (gnl = get_line_cb(&usr->cb)) != NULL)
    {
      if ((tok = stwt(gnl, " \t\n\r", usr->type)) == NULL)
	{
	  *ret = 0;
	  return;
	}
      if ((i = find_ptr(com, tok[0])) != -1
	  && (*ret = com[i].ptr(tok, data, usr)) != -1)
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
