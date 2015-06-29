/*
** main.c for zappy in /home/fave_r/rendu/Zappy/src
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue May  5 15:02:45 2015 romaric
** Last update Mon Jun 29 18:32:29 2015 Thibaut Lopez
*/

#include "server.h"

int		nb_client(t_user *usr)
{
  int		i;

  i = 0;
  while (usr != NULL)
    {
      usr = usr->next;
      i++;
    }
  return (i);
}

int		main(int ac, char **av)
{
  int		s;
  t_user	*user;
  t_zap		data;

  srand(time(NULL));
  init_val(&data);
  if (ac == 1)
    printf("Note on usage: ./zappy [-p port] [-x length] [-y width] \
[-n team_name ...] [-c client_per_team] [-t delay] [-a asking delay]\n");
  if (parse_com(av, &data) != 0)
    return (1);
  if ((s = init_socket()) == -1)
    return (1);
  if (init_bind(s, &data.port) == -1)
    return (clean_return(s, "Couldn't bind"));
  if (listen(s, 0) == -1)
    return (clean_return(s, "Couldn't listen"));
  handle_fds(s, &user, &data);
  data_free(&user);
  close(s);
  free_zap(&data);
  printf("quitte normalement\n");
  return (0);
}
