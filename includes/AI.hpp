//
// AI.hpp for zappy in /home/cache-_s/rendu/PSU_2014_zappy
// 
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
// 
// Started on  Thu Jun 25 11:01:29 2015 Sebastien Cache-Delanos
// Last update Mon Jun 29 18:21:30 2015 Sebastien Cache-Delanos
//

#ifndef				AI_HPP
# define			AI_HPP

# include			<iostream>
# include			<string.h>
# include			<unistd.h>
# include			<sstream>
# include			<utility>
# include			<vector>
# include			<string>
# include			<deque>
# include			<map>

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
  void				lookFor(const std::string & toget);
  void				setPath(int pos, const std::string & obj);
  void				getMissingStones();
  bool				tryIncant();

  void				printInventory();

  typedef void (AI::*handleResponse)();

  std::deque<std::string>			_path;
  int						_level;
  int						_state;
  std::map<std::pair<int, std::string>, int >	_lvlUp;
  std::string					_cmdRcv;
  std::string					_cmdSnd;
  std::map<int, std::vector<std::string>>	_vision;
  std::string					_lastSnd;
  bool						_isWaiting;
  std::string					_objective;
  std::map<std::string, int>			_inventory;
  int						_sightRange;
  std::map<std::string, handleResponse>		_handleResponse;
};

#endif				//AI_HPP
