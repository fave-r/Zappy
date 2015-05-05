/*
** parser.c for parser in /home/lopez_t/Zappy
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Tue May  5 16:43:22 2015 Thibaut Lopez
** Last update Tue May  5 19:26:30 2015 Thibaut Lopez
*/

enum e_parser
  {
    P = 0,
    X,
    Y,
    N,
    C,
    T,
    NONE
  };

char		**map_state()
{
  int		i;
  char		**map;

  map = xmalloc(7 * sizeof(char *) + 6 * 3 * sizeof(char));
  i = 0;
  while (i < 6)
    {
      map[i] = map[i] + (6 * sizeof(char *)) + i * 3 * sizeof(char);
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
}

int		parse_com(char **argv)
{
  int		i;
  e_parser	state;
  char		**map;

  i = 1;
  state = NONE;
  map = map_state();
  while (argv[i] != NULL)
    {
      if (argv[i][0] == '-')
	{
	  if ((state = my_strstr(map, argv[i])) == NONE)
	    return (i);
	}
      else if (state == NONE)
	return (i);
      
      i++;
    }
  free(map);
  return (0);
}
