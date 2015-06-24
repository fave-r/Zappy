//
// Error.hh for Error.hh in /home/jean_c/Dropbox/zappy/Includes
//
// Made by jean_c
// Login   <jean_c@epitech.net>
//
// Started on  Sun Jun 21 02:36:39 2015 jean_c
// Last update Sun Jun 21 02:36:41 2015 jean_c
//

#ifndef __ERROR_HH__
#define __ERROR_HH__

#include <stdexcept>

class loading_error : public std::runtime_error
{
public:
  loading_error():runtime_error("Loading error"){}
  loading_error(const std::string &msg):runtime_error(msg.c_str()) {}
};

class exec_error : public std::runtime_error
{
public:
  exec_error():runtime_error("execution error"){}
  exec_error(const std::string &msg):runtime_error(msg.c_str()) {}
};

#endif
