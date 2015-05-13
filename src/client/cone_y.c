/*
** cone_y.c for cone_y in /home/lopez_t/Zappy/src/client
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Wed May 13 11:30:12 2015 Thibaut Lopez
** Last update Wed May 13 15:28:20 2015 Thibaut Lopez
*/

#include "server.h"

void		north_gofo(t_pair *cone, int forward)
{
  cone->s -= forward;
}

void		north_gole(t_pair *cone, int left)
{
  cone->f -= left;
}

void		south_gofo(t_pair *cone, int forward)
{
  cone->s += forward;
}

void		south_gole(t_pair *cone, int left)
{
  cone->f += left;
}
