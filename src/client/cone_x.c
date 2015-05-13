/*
** cone_x.c for cone_x in /home/lopez_t/Zappy/src/client
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Wed May 13 10:36:48 2015 Thibaut Lopez
** Last update Wed May 13 11:31:41 2015 Thibaut Lopez
*/

#include "server.h"

void		east_cone_end(t_pair *cone, t_user *usr)
{
  cone[9].f = usr->x + 4;
  cone[9].s = usr->y - 3;
  cone[10].f = usr->x + 4;
  cone[10].s = usr->y - 2;
  cone[11].f = usr->x + 4;
  cone[11].s = usr->y - 1;
  cone[12].f = usr->x + 4;
  cone[12].s = usr->y;
  cone[13].f = usr->x + 4;
  cone[13].s = usr->y + 1;
  cone[14].f = usr->x + 4;
  cone[14].s = usr->y + 2;
  cone[15].f = usr->x + 4;
  cone[15].s = usr->y + 3;
}

void		east_cone(t_pair *cone, t_user *usr)
{
  cone[0].f = usr->x + 1;
  cone[0].s = usr->y;
  cone[1].f = usr->x + 2;
  cone[1].s = usr->y - 1;
  cone[2].f = usr->x + 2;
  cone[2].s = usr->y;
  cone[3].f = usr->x + 2;
  cone[3].s = usr->y + 1;
  cone[4].f = usr->x + 3;
  cone[4].s = usr->y - 2;
  cone[5].f = usr->x + 3;
  cone[5].s = usr->y - 1;
  cone[6].f = usr->x + 3;
  cone[6].s = usr->y;
  cone[7].f = usr->x + 3;
  cone[7].s = usr->y + 1;
  cone[8].f = usr->x + 3;
  cone[8].s = usr->y + 2;
  east_cone_end(cone, usr);
}

void		west_cone_end(t_pair *cone, t_user *usr)
{
  cone[9].f = usr->x - 4;
  cone[9].s = usr->y + 3;
  cone[10].f = usr->x - 4;
  cone[10].s = usr->y + 2;
  cone[11].f = usr->x - 4;
  cone[11].s = usr->y + 1;
  cone[12].f = usr->x - 4;
  cone[12].s = usr->y;
  cone[13].f = usr->x - 4;
  cone[13].s = usr->y - 1;
  cone[14].f = usr->x - 4;
  cone[14].s = usr->y - 2;
  cone[15].f = usr->x - 4;
  cone[15].s = usr->y - 3;
}

void		west_cone(t_pair *cone, t_user *usr)
{
  cone[0].f = usr->x - 1;
  cone[0].s = usr->y;
  cone[1].f = usr->x - 2;
  cone[1].s = usr->y + 1;
  cone[2].f = usr->x - 2;
  cone[2].s = usr->y;
  cone[3].f = usr->x - 2;
  cone[3].s = usr->y - 1;
  cone[4].f = usr->x - 3;
  cone[4].s = usr->y + 2;
  cone[5].f = usr->x - 3;
  cone[5].s = usr->y + 1;
  cone[6].f = usr->x - 3;
  cone[6].s = usr->y;
  cone[7].f = usr->x - 3;
  cone[7].s = usr->y - 1;
  cone[8].f = usr->x - 3;
  cone[8].s = usr->y - 2;
  east_cone_end(cone, usr);
}
