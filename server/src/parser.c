/*
** parser.c for parser in /home/lopez_t/Zappy
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Tue May  5 16:43:22 2015 Thibaut Lopez
** Last update Sat Jul  4 14:23:53 2015 Thibaut Lopez
*/

#include "server.h"

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

  if ((func = malloc(10 * sizeof(t_com))) == NULL)
    return (NULL);
  func[0].com = "-p";
  func[1].com = "-x";
  func[2].com = "-y";
  func[3].com = "-n";
  func[4].com = "-c";
  func[5].com = "-t";
  func[6].com = "-a";
  func[7].com = "-w";
  func[8].com = "-v";
  func[9].com = NULL;
  func[0].ptr = set_port;
  func[1].ptr = set_x;
  func[2].ptr = set_y;
  func[3].ptr = set_team;
  func[4].ptr = set_count;
  func[5].ptr = set_delay;
  func[6].ptr = set_asking;
  func[7].ptr = set_wait;
  func[8].ptr = set_verbose;
  func[9].ptr = NULL;
  return (func);
}

int		parse_loop(char **argv, t_zap *data, char **map, t_com *func)
{
  int		i;
  e_state	state;

  i = 0;
  state = NONE;
  while (argv[++i] != NULL)
    {
      if (argv[i][0] == '-')
	{
	  if ((state = my_strstr(map, argv[i])) == NONE)
	    return (pars_error(argv[i], map, func));
	}
      else if (state == NONE || state == H)
	return (pars_error(argv[i], map, func));
      else if (func[find_ptr(func, map[state])].
	       ptr(data, argv[i], &state) == -1)
	return (-1);
    }
  return (0);
}

int		parse_com(char **argv, t_zap *data)
{
  char		**map;
  t_com		*func;
  int		ret;

  if ((map = stwt("-p -x -y -n -c -t -a -w -v -h", " ", -1)) == NULL)
    return (-1);
  if ((func = map_func()) == NULL)
    {
      free(map);
      return (-1);
    }
  ret = parse_loop(argv, data, map, func);
  free(map);
  free(func);
  return ((ret != 0) ? ret : base_value(data));
}
