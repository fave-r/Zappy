//
// Command.hh for zappy in /home/fave_r/rendu/Zappy/clients/graphic
//
// Made by romaric
// Login   <fave_r@epitech.net>
//
// Started on  Mon Jun  8 14:05:20 2015 romaric
// Last update Tue Jun  9 12:20:18 2015 romaric
//

#ifndef __FACTCO__
#define __FACTCO__

#include <string>
#include <map>

class Command
{
private:
  typedef void (Command::*func)(const std::string &);
  std::map<std::string, func>	_foncs;

public:
  static Command		*_Command;
  static Command		*newinstance();
  Command();
  virtual ~Command(){}

  func				thiscom(const std::string &, const std::string &);
  void				hello(const std::string &);
  void				mapSize(const std::string &);
  void				cellInfo(const std::string &);
  void				teamName(const std::string &);
  void				newPlayer(const std::string &);
  void				playerPos(const std::string &);
  void				playerLevel(const std::string &);
  void				playerInv(const std::string &);
  void				playerExpel(const std::string &);
  void				playerBroad(const std::string &);
  void				playerCastb(const std::string &);
  void				playerCaste(const std::string &);
  void				playerLay(const std::string &);
  void				playerThrow(const std::string &);
  void				playerLoot(const std::string &);
  void				playerStarve(const std::string &);
  void				eggLayed(const std::string &);
  void				eggHatch(const std::string &);
  void				playerOnEgg(const std::string &);
  void				hatchedEggStarv(const std::string &);
  void				timeNotif(const std::string &);
  void				eog(const std::string &);
  void				serverMsg(const std::string &);
  void				askTeam(const std::string &);
  void				askPlayerPosition(const std::string &);
  void				askPlayerInv(const std::string &);
  void				askPlayerLvl(const std::string &);
  void				askPlayerKill(const std::string &);
  void				askContent(const std::string &);
  void				askMapSize(const std::string &);
  void				askReset(const std::string &);
  void				unknow(const std::string &);
  void				bad(const std::string &);
};

#endif
