//
// Timeval.hh for Timeval in /home/lopez_t/BMail
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Sat Jun 20 14:23:27 2015 Thibaut Lopez
// Last update Sat Jun 20 15:58:01 2015 Thibaut Lopez
//

#ifndef	TIMEVAL_HH
#define	TIMEVAL_HH

typedef	struct timeval	t_tv;

#include <iostream>
#include <string>
#include <sys/time.h>

class	Timeval
{
private:
  t_tv			_tv;
public:
  Timeval();
  Timeval(time_t, suseconds_t);
  Timeval(Timeval const &);
  virtual ~Timeval();
  time_t		getSec() const;
  suseconds_t		getUSec() const;
  t_tv			getTV() const;
  virtual Timeval const	&operator=(Timeval const &);
  Timeval		&operator+=(time_t);
  Timeval		&operator-=(time_t);
  void			add(time_t, suseconds_t);
  void			sub(time_t, suseconds_t);
  int			cmp(Timeval const &);
};

#endif
