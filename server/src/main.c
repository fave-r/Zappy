/*
** main.c for zappy in /home/fave_r/rendu/Zappy/src
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue May  5 15:02:45 2015 romaric
** Last update Sat Jul  4 14:01:28 2015 Thibaut Lopez
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

void		print_help_color()
{
  printf("\033[31mOption\t\033[33mValue\t\t");
  printf("\033[32mBase Value\t\033[36mGoal\n");
  printf("\033[31m-p\t\033[33mport\t\t");
  printf("\033[32m65536\t\t\033[36mSet the port\n");
  printf("\033[31m-x\t\033[33mlength\t\t");
  printf("\033[32m50\t\t\033[36mSet the length of the map\n");
  printf("\033[31m-y\t\033[33mwidth\t\t");
  printf("\033[32m50\t\t\033[36mSet the width of the map\n");
  printf("\033[31m-n\t\033[33mteams names\t");
  printf("\033[32mTeamA TeamB\t\033[36mSet the name of the teams\n");
  printf("\033[31m-c\t\033[33mnumber\t\t");
  printf("\033[32m10\t\t");
  printf("\033[36mSet the number max of client per team on the server\n");
  printf("\033[31m-t\t\033[33mdelay\t\t");
  printf("\033[32m100\t\t\033[36mSet the speed (greater mean faster)\n");
  printf("\033[31m-a\t\033[33masking delay\t");
  printf("\033[32m5.5\t\t\033[36mSet the delay on each asking\n");
  printf("\033[31m-w\t\033[33myes|y|no|n\t");
  printf("\033[32myes\t\t\033[36mEnable or disable the asking system\n");
  printf("\033[31m-v\t\033[33myes|y|no|n\t");
  printf("\033[32mno\t\t\033[36mEnable or disable verbose mode\n");
  printf("\033[31m-h\t\033[33m-\t\t");
  printf("\033[32m-\t\t\033[36mShow this help (no argument will too)\n");
  printf("\033[0m\n");
}

void		print_help()
{
  printf("Note on usage:\n");
  if (isatty(1))
    {
      print_help_color();
      return ;
    }
  printf("Option\tValue\t\tBase Value\tGoal\n");
  printf("-p\tport\t\t65536\t\tSet the port\n");
  printf("-x\tlength\t\t30\t\tSet the length of the map\n");
  printf("-y\twidth\t\t30\t\tSet the width of the map\n");
  printf("-n\tteams names\tTeamA TeamB\tSet the name of the teams\n");
  printf("-c\tnumber\t\t10\t\t");
  printf("Set the number max of client per team on the server\n");
  printf("-t\tdelay\t\t100\t\tSet the speed (greater mean faster)\n");
  printf("-a\tasking delay\t5.5\t\tSet the delay on each asking\n");
  printf("-w\tyes|y|no|n\tyes\t\tEnable or disable the asking system\n");
  printf("-v\tyes|y|no|n\tno\t\tEnable or disable verbose mode\n");
  printf("-h\t-\t\t-\t\tShow this help (no argument will too)\n\n");
}

int		is_asking_for_help(char **av)
{
  int		i;

  i = 1;
  while (av[i] != NULL)
    {
      if (strcmp(av[i], "-h") == 0)
	return (1);
      i++;
    }
  return ((i == 1) ? 1 : 0);
}

int		main(int ac, char **av)
{
  int		s;
  t_user	*user;
  t_zap		data;

  (void)ac;
  srand(time(NULL));
  init_val(&data);
  if (is_asking_for_help(av))
    print_help();
  if (parse_com(av, &data) != 0)
    return (1);
  if ((s = init_socket()) == -1)
    return (clean_return(-1, "Socket failed", &data));
  if (init_bind(s, &data.port) == -1)
    return (clean_return(s, "Couldn't bind", &data));
  if (listen(s, 0) == -1)
    return (clean_return(s, "Couldn't listen", &data));
  handle_fds(s, &user, &data);
  data_free(&user, &data);
  close(s);
  free_zap(&data);
  return (0);
}
