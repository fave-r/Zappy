//
// command.hh for zappy in /home/fave_r/rendu/Zappy/clients/graphic
//
// Made by romaric
// Login   <fave_r@epitech.net>
//
// Started on  Mon Jun  8 14:05:20 2015 romaric
// Last update Mon Jun  8 16:59:53 2015 romaric
//

#ifndef __FACTCO__
#define __FACTCO__

#include <string>
#include <map>

class command
{
private:
  typedef void (command::*func)(const std::string &);
  std::map<std::string, func>  foncs;

public:
  static command * _command;
  static command *newinstance();
  command()
  {
    foncs["BIENVENUE"] = &command::hello;
    foncs["msz"] = &command::mapsize;
    foncs["bct"] = &command::cellinfo;
    foncs["tna"] = &command::teamname;
    foncs["pnw"] = &command::newplayer;
    foncs["ppo"] = &command::playerpos;
    foncs["plv"] = &command::playerlevel;
    foncs["pin"] = &command::playerinv;
    foncs["pex"] = &command::playerexpel;
    foncs["pbc"] = &command::playerbroad;
    foncs["pic"] = &command::playercastb;
    foncs["pie"] = &command::playercaste;
    foncs["pfk"] = &command::playerlay;
    foncs["pdr"] = &command::playerthrow;
    foncs["pgt"] = &command::playerloot;
    foncs["pdi"] = &command::playerstarve;
    foncs["enw"] = &command::egglayed;
    foncs["eht"] = &command::egghatch;
    foncs["ebo"] = &command::playeronegg;
    foncs["edi"] = &command::hatchedeggstrav;
    foncs["sgt"] = &command::timenotif;
    foncs["seg"] = &command::eog;
    foncs["smg"] = &command::servermsg;
    foncs["suc"] = &command::unknow;
    foncs["sbp"] = &command::bad;
  }
  virtual ~command(){}
};

#endif
