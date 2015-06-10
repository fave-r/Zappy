//
// main.cpp for zappy in /home/fave_r/rendu/Zappy/clients/graphic/src
//
// Made by romaric
// Login   <fave_r@epitech.net>
//
// Started on  Mon Jun  8 13:02:03 2015 romaric
// Last update Wed Jun 10 18:34:02 2015 Thibaut Lopez
//

#include "Client.hh"
#include "Menu.hh"

int	main(int ac, char **av)
{
  Client	clt("127.0.0.1", "6667");
  Map		map;
  Menu		menu;

  (void)ac;
  (void)av;
  (void)menu;
  clt.run(map);
  return (0);
}
