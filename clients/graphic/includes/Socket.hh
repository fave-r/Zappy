//
// Socket.hh for Socket in /home/lopez_t/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Tue Jun 09 15:30:29 2015 Thibaut Lopez
// Last update Tue Jun  9 16:17:44 2015 Thibaut Lopez
//

#ifndef	SOCKET_HH
#define	SOCKET_HH

#include <iostream>
#include <string>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdexcept>

class	Socket
{
private:
  int	_fd;
public:
  Socket();
  Socket(int);
  Socket(const std::string &, const std::string &);
  virtual ~Socket();
  void	Connect(const std::string &, const std::string &);
  void	set(fd_set *);
  int	isset(fd_set *);
};

#endif
