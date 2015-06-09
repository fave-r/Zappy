/*
** x_tcp.c for zappy in /home/fave_r/rendu/PSU_2014_myirc
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue May  5 15:47:09 2015 romaric
** Last update Tue Jun  9 13:47:37 2015 Thibaut Lopez
*/

#include "server.h"

int			clean_return(int fd, char *str)
{
  if (fd > 2)
    close(fd);
  fprintf(stderr, "%s\n", str);
  return (1);
}

int			init_socket(void)
{
  struct protoent	*pe;

  pe = getprotobyname("TCP");
  return (socket(AF_INET, SOCK_STREAM, pe->p_proto));
}

int			init_bind(int s, int *port)
{
  struct sockaddr_in	sin;
  socklen_t		len;

  sin.sin_family = AF_INET;
  sin.sin_port = htons(*port);
  sin.sin_addr.s_addr = INADDR_ANY;
  if (bind(s, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
    return (-1);
  len = sizeof(sin);
  if (*port == 0)
    {
      if (getsockname(s, (struct sockaddr *)&sin, &len) == -1)
	return (-1);
      *port = ntohs(sin.sin_port);
    }
  return (0);
}

int			init_connect(int s, int port, char *id)
{
  struct sockaddr_in	sin;

  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  sin.sin_addr.s_addr = inet_addr(id);
  return (connect(s, (const struct sockaddr *)&sin, sizeof(sin)));
}
