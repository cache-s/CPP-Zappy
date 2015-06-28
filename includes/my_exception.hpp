//
// my_exception.hpp for  in /home/charie_p/rendu/PSU_2014_zappy/includes
//
// Made by Pierre Charie
// Login   <charie_p@epitech.net>
//
// Started on  Wed Jun 24 16:34:41 2015 Pierre Charie
// Last update Sun Jun 28 17:34:02 2015 Pierre Charie
//

#ifndef		MY_EXCEPTION_HPP
# define	MY_EXCEPTION_HPP

# include <iostream>
# include <sstream>
# include <exception>

class to_C : public std::exception
{
public:
  to_C(std::string m) : _msg(m) {}
  ~to_C() throw() {}
const char* what() const throw() { return _msg.c_str(); }
private:
  std::string _msg;
};

#endif
