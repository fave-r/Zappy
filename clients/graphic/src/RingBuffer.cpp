//
// RingBuffer.cpp for RingBuffer in /home/lopez_t/BONUS/CircularBuffer
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Mon Jun 08 13:43:12 2015 Thibaut Lopez
// Last update Tue Jun  9 18:10:48 2015 Thibaut Lopez
//

#include "RingBuffer.hh"

RingBuffer::RingBuffer()
  : _buff(new char[4096]), _cap(4096), _beg(0), _end(0)
{
}

RingBuffer::RingBuffer(const size_t cap)
  : _buff(new char[cap]), _cap(cap), _beg(0), _end(0)
{
}

RingBuffer::~RingBuffer()
{
  delete this->_buff;
}

size_t		RingBuffer::_taken() const
{
  if (this->_beg <= this->_end)
    return (this->_end - this->_beg);
  else
    return (this->_cap - (this->_beg - this->_end));
}

size_t		RingBuffer::_available() const
{
  if (this->_beg > this->_end)
    return (this->_beg - this->_end - 1);
  else
    return (this->_cap - (this->_end - this->_beg) - 1);
}

char		*RingBuffer::_getBegin() const
{
  return (this->_buff + this->_beg);
}

char		*RingBuffer::_getEnd() const
{
  return (this->_buff + this->_end);
}

void		RingBuffer::flush()
{
  memset(this->_buff, 0, this->_cap);
  this->_beg = 0;
  this->_end = 0;
}

void		RingBuffer::extend(const size_t len)
{
  char		*buff;
  size_t	old;

  if (this->_cap >= len)
    return ;
  old = this->_taken();
  buff = new char[len + 51];
  memset(buff, 0, len + 51);
  if (this->_beg < this->_end)
    memcpy(buff, this->_getBegin(), old);
  else
    {
      memcpy(buff, this->_getBegin(), (this->_cap - this->_beg));
      memcpy(buff + (this->_cap - this->_beg), this->_buff, (old - this->_cap + this->_beg));
    }
  this->_beg = 0;
  this->_end = old;
  delete this->_buff;
  this->_buff = buff;
  this->_cap = len + 50;
}

void		RingBuffer::fill(const std::string &to_add)
{
  size_t	len;

  len = to_add.size();
  if (this->_available() < len)
    this->extend(this->_cap + len);
  if (len < this->_cap - this->_end)
    memcpy(this->_getEnd(), to_add.c_str(), len);
  else
    {
      memcpy(this->_getEnd(), to_add.c_str(), this->_cap - this->_end);
      memcpy(this->_buff, to_add.substr(this->_cap - this->_end, std::string::npos).c_str(), len - this->_cap + this->_end);
    }
  this->_end += len;
  this->_end %= this->_cap;
}

std::string	RingBuffer::extract(size_t len)
{
  std::string	buff("");

  if (this->_beg == this->_end)
    return ("");
  else if (this->_taken() < len)
    len = this->_taken();
  if (this->_beg < this->_end || this->_cap - this->_beg >= len)
    buff.append(this->_getBegin(), len);
  else
    {
      buff.append(this->_getBegin(), this->_cap - this->_beg);
      buff.append(this->_buff, len - this->_cap + this->_beg);
    }
  this->_beg += len;
  this->_beg %= this->_cap + 1;
  return (buff);
}

int		RingBuffer::find(const char &c) const
{
  int		i;

  i = this->_beg;
  while (i % this->_cap != this->_end && this->_buff[i % this->_cap] != c)
    i++;
  if (i % this->_cap == this->_end)
    return (-1);
  return (i - this->_beg);
}

std::string	RingBuffer::getLine()
{
  int		ret;
  std::string	str("");

  if ((ret = this->find('\r')) != -1 || (ret = this->find('\n')) != -1)
    str.append(this->extract(static_cast<size_t>(ret + 1)));
  return (str);
}

int		RingBuffer::Read(int fd, const size_t &size)
{
  int		rl;
  char		*str;

  str = new char[size + 1];
  rl = read(fd, str, size);
  str[rl] = 0;
  if (rl > 0)
    this->fill(str);
  delete str;
  return (rl);
}

int		RingBuffer::Write(int fd)
{
  int		wl;
  std::string	str;

  str = this->extract(this->_taken());
  wl = write(fd, str.c_str(), str.size());
  if ((int)str.size() != wl && wl >= 0)
    this->fill(str.substr(wl));
  return (wl);
}
