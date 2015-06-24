//
// Command.hh for zappy in /home/fave_r/rendu/Zappy/clients/graphic
//
// Made by romaric
// Login   <fave_r@epitech.net>
//
// Started on  Mon Jun  8 14:05:20 2015 romaric
// Last update Wed Jun 10 15:47:33 2015 Thibaut Lopez
//

#ifndef __FACTCO__
#define __FACTCO__

#include <string>
#include <map>
#include "Map.hh"
#include "Socket.hh"

class Command
{
private:
  typedef void (Command::*func)(const std::string &, Map &, Socket &) const;
  std::map<std::string, func>	_foncs;

public:
  static Command		*_Command;
  static Command		*newinstance();
  Command();
  virtual ~Command(){}

  void				thiscom(const std::string &, Map &, Socket &);
  void				hello(const std::string &, Map &, Socket &) const;
  void				mapSize(const std::string &, Map &, Socket &) const;
  void				cellInfo(const std::string &, Map &, Socket &) const;
  void				teamName(const std::string &, Map &, Socket &) const;
  void				newPlayer(const std::string &, Map &, Socket &) const;
  void				playerPos(const std::string &, Map &, Socket &) const;
  void				playerLevel(const std::string &, Map &, Socket &) const;
  void				playerInv(const std::string &, Map &, Socket &) const;
  void				playerExpel(const std::string &, Map &, Socket &) const;
  void				playerBroad(const std::string &, Map &, Socket &) const;
  void				playerCastb(const std::string &, Map &, Socket &) const;
  void				playerCaste(const std::string &, Map &, Socket &) const;
  void				playerLay(const std::string &, Map &, Socket &) const;
  void				playerThrow(const std::string &, Map &, Socket &) const;
  void				playerLoot(const std::string &, Map &, Socket &) const;
  void				playerStarve(const std::string &, Map &, Socket &) const;
  void				eggLayed(const std::string &, Map &, Socket &) const;
  void				eggHatch(const std::string &, Map &, Socket &) const;
  void				playerOnEgg(const std::string &, Map &, Socket &) const;
  void				hatchedEggStarv(const std::string &, Map &, Socket &) const;
  void				timeNotif(const std::string &, Map &, Socket &) const;
  void				eog(const std::string &, Map &, Socket &) const;
  void				serverMsg(const std::string &, Map &, Socket &) const;
  void				askTeam(const std::string &, Map &, Socket &) const;
  void				askPlayerPosition(const std::string &, Map &, Socket &) const;
  void				askPlayerInv(const std::string &, Map &, Socket &) const;
  void				askPlayerLvl(const std::string &, Map &, Socket &) const;
  void				askPlayerKill(const std::string &, Map &, Socket &) const;
  void				askContent(const std::string &, Map &, Socket &) const;
  void				askMapSize(const std::string &, Map &, Socket &) const;
  void				askReset(const std::string &, Map &, Socket &) const;
  void				askGetTime(const std::string &, Map &, Socket &) const;
  void				unknow(const std::string &, Map &, Socket &) const;
  void				bad(const std::string &, Map &, Socket &) const;
};

#endif
