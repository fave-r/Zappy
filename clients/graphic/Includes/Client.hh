//
// Client.hh for Client in /home/lopez_t/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Tue Jun 09 17:40:56 2015 Thibaut Lopez
// Last update Tue Jun 23 15:08:15 2015 Thibaut Lopez
//

#ifndef	CLIENT_HH
#define	CLIENT_HH

#include <signal.h>
#include "Map.hh"
#include "Command.hh"
#include "Socket.hh"
#include "Timeval.hh"

class		Client
{
private:
  Socket	_s;
  fd_set	_rbf;
  fd_set	_wbf;
  Timeval	_tv;
  void		_update();
public:
  Client();
  Client(const std::string &, const std::string &);
  virtual ~Client();
  void		Connect(const std::string &, const std::string &);
  void		run(Map &);
};

#endif
