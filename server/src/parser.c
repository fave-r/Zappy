/*
** parser.c for parser in /home/lopez_t/Zappy
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Tue May  5 16:43:22 2015 Thibaut Lopez
** Last update Thu Jul  2 04:12:43 2015 Thibaut Lopez
*/

#include "server.h"

int		set_team(t_zap *data, char *arg, e_state *state)
{
  (void)state;
  if (strlen(arg) < 200)
    data->teams = team_cat(data->teams, xstrdup(arg));
  else
    fprintf(stderr, "Warning: %s: Team name too long\n", arg);
  return (0);
}

int		pars_error(char *arg, char **map, t_com *func)
{
  free(map);
  free(func);
  if (arg[0] == '-')
    {
      fprintf(stderr, "Error: option %s not recognized.\n", arg);
      return (-1);
    }
  fprintf(stderr, "Error: %s value without definition flag before.\n", arg);
  return (-1);
}

t_com		*map_func()
{
  t_com		*func;

  func = xmalloc(9 * sizeof(t_com));
  func[0].com = "-p";
  func[1].com = "-x";
  func[2].com = "-y";
  func[3].com = "-n";
  func[4].com = "-c";
  func[5].com = "-t";
  func[6].com = "-a";
  func[7].com = "-w";
  func[8].com = NULL;
  func[0].ptr = set_port;
  func[1].ptr = set_x;
  func[2].ptr = set_y;
  func[3].ptr = set_team;
  func[4].ptr = set_count;
  func[5].ptr = set_delay;
  func[6].ptr = set_asking;
  func[7].ptr = set_wait;
  func[8].ptr = NULL;
  return (func);
}

int		parse_com(char **argv, t_zap *data)
{
  int		i;
  e_state	state;
  char		**map;
  t_com		*func;

  i = 0;
  state = NONE;
  map = stwt("-p -x -y -n -c -t -a -w", " ", -1);
  func = map_func();
  while (argv[++i] != NULL)
    {
      if (argv[i][0] == '-')
	{
	  if ((state = my_strstr(map, argv[i])) == NONE)
	    return (pars_error(argv[i], map, func));
	}
      else if (state == NONE)
	return (pars_error(argv[i], map, func));
      else if (func[find_ptr(func, map[state])].
	       ptr(data, argv[i], &state) == -1)
	return (-1);
    }
  free(map);
  free(func);
  return (base_value(data));
}
