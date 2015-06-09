//
// Socket.cpp for Socket in /home/lopez_t/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Tue Jun 09 15:30:29 2015 Thibaut Lopez
// Last update Tue Jun  9 16:17:57 2015 Thibaut Lopez
//

#include "Socket.hh"

Socket::Socket()
  : _fd(-1)
{
}

Socket::Socket(int fd)
  : _fd(fd)
{
}

Socket::Socket(const std::string &ip, const std::string &port)
  : _fd(-1)
{
  this->Connect(ip, port);
}

Socket::~Socket()
{
  if (this->_fd > 2)
    close(this->_fd);
}

void	Socket::Connect(const std::string &ip, const std::string &sPort)
{
  int			port;
  size_t		idx;
  struct protoent	*pe;
  struct sockaddr_in	sin;

  idx = 0;
  try
    {
      port = std::stoi(sPort, &idx);
    }
  catch (std::invalid_argument &err)
    {
      std::cerr << "Invalid port: taking by default 6667" << std::endl;
      port = 6667;
    }
  catch (std::out_of_range &err)
    {
      std::cerr << "Invalid port: taking by default 6667" << std::endl;
      port = 6667;
    }
  if (idx != sPort.size())
    {
      std::cerr << "Invalid port: taking by default 6667" << std::endl;
      port = 6667;
    }
  pe = getprotobyname("TCP");
  this->_fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  if (this->_fd == -1)
    throw std::runtime_error("Socket fail.");
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  sin.sin_addr.s_addr = inet_addr(ip.c_str());
  if (connect(this->_fd, reinterpret_cast<const struct sockaddr *>(&sin), sizeof(sin)) == -1)
    throw std::runtime_error("Connect fail.");
}

void	Socket::set(fd_set *set)
{
  FD_SET(this->_fd, set);
}

int	Socket::isset(fd_set *set)
{
  return (FD_ISSET(this->_fd, set));
}
