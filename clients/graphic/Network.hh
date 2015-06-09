//
// Network.hh for Network in /home/lopez_t/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Tue Jun 09 11:58:14 2015 Thibaut Lopez
// Last update Tue Jun  9 12:13:30 2015 Thibaut Lopez
//

#ifndef	NETWORK_HH
#define	NETWORK_HH

#include <iostream>
#include <string>

class	Network
{
private:
  int		fd;
  RingBuffer	in;
  RingBuffer	out;
public:
  Network(const std::string &, const std::string &);
  virtual ~Network();
};

#endif
