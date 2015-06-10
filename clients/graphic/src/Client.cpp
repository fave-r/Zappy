//
// Client.cpp for Client in /home/lopez_t/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Tue Jun 09 17:40:56 2015 Thibaut Lopez
// Last update Wed Jun 10 10:40:07 2015 Thibaut Lopez
//

#include "Client.hh"

sig_atomic_t	signaled = 0;

Client::Client()
  : _stdin(0), _s("127.0.0.1", "6667")
{
  this->_tv.tv_sec = 0;
  this->_tv.tv_usec = 5000;
}

Client::Client(const std::string &ip, const std::string &port)
  : _stdin(0), _s(ip, port)
{
  this->_tv.tv_sec = 0;
  this->_tv.tv_usec = 5000;
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
  (void)map;
  signal(SIGINT, quit_signal);
  while (signaled == 0)
    {
      FD_ZERO(&this->_rbf);
      FD_ZERO(&this->_wbf);
      this->_stdin.set(&this->_rbf, &this->_wbf);
      this->_s.set(&this->_rbf, &this->_wbf);
      if ((signaled = select(this->_s.getFD() + 1, &this->_rbf, &this->_wbf, NULL, &this->_tv)) != -1)
	{

	}
    }
}
