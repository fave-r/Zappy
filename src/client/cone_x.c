/*
** cone_x.c for cone_x in /home/lopez_t/Zappy/src/client
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Wed May 13 10:36:48 2015 Thibaut Lopez
** Last update Wed May 13 15:27:46 2015 Thibaut Lopez
*/

#include "server.h"

void		east_gofo(t_pair *cone, int forward)
{
  cone->f += forward;
}

void		east_gole(t_pair *cone, int left)
{
  cone->s -= left;
}

void		west_gofo(t_pair *cone, int forward)
{
  cone->f -= forward;
}

void		west_gole(t_pair *cone, int left)
{
  cone->s += left;
}
