/*
** cone_y.c for cone_y in /home/lopez_t/Zappy/src/client
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Wed May 13 11:30:12 2015 Thibaut Lopez
** Last update Wed May 13 11:31:29 2015 Thibaut Lopez
*/

#include "server.h"

void		north_cone_end(t_pair *cone, t_user *usr)
{
  cone[9].f = usr->x - 3;
  cone[9].s = usr->y - 4;
  cone[10].f = usr->x - 2;
  cone[10].s = usr->y - 4;
  cone[11].f = usr->x - 1;
  cone[11].s = usr->y - 4;
  cone[12].f = usr->x;
  cone[12].s = usr->y - 4;
  cone[13].f = usr->x + 1;
  cone[13].s = usr->y - 4;
  cone[14].f = usr->x + 2;
  cone[14].s = usr->y - 4;
  cone[15].f = usr->x + 3;
  cone[15].s = usr->y - 4;
}

void		north_cone(t_pair *cone, t_user *usr)
{
  cone[0].f = usr->x;
  cone[0].s = usr->y - 1;
  cone[1].f = usr->x - 1;
  cone[1].s = usr->y - 2;
  cone[2].f = usr->x;
  cone[2].s = usr->y - 2;
  cone[3].f = usr->x + 1;
  cone[3].s = usr->y - 2;
  cone[4].f = usr->x - 2;
  cone[4].s = usr->y - 3;
  cone[5].f = usr->x - 1;
  cone[5].s = usr->y - 3;
  cone[6].f = usr->x;
  cone[6].s = usr->y - 3;
  cone[7].f = usr->x + 1;
  cone[7].s = usr->y - 3;
  cone[8].f = usr->x + 2;
  cone[8].s = usr->y - 3;
  north_cone_end(cone, usr);
}

void		south_cone_end(t_pair *cone, t_user *usr)
{
  cone[9].f = usr->x + 3;
  cone[9].s = usr->y + 4;
  cone[10].f = usr->x + 2;
  cone[10].s = usr->y + 4;
  cone[11].f = usr->x + 1;
  cone[11].s = usr->y + 4;
  cone[12].f = usr->x;
  cone[12].s = usr->y + 4;
  cone[13].f = usr->x - 1;
  cone[13].s = usr->y + 4;
  cone[14].f = usr->x - 2;
  cone[14].s = usr->y + 4;
  cone[15].f = usr->x - 3;
  cone[15].s = usr->y + 4;
}

void		south_cone(t_pair *cone, t_user *usr)
{
  cone[0].f = usr->x;
  cone[0].s = usr->y + 1;
  cone[1].f = usr->x + 1;
  cone[1].s = usr->y + 2;
  cone[2].f = usr->x;
  cone[2].s = usr->y + 2;
  cone[3].f = usr->x - 1;
  cone[3].s = usr->y + 2;
  cone[4].f = usr->x + 2;
  cone[4].s = usr->y + 3;
  cone[5].f = usr->x + 1;
  cone[5].s = usr->y + 3;
  cone[6].f = usr->x;
  cone[6].s = usr->y + 3;
  cone[7].f = usr->x - 1;
  cone[7].s = usr->y + 3;
  cone[8].f = usr->x - 2;
  cone[8].s = usr->y + 3;
  south_cone_end(cone, usr);
}
