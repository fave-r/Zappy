//
// Client.cpp for Client in /home/lopez_t/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Tue Jun 09 17:40:56 2015 Thibaut Lopez
// Last update Tue Jun 23 15:10:51 2015 Thibaut Lopez
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

void		Client::_update()
{
  t_tv		tv;

  FD_ZERO(&this->_rbf);
  FD_ZERO(&this->_wbf);
  this->_tv = Timeval(0, 10000);
  tv = this->_tv.getTV();
  this->_s.set(&this->_rbf, &this->_wbf);
  if (select(this->_s.getFD() + 1, &this->_rbf, &this->_wbf, NULL, &tv) != -1)
    {
      if (this->_s.isset(&this->_rbf))
	this->_s.Read(499);
      if (this->_s.isset(&this->_wbf))
	this->_s.Write();
    }
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
  while (signaled == 0)
    {
      this->_update();
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