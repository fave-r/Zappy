/*
** fd_func.c for zappy in /home/fave_r/rendu/Zappy/src
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue May  5 15:51:15 2015 romaric
** Last update Mon Jun  1 10:59:54 2015 Thibaut Lopez
*/

#include "server.h"

void	set_fd(int s, t_bf *bf, t_user *user)
{
  t_user	*tmp;

  FD_ZERO(&(bf->rbf));
  FD_ZERO(&(bf->wbf));
  FD_SET(s, &(bf->rbf));
  if (user != NULL)
    {
      tmp = user;
      while (tmp != NULL)
	{
	  FD_SET(tmp->fd, &(bf->rbf));
	  if (cb_taken(&tmp->wr) > 0)
	    FD_SET(tmp->fd, &(bf->wbf));
	  tmp = tmp->next;
	}
    }
}

void			push_back(t_user **user, t_user *to_add)
{
  t_user	*tmp;

  tmp = *user;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = to_add;
  to_add->prev = tmp;
}

void			new_client(int fd, t_user **user, int *nbclient)
{
  t_user		*new;
  struct sockaddr_in	sin;
  socklen_t		len;

  *nbclient = *nbclient + 1;
  new = xmalloc(sizeof(t_user));
  len = sizeof(sin);
  new->fd = accept(fd, (struct sockaddr *)&sin, &len);
  new->ip = inet_ntoa(sin.sin_addr);
  new->next = NULL;
  new->prev = NULL;
  new->tokill = 0;
  init_cb(&new->cb, 4096, sizeof(char));
  init_cb(&new->wr, 4096, sizeof(char));
  new->queue = NULL;
  new->type = UNKNOWN;
  new->info = NULL;
  new->nb_ncom = 0;
  printf("new client\n");
  if (*user != NULL)
    push_back(user, new);
  else
    *user = new;
  fill_cb(&new->wr, "BIENVENUE\n", strlen("BIENVENUE\n"));
}

void		data_free(t_user **data)
{
  t_user	*tmp;

  tmp = *data;
  while (tmp != NULL && tmp->next != NULL)
    {
      close(tmp->fd);
      free_cb(&tmp->cb);
      free_cb(&tmp->wr);
      while (tmp->queue != NULL)
	pop_q(&tmp->queue);
      if (tmp->type == AI)
	free(tmp->info);
      tmp = tmp->next;
      free(tmp->prev);
    }
  if (tmp != NULL)
    free(tmp);
}

void		unit_user_free(t_user *user)
{
  close(user->fd);
  free_cb(&user->cb);
  free_cb(&user->wr);
  while (user->queue != NULL)
    pop_q(&user->queue);
  if (user->type == AI)
    free(user->info);
  if (user->prev != NULL)
    user->prev->next = user->next;
  if (user->next != NULL)
    user->next->prev = user->prev;
  free(user);
}
