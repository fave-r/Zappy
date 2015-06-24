//
// Socket.hh for Socket in /home/lopez_t/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Tue Jun 09 15:30:29 2015 Thibaut Lopez
// Last update Tue Jun  9 19:44:13 2015 Thibaut Lopez
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
#include <stdexcept>
#include "RingBuffer.hh"

class	Socket
{
private:
  int			_s;
  RingBuffer		_in;
  RingBuffer		_out;
public:
  Socket();
  Socket(int);
  Socket(const std::string &, const std::string &);
  virtual ~Socket();
  int			getFD() const;
  void			Connect(const std::string &, const std::string &);
  void			set(fd_set *, fd_set *) const;
  int			isset(fd_set *) const;
  int			Read(const size_t &);
  int			Write();
  const std::string	getLine();
  void			fill(const std::string &);
};

#endif
