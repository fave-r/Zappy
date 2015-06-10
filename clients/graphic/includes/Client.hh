//
// Client.hh for Client in /home/lopez_t/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Tue Jun 09 17:40:56 2015 Thibaut Lopez
// Last update Wed Jun 10 13:17:14 2015 Thibaut Lopez
//

#ifndef	CLIENT_HH
#define	CLIENT_HH

#include <signal.h>
#include "Map.hh"
#include "Socket.hh"

typedef struct	timeval t_tv;

class		Client
{
private:
  Socket	_s;
  fd_set	_rbf;
  fd_set	_wbf;
  t_tv		_tv;
public:
  Client();
  Client(const std::string &, const std::string &);
  virtual ~Client();
  void		Connect(const std::string &, const std::string &);
  void		run(Map &);
};

#endif
