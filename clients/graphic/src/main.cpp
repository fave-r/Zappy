//
// main.cpp for zappy in /home/fave_r/rendu/Zappy/clients/graphic/src
//
// Made by romaric
// Login   <fave_r@epitech.net>
//
// Started on  Mon Jun  8 13:02:03 2015 romaric
// Last update Thu Jun 11 11:29:31 2015 Thibaut Lopez
//

#include "Client.hh"
#include "Menu.hh"

int	main(int ac, char **av)
{
  Client	clt;
  Map		map;
  Menu		menu;

  (void)ac;
  (void)av;
  (void)menu;
  menu.run(map);
  clt.Connect("127.0.0.1", "6667");
  clt.run(map);
  return (0);
}
