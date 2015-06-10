//
// main.cpp for zappy in /home/fave_r/rendu/Zappy/clients/graphic/src
//
// Made by romaric
// Login   <fave_r@epitech.net>
//
// Started on  Mon Jun  8 13:02:03 2015 romaric
// Last update Wed Jun 10 15:03:30 2015 Thibaut Lopez
//

#include "Client.hh"

int	main(int ac, char **av)
{
  Client	clt("127.0.0.1", "6667");
  Map		map;

  (void)ac;
  (void)av;
  clt.run(map);
  return (0);
}
