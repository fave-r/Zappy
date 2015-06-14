//
// Client.cpp for Client in /home/lopez_t/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Tue Jun 09 17:40:56 2015 Thibaut Lopez
// Last update Thu Jun 11 11:28:27 2015 Thibaut Lopez
//

#include "Client.hh"

sig_atomic_t	signaled = 0;

Client::Client()
{
}

Client::Client(const std::string &ip, const std::string &port)
  : _s(ip, port)
{
}

Client::~Client()
{
}

void		Client::Connect(const std::string &ip, const std::string &port)
{
  this->_s.Connect(ip, port);
}

void		quit_signal(int signo)
{
  (void)signo;
  signaled = 1;
}

void		Client::run(Map &map)
{
  std::string	str;
  Command	com;

  signal(SIGINT, quit_signal);
  FD_ZERO(&this->_rbf);
  FD_ZERO(&this->_wbf);
  while (signaled == 0)
    {
      this->_tv.tv_sec = 0;
      this->_tv.tv_usec = 10000;
      this->_s.set(&this->_rbf, &this->_wbf);
      if (select(this->_s.getFD() + 1, &this->_rbf, &this->_wbf, NULL, &this->_tv) != -1)
	{
	  if (this->_s.isset(&this->_rbf))
	    this->_s.Read(499);
	  if (this->_s.isset(&this->_wbf))
	    this->_s.Write();
	}
      str = this->_s.getLine();
      if (str.size() > 0 && str.find_first_of("\n\r") > 0)
	try
	  {
	    com.thiscom(str, map, this->_s);
	  }
	catch (std::out_of_range &err)
	  {
	  }
      map.handleKeys();
    }
}
