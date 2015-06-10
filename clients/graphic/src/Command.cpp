//
// Command.cpp for zappy in /home/fave_r/rendu/Zappy/clients/graphic
//
// Made by romaric
// Login   <fave_r@epitech.net>
//
// Started on  Mon Jun  8 14:29:10 2015 romaric
// Last update Tue Jun  9 15:13:04 2015 romaric
//

#include <map>
#include "Command.hh"

Command * Command::_Command  = NULL;

Command * Command::newinstance()
{
  if (_Command == NULL)
    _Command = new Command;
  return _Command;
}

Command::Command()
{
  this->_foncs["BIENVENUE"] = &Command::hello;
  this->_foncs["msz"] = &Command::mapSize;
  this->_foncs["bct"] = &Command::cellInfo;
  this->_foncs["tna"] = &Command::teamName;
  this->_foncs["pnw"] = &Command::newPlayer;
  this->_foncs["ppo"] = &Command::playerPos;
  this->_foncs["plv"] = &Command::playerLevel;
  this->_foncs["pin"] = &Command::playerInv;
  this->_foncs["pex"] = &Command::playerExpel;
  this->_foncs["pbc"] = &Command::playerBroad;
  this->_foncs["pic"] = &Command::playerCastb;
  this->_foncs["pie"] = &Command::playerCaste;
  this->_foncs["pfk"] = &Command::playerLay;
  this->_foncs["pdr"] = &Command::playerThrow;
  this->_foncs["pgt"] = &Command::playerLoot;
  this->_foncs["pdi"] = &Command::playerStarve;
  this->_foncs["enw"] = &Command::eggLayed;
  this->_foncs["eht"] = &Command::eggHatch;
  this->_foncs["ebo"] = &Command::playerOnEgg;
  this->_foncs["edi"] = &Command::hatchedEggStarv;
  this->_foncs["sgt"] = &Command::timeNotif;
  this->_foncs["seg"] = &Command::eog;
  this->_foncs["smg"] = &Command::serverMsg;
  this->_foncs["atn"] = &Command::askTeam;
  this->_foncs["app"] = &Command::askPlayerPosition;
  this->_foncs["api"] = &Command::askPlayerInv;
  this->_foncs["apl"] = &Command::askPlayerLvl;
  this->_foncs["apk"] = &Command::askPlayerKill;
  this->_foncs["act"] = &Command::askContent;
  this->_foncs["ams"] = &Command::askMapSize;
  this->_foncs["ars"] = &Command::askReset;
  this->_foncs["suc"] = &Command::unknow;
  this->_foncs["sbp"] = &Command::bad;
}

func	Command::thiscom(const std::string & com , const std::string & str)
{
  return (this->*_foncs[com])(str);
}

