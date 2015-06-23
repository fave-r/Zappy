//
// Timeval.cpp for Timeval in /home/lopez_t/BMail
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Sat Jun 20 14:23:27 2015 Thibaut Lopez
// Last update Sun Jun 21 14:45:39 2015 Thibaut Lopez
//

#include "Timeval.hh"

Timeval::Timeval()
{
  gettimeofday(&this->_tv, NULL);
}

Timeval::Timeval(time_t sec, suseconds_t usec)
{
  this->_tv.tv_sec = sec;
  this->_tv.tv_usec = usec;
}

Timeval::Timeval(Timeval const &cpy)
{
  this->_tv.tv_sec = cpy.getSec();
  this->_tv.tv_usec = cpy.getUSec();
}

Timeval::~Timeval()
{
}

time_t		Timeval::getSec() const
{
  return (this->_tv.tv_sec);
}

suseconds_t	Timeval::getUSec() const
{
  return (this->_tv.tv_usec);
}

t_tv		Timeval::getTV() const
{
  return (this->_tv);
}

Timeval const	&Timeval::operator=(Timeval const &cpy)
{
  if (&cpy != this)
    {
      this->_tv.tv_sec = cpy.getSec();
      this->_tv.tv_usec = cpy.getUSec();
    }
  return (*this);
}

Timeval		&Timeval::operator+=(time_t toAdd)
{
  this->add(toAdd / 1000000, toAdd % 1000000);
  return (*this);
}

Timeval		&Timeval::operator-=(time_t toSub)
{
  this->sub(toSub / 1000000, toSub % 1000000);
  return (*this);
}

void		Timeval::add(time_t secAdd, suseconds_t usecAdd)
{
  this->_tv.tv_sec += secAdd;
  this->_tv.tv_usec += usecAdd;
  if (this->_tv.tv_usec > 1000000)
    {
      this->_tv.tv_sec++;
      this->_tv.tv_usec %= 1000000;
    }
}

void		Timeval::sub(time_t secSub, suseconds_t usecSub)
{
  this->_tv.tv_sec -= secSub;
  this->_tv.tv_usec -= usecSub;
  if (this->_tv.tv_usec < 0)
    {
      this->_tv.tv_sec--;
      this->_tv.tv_usec += 1000000;
    }
}

int		Timeval::cmp(Timeval const &toCmp)
{
  if (this->_tv.tv_sec > toCmp.getSec())
    return (1);
  if (this->_tv.tv_sec < toCmp.getSec())
    return (-1);
  if (this->_tv.tv_usec > toCmp.getUSec())
    return (1);
  if (this->_tv.tv_usec < toCmp.getUSec())
    return (-1);
  return (0);
}
