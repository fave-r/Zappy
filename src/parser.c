/*
** parser.c for parser in /home/lopez_t/Zappy
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Tue May  5 16:43:22 2015 Thibaut Lopez
** Last update Mon May 25 16:29:16 2015 Thibaut Lopez
*/

#include "server.h"

int		set_team(t_zap *data, char *arg, e_state *state)
{
  (void)state;
  if (strlen(arg) < 200)
    data->team = sstrcat(data->team, xstrdup(arg));
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

char		**map_state()
{
  int		i;
  char		**map;

  map = xmalloc(7 * sizeof(char *) + 6 * 3 * sizeof(char));
  i = 0;
  while (i < 6)
    {
      map[i] = (char *)map + (7 * sizeof(char *)) + i * 3 * sizeof(char);
      i++;
    }
  strcpy(map[0], "-p");
  map[0][2] = 0;
  strcpy(map[1], "-x");
  map[1][2] = 0;
  strcpy(map[2], "-y");
  map[2][2] = 0;
  strcpy(map[3], "-n");
  map[3][2] = 0;
  strcpy(map[4], "-c");
  map[4][2] = 0;
  strcpy(map[5], "-t");
  map[5][2] = 0;
  map[6] = NULL;
  return (map);
}

t_com		*map_func()
{
  t_com		*func;

  func = xmalloc(7 * sizeof(t_com));
  func[0].com = "-p";
  func[1].com = "-x";
  func[2].com = "-y";
  func[3].com = "-n";
  func[4].com = "-c";
  func[5].com = "-t";
  func[6].com = NULL;
  func[0].ptr = set_port;
  func[1].ptr = set_x;
  func[2].ptr = set_y;
  func[3].ptr = set_team;
  func[4].ptr = set_count;
  func[5].ptr = set_delay;
  func[6].ptr = NULL;
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
  map = map_state();
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
