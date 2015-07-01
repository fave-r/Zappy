/*
** manage.c for manage in /home/lopez_t/BONUS/Zappy/src
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Mon Jun  1 11:28:59 2015 Thibaut Lopez
** Last update Tue Jun 30 20:08:02 2015 Thibaut Lopez
*/

#include "server.h"

int		check_food(t_user *usr, t_zap *data)
{
  t_tv		tv;
  t_tv		tmp;
  t_tv		time;
  t_tv		now;

  if (GET_GHOST(usr) == 1)
    return (0);
  gettimeofday(&tv, NULL);
  now.tv_sec = tv.tv_sec;
  now.tv_usec = tv.tv_usec;
  timersub(&tv, &GET_TIME(usr), &tmp);
  time.tv_usec = 0;
  time.tv_sec = 0;
  add_tv(&time, (126000000 / data->delay));
  if (cmp_tv(&tmp, &time) == 1 || cmp_tv(&tmp, &time) == 0)
    {
      printf("%d: eat at %ld:%ld... next time %ld:%ld\n", usr->fd, now.tv_sec, now.tv_usec, tv.tv_sec, tv.tv_usec);
      GET_INV(usr).food -= 1;
      data->map[rand() % data->length][rand() % data->width].food++;
      GET_TIME(usr) = tv;
      if (GET_INV(usr).food == 0)
	{
	  usr->tokill = 1;
	  return (-1);
	}
    }
  return (0);
}

void		check_egg_time(t_egg *egg, t_tv *now, t_user *usr, t_team *teams)
{
  t_user	*new;
  char		tmp[128];

  bzero(tmp, 128);
  if (!(egg->lay.tv_sec == 0 && egg->lay.tv_usec == 0) &&
      cmp_tv(&egg->lay, now) <= 0)
    {
      sprintf(tmp, "enw #%d #%d %d %d\n",
	      egg->nb, egg->dad, egg->pos.f, egg->pos.s);
      send_to_graphic(tmp, usr);
      egg->lay.tv_sec = 0;
      egg->lay.tv_usec = 0;
      teams->count++;
    }
  else if (cmp_tv(&egg->hatch, now) <= 0)
    {
      new = (egg->son == -1) ? NULL : get_by_nb(usr, egg->son, AI);
      sprintf(tmp, (new == NULL) ? "edi #%d\n" : "eht #%d\n", egg->nb);
      if (new != NULL)
	GET_GHOST(new) = 0;
      send_to_graphic(tmp, usr);
      pop_q(&teams->eggs);
    }
}

void		check_eggs(t_team *teams, t_tv *now, t_user *usr)
{
  t_egg		*frt;
  t_egg		*prev;
  int		bool;

  while (teams != NULL)
    {
      bool = 0;
      prev = NULL;
      while (bool == 0)
	{
	  frt = front_q(teams->eggs);
	  if (frt != NULL && frt != prev)
	    check_egg_time(frt, now, usr, teams);
	  else
	    bool = 1;
	  prev = frt;
	}
      teams = teams->next;
    }
}

int		end_game(t_zap *data, t_user **user)
{
  char		str[256];
  t_user	*tmp;

  bzero(str, 256);
  sprintf(str, "seg %s\naeg\n", data->winner->name);
  tmp = *user;
  while (tmp != NULL)
    {
      if (tmp->type == GRAPHIC)
	fill_cb(&tmp->wr, str, strlen(str));
      if (tmp->type != UNKNOWN)
	while (cb_taken(&tmp->wr) > 0)
	  write_cb(&tmp->wr, tmp->fd, NULL);
      if (tmp->type == AI && *user == tmp)
	*user = (*user)->next;
      tmp = (tmp->type == AI) ? unit_user_free(tmp) : tmp->next;
    }
  while (data->end != NULL)
    pop_q(&data->end);
  if (count_type(*user, GRAPHIC) == 0)
    return (0);
  find_ask(&data->end_game, data->asking);
  return (0);
}

int		manage_server(t_user **user, t_zap *data)
{
  t_user	*tmp;
  t_tv		now;
  t_ask		*ask;

  tmp = *user;
  while (tmp != NULL)
    {
      if (tmp->type == AI)
	check_food(tmp, data);
      else if (tmp->type == GRAPHIC)
	{
	  ask = front_q((t_que *)tmp->info);
	  check_asking(user, data, ask);
	  if (ask != NULL && !IS_ASKING(ask))
	    pop_q((t_que **)&tmp->info);
	}
      if (tmp->tokill == 1)
	send_death(user, &tmp, data);
      else
	tmp = tmp->next;
    }
  gettimeofday(&now, NULL);
  check_eggs(data->teams, &now, *user);
  return ((front_q(data->end) != NULL && cmp_tv(front_q(data->end), &now) <= 0)
	  ? end_game(data, user) : check_asking(user, data, &data->end_game));
}
