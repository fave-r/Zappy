//
// Socket.cpp for Socket in /home/lopez_t/Zappy/clients/graphic
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Tue Jun 09 15:30:29 2015 Thibaut Lopez
// Last update Wed Jun 17 18:41:40 2015 Thibaut Lopez
//

#include "Socket.hh"

Socket::Socket()
  : _s(-1)
{
}

Socket::Socket(int fd)
  : _s(fd)
{
}

Socket::Socket(const std::string &ip, const std::string &port)
  : _s(-1)
{
  this->Connect(ip, port);
}

Socket::~Socket()
{
  if (this->_s > 2)
    close(this->_s);
}

int			Socket::getFD() const
{
  return (this->_s);
}

void			Socket::Connect(const std::string &ip, const std::string &sPort)
{
  int			port;
  size_t		idx;
  struct protoent	*pe;
  struct sockaddr_in	sin;
  struct hostent	*he;

  if (this->_s >= 2)
    {
      close(this->_s);
      this->_in.flush();
      this->_out.flush();
    }
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
  this->_s = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  if (this->_s == -1)
    throw std::runtime_error("Socket fail.");
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  if ((he = gethostbyname(ip.c_str())) == NULL)
    throw std::runtime_error(ip + ": No such IP or hostname.");
  memcpy(&sin.sin_addr, he->h_addr_list[0], he->h_length);
  if (connect(this->_s, reinterpret_cast<const struct sockaddr *>(&sin), sizeof(sin)) == -1)
    throw std::runtime_error("Connect fail.");
}

void			Socket::set(fd_set *rbf, fd_set *wbf) const
{
  if (this->_s == -1)
    throw std::runtime_error("Socket not open.");
  FD_SET(this->_s, rbf);
  if (this->_out.taken() > 0)
    FD_SET(this->_s, wbf);
}

int			Socket::isset(fd_set *set) const
{
  if (this->_s == -1)
    throw std::runtime_error("Socket not open.");
  return (FD_ISSET(this->_s, set));
}

int			Socket::Read(const size_t &size)
{
  if (this->_s == -1)
    throw std::runtime_error("Socket not open.");
  return (this->_in.Read(this->_s, size));
}

int			Socket::Write()
{
  if (this->_s == -1)
    throw std::runtime_error("Socket not open.");
  return (this->_out.Write(this->_s));
}

const std::string	Socket::getLine()
{
  return (this->_in.getLine());
}

void			Socket::fill(const std::string &to_add)
{
  this->_out.fill(to_add);
}
