//
// AI.hpp for zappy in /home/cache-_s/rendu/PSU_2014_zappy
//
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
//
// Started on  Thu Jun 25 11:01:29 2015 Sebastien Cache-Delanos
// Last update Fri Jul  3 12:24:42 2015 Pierre Charie
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

  void				vision();
  void				inventory();
  void				incantation();
  void				connect_nbr();

  void				act();
  void				setObjective();
  void				lookFor(const std::string & toget);
  void				setPath(int pos, const std::string & obj);
  void				getMissingStones();
  bool				tryIncant();
  void				dropToIncant();
  void				grabAll();
  void				listenSummon();
  void				communicate();
  void				move(int direction);

  void				printInventory();

  typedef void (AI::*handleResponse)();

  std::deque<std::string>			_todo;
  int						_level;
  std::map<std::pair<int, std::string>, int >	_lvlUp;
  std::vector<std::string>			_stones;
  bool						_update;
  std::string					_cmdRcv;
  std::string					_cmdSnd;
  std::map<int, std::vector<std::string>>	_vision;
  std::string					_lastSnd;
  bool						_isWaiting;
  std::string					_ID;
  std::string					_targetID;
  std::map<std::string, int>			_inventory;
  int						_sightRange;
  std::vector<std::string>			_needResponse;
  std::map<std::string, handleResponse>		_handleResponse;

  bool						_waitPong;
  bool						_triedInv;
};

#endif				//AI_HPP
