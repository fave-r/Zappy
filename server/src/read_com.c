/*
** read_com.c for zappy in /home/fave_r/rendu/Zappy/src
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue May 12 17:51:04 2015 romaric
** Last update Sat Jul  4 17:17:21 2015 Thibaut Lopez
*/

#include "server.h"

int	send_prend(t_user *usr, int item, t_content *cnt)
{
  char	tmp[256];
  int	nbr;

  nbr = usr->nb;
  bzero(tmp, 256);
  sprintf(tmp, "pgt %d %d\n\
pin %d %d %d %d %d %d %d %d %d %d\n\
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
  sprintf(tmp, "pgt %d %d\n\
pin %d %d %d %d %d %d %d %d %d %d\n\
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

int		read_com(t_user *usr, t_zap *data)
{
  int		i;
  char		*gnl;
  char		**tok;
  t_com		*com;
  int		ret;

  ret = 0;
  if ((com = ptr_to_function(usr->type)) == NULL)
    return (-1);
  while (usr->queue == NULL && (gnl = get_line_cb(&usr->cb)) != NULL)
    {
      verbose_receive(usr, gnl, data);
      tok = stwt(gnl, " \t\n\r", usr->type);
      free(gnl);
      if (tok == NULL)
	return (0);
      if ((i = find_ptr(com, tok[0])) != -1 &&
	  (ret = com[i].ptr(tok, data, usr)) != -1)
	usr->nb_ncom = 0;
      else if (++usr->nb_ncom == 10)
	usr->tokill = 1;
      free(tok);
    }
  free(com);
  return (ret);
}

int		write_read_client(t_user **user, t_bf *bf, t_zap *data)
{
  t_user	*tmp;
  int		rv;

  tmp = *user;
  while (tmp != NULL)
    {
      if (FD_ISSET(tmp->fd, &bf->rbf) && cb_taken(&tmp->cb) == 0)
	if ((rv = read_cb(tmp, tmp->fd)) <= 0)
	  {
	    tmp->tokill = (rv <= 0) ? 2 : 1;
	    return (-1);
	  }
      if (cb_taken(&tmp->wr) > 0 && FD_ISSET(tmp->fd, &bf->wbf))
	write_cb(tmp, data, &tmp->queue);
      tmp = tmp->next;
    }
  return (0);
}
