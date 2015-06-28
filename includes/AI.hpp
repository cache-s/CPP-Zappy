//
// AI.hpp for zappy in /home/cache-_s/rendu/PSU_2014_zappy
//
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
//
// Started on  Thu Jun 25 11:01:29 2015 Sebastien Cache-Delanos
// Last update Sun Jun 28 17:24:09 2015 Pierre Charie
//

#ifndef				AINUTILE_HPP
# define			AINUTILE_HPP

# include			<iostream>
# include			<utility>
# include			<vector>
# include			<map>
# include			<string.h>

class				AI
{
public:

  AI();
  ~AI();

  char*				call(const char* cmdRdv);

private:

  void				forward();
  void				right();
  void				left();
  void				vision();
  void				inventory();
  void				expulse();
  void				incantation();
  void				fork();
  void				connect_nbr();
  void				death();

  void				act();
  void				setObjective();

  std::string			_cmdRcv;
  std::string			_cmdSnd;
  bool				_isWaiting;

  std::string			_objective;
  std::vector<std::string>	_path;

  typedef void (AI::*handleResponse)();
  std::map<std::string, handleResponse>	_handleResponse;
};

#endif				//AI_HPP
