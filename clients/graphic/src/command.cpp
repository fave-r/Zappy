//
// command.cpp for zappy in /home/fave_r/rendu/Zappy/clients/graphic
//
// Made by romaric
// Login   <fave_r@epitech.net>
//
// Started on  Mon Jun  8 14:29:10 2015 romaric
// Last update Mon Jun  8 14:29:14 2015 romaric
//

#include <map>
#include "command.hh"

command * command::_command  = NULL;

command * command::newinstance()
{
  if (_command == NULL)
    _command = new command;
  return _command;
}

command * command::thiscom(std::string com)
{
  return (this->*foncs[com])(com);
}
