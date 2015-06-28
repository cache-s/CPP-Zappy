//
// Ai.hpp for  in /home/charie_p/rendu/PSU_2014_zappy/includes
//
// Made by Pierre Charie
// Login   <charie_p@epitech.net>
//
// Started on  Wed Jun 17 18:01:03 2015 Pierre Charie
// Last update Sun Jun 28 15:16:04 2015 Pierre Charie
//

#ifndef		AI_HPP
# define	AI_HPP

# include	<sstream>
# include	<iostream>
# include	<map>
# include	<list>
# include	<stdexcept>
# include	<vector>
# include       <stdlib.h>

# include	"my_exception.hpp"

class Ai
{
public:

  Ai(int ID);
  ~Ai();

  const char		*action(std::string msg);

  void		setVision(std::string canSee);
  void		checkVision();
  void		setInventory(std::string inventory);
  void		checkInventory();
  void		communicate(std::string cmd);
  void		setInstruction(int mapCase, std::string obj);
  void		move(int direction);

private:
  std::map<int, std::vector<std::string> >	_vision;
  std::map<std::string, int>			_inventory;
  std::map<std::pair<int, std::string>, int >  _forUp;
  std::string					_ID;
  int						_level;
  std::string					_targetID;

  std::list<std::string>			_instruction;
  bool						_mustWait;

  bool						_waitInventory;
  bool						_waitVision;
  bool						_waitPong;
};

#endif
