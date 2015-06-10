//
// Command.hh for zappy in /home/fave_r/rendu/Zappy/clients/graphic
//
// Made by romaric
// Login   <fave_r@epitech.net>
//
// Started on  Mon Jun  8 14:05:20 2015 romaric
// Last update Wed Jun 10 14:01:57 2015 romaric
//

#ifndef __FACTCO__
#define __FACTCO__

#include <string>
#include <map>
#include "Map.hh"

class Command
{
private:
  typedef void (Command::*func)(const std::string &, Map &) const;
  std::map<std::string, func>	_foncs;

public:
  static Command		*_Command;
  static Command		*newinstance();
  Command();
  virtual ~Command(){}

  void				thiscom(const std::string &, const std::string &, Map &);
  void				hello(const std::string &, Map &) const;
  void				mapSize(const std::string &, Map &) const;
  void				cellInfo(const std::string &, Map &) const;
  void				teamName(const std::string &, Map &) const;
  void				newPlayer(const std::string &, Map &) const;
  void				playerPos(const std::string &, Map &) const;
  void				playerLevel(const std::string &, Map &) const;
  void				playerInv(const std::string &, Map &) const;
  void				playerExpel(const std::string &, Map &) const;
  void				playerBroad(const std::string &, Map &) const;
  void				playerCastb(const std::string &, Map &) const;
  void				playerCaste(const std::string &, Map &) const;
  void				playerLay(const std::string &, Map &) const;
  void				playerThrow(const std::string &, Map &) const;
  void				playerLoot(const std::string &, Map &) const;
  void				playerStarve(const std::string &, Map &) const;
  void				eggLayed(const std::string &, Map &) const;
  void				eggHatch(const std::string &, Map &) const;
  void				playerOnEgg(const std::string &, Map &) const;
  void				hatchedEggStarv(const std::string &, Map &) const;
  void				timeNotif(const std::string &, Map &) const;
  void				eog(const std::string &, Map &) const;
  void				serverMsg(const std::string &, Map &) const;
  void				askTeam(const std::string &, Map &) const;
  void				askPlayerPosition(const std::string &, Map &) const;
  void				askPlayerInv(const std::string &, Map &) const;
  void				askPlayerLvl(const std::string &, Map &) const;
  void				askPlayerKill(const std::string &, Map &) const;
  void				askContent(const std::string &, Map &) const;
  void				askMapSize(const std::string &, Map &) const;
  void				askReset(const std::string &, Map &) const;
  void				unknow(const std::string &, Map &) const;
  void				bad(const std::string &, Map &) const;
};

#endif
