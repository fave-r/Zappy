//
// RingBuffer.hh for RingBuffer in /home/lopez_t/BONUS/CircularBuffer
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Mon Jun 08 13:43:12 2015 Thibaut Lopez
// Last update Mon Jun  8 17:09:51 2015 Thibaut Lopez
//

#ifndef	RINGBUFFER_HH
#define	RINGBUFFER_HH

#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>

class	RingBuffer
{
private:
  char		*_buff;
  size_t	_cap;
  size_t	_beg;
  size_t	_end;

  size_t	_taken();
  size_t	_available();
  char		*_getBegin();
  char		*_getEnd();
public:
  RingBuffer();
  RingBuffer(size_t);
  virtual ~RingBuffer();
  void		flush();
  void		extend(size_t);
  void		fill(std::string);
  std::string	extract(size_t);
  size_t	find(char);
  std::string	getLine();
  int		Read(int, size_t);
  int		Write(int);
};

#endif
