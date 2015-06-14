//
// main.cpp for zappy in /home/fave_r/rendu/Zappy/clients/graphic/src
//
// Made by romaric
// Login   <fave_r@epitech.net>
//
// Started on  Mon Jun  8 13:02:03 2015 romaric
// Last update Sun Jun 14 19:42:47 2015 Thibaut Lopez
//

#include "Client.hh"
#include "Menu.hh"

int	main(int ac, char **av)
{
  std::pair<std::string, std::string>	con;
  Client	clt;
  Map		map;
  Menu		*menu;

  (void)ac;
  (void)av;
  menu = new Menu();
  con = menu->run(map);
  delete menu;
  clt.Connect(con.first, con.second);
  clt.run(map);
  return (0);
}
