// main.cpp for zappy in /home/fave_r/rendu/Zappy/clients/graphic/src
//
// Made by romaric
// Login   <fave_r@epitech.net>
//
// Started on  Mon Jun  8 13:02:03 2015 romaric
// Last update Sat Jul  4 22:40:46 2015 Leo Thevenet
//

#include "Client.hh"
#include "Menu.hh"

int	main()
{
  std::pair<std::string, std::string>	con;
  Client	clt;
  Map		map;
  Menu		*menu;

  try
    {
      menu = new Menu();
      con = menu->run(map);
      delete menu;
      clt.Connect(con.first, con.second);
    }
  catch (std::runtime_error &err)
    {
      std::cerr << "Error: " << err.what() <<std::endl;
      return (1);
    }
  catch (std::exception &err)
    {
      return (0);
    }
  clt.run(map);
  return (0);
}
