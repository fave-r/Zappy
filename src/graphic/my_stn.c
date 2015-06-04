/*
** my_stn.c for stn in /home/lopez_t/BONUS/Zappy/src/graphic
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Fri May 29 15:07:54 2015 Thibaut Lopez
** Last update Thu Jun  4 10:56:27 2015 Thibaut Lopez
*/

#include "server.h"

void		delete_team(t_team *team, t_user **usr, t_zap *data)
{
  t_team	*prev;
  t_user	*tmp;

  tmp = *usr;
  while (tmp != NULL)
    {
      if (tmp->type == AI && GET_TEAM(tmp) == team)
	send_death(usr, &tmp, data);
      else
	tmp = tmp->next;
    }
  prev = data->teams;
  while (prev != NULL && prev != team && prev->next != team)
    prev = prev->next;
  prev->next = team->next;
  if (data->teams == team)
    data->teams = data->teams->next;
  free(team->name);
  free(team);
}

void		stn_data(t_user **usr, t_zap *data, t_ask *ask)
{
  t_team	*team;

  team = team_by_name(data->teams, ask->args[0]);
  if (team == NULL)
    data->teams = team_cat(data->teams, xstrdup(ask->args[0]));
  else if (ask->args[1] != NULL)
    {
      free(team->name);
      team->name = xstrdup(ask->args[1]);
    }
  else
    delete_team(team, usr, data);
}

void		stn_ok(t_user *usr, t_zap *data)
{
  fill_cb(&usr->wr, "apr\n", 4);
  my_send_tna(data, usr);
}

void		stn_ko(t_user *usr, t_zap *data)
{
  fill_cb(&usr->wr, "anr\n", 4);
  my_send_tna(data, usr);
}

int		my_stn(char **com, t_zap *data, t_user *usr)
{
  char		*str;
  t_ask		ask;

  if ((sstrlen(com) != 2 && sstrlen(com) != 3) ||
      (team_by_name(data->teams, com[1]) != NULL && team_len(data->teams) == 2)
      || (sstrlen(com) == 3 && team_by_name(data->teams, com[2]) != NULL))
    return (my_sbp(usr));
  ask.args = sstrdup(com + 1);
  ask.ok = stn_ok;
  ask.changes = stn_data;
  ask.ko = stn_ko;
  find_ask(&ask, data->asking);
  if (count_type(usr, GRAPHIC) == 1)
    gettimeofday(&ask.wait, NULL);
  push_q((t_que **)&usr->info, &ask, clone_ask);
  str = strflat(com, " ", usr->nb, q_len((t_que *)usr->info) - 1);
  str[0] = 'a';
  alert_graphic(str, usr);
  free(str);
  return (0);
}
