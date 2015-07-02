/*
** verbose2.c for verbose2 in /home/lopez_t/Zappy/server
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Thu Jul  2 15:51:33 2015 Thibaut Lopez
** Last update Thu Jul  2 19:57:26 2015 Thibaut Lopez
*/

#include "server.h"

void		print_data(t_zap *data)
{
  printf("Information about the server:\n");
  printf("Port: %d\n", data->port);
  printf("Map of %dx%d cells\n", data->length, data->width); 
  printf("Player max per team: %d\n", data->count);
  printf("Delay for each action: %d\n", data->delay);
  printf("Name of each team\n");
  put_team(data->teams);
  printf("Time waiting for a graphic response: %f\n", data->asking);
  printf("Asking: %s\n", (data->wait == 0) ? "yes" : "no");
  printf("Verbose: %s\n", (data->verbose == 0) ? "no" : "yes");
}

void		verbose_base(t_user *usr, char *color)
{
  t_tv		now;
  struct tm	*tm;
  char		*type;
  char		time[64];

  gettimeofday(&now, NULL);
  tm = localtime(&now.tv_sec);
  if (usr != NULL)
    type = (usr->type == UNKNOWN) ? "unknown" :
      (usr->type == AI) ? "AI" : "GUI";
  strftime(time, sizeof(time), "%Y-%m-%d %H:%M:%S", tm);
  if (isatty(1))
    printf("\033[36m");
  printf("%s:%ld:\n", time, now.tv_usec);
  if (usr != NULL)
    {
      if (isatty(1))
	printf(color);
      printf("User %d (type %s)", usr->nb, type);
    }
}

int	set_verbose(t_zap *data, char *arg, e_state *state)
{
  if (strcmp(arg, "yes") == 0 || strcmp(arg, "y") == 0)
    data->verbose = 1;
  else if (strcmp(arg, "no") == 0 || strcmp(arg, "n") == 0)
    data->verbose = 0;
  else
    fprintf(stderr, "Warning: '-v %s': %s not a good answer.\n", arg, arg);
  *state = NONE;
  return (0);
}

void		verbose_ask(t_user *usr, char *demand, t_ask *ask)
{
  (void)usr;
  (void)demand;
  (void)ask;
}

void		verbose_ask_result(t_user *usr, t_ask *ask)
{
  (void)usr;
  (void)ask;
}
