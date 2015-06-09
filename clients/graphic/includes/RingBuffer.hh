//
// RingBuffer.hh for RingBuffer in /home/lopez_t/BONUS/CircularBuffer
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Mon Jun 08 13:43:12 2015 Thibaut Lopez
// Last update Tue Jun  9 16:45:49 2015 Thibaut Lopez
//

#ifndef	RINGBUFFER_HH
#define	RINGBUFFER_HH

#include <string.h>
#include "Socket.hh"

class	RingBuffer
{
private:
  char		*_buff;
  size_t	_cap;
  size_t	_beg;
  size_t	_end;

  size_t	_taken() const;
  size_t	_available() const;
  char		*_getBegin() const;
  char		*_getEnd() const;
public:
  RingBuffer();
  RingBuffer(const size_t);
  virtual ~RingBuffer();
  void		flush();
  void		extend(const size_t);
  void		fill(const std::string &);
  std::string	extract(size_t);
  int		find(const char &) const;
  std::string	getLine();
  int		Read(int, const size_t &);
  int		Read(Socket &, const size_t &);
  int		Write(int);
  int		Write(Socket &);
};

#endif
