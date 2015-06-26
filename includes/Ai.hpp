//
// Ai.hpp for  in /home/charie_p/rendu/PSU_2014_zappy/includes
//
// Made by Pierre Charie
// Login   <charie_p@epitech.net>
//
// Started on  Wed Jun 17 18:01:03 2015 Pierre Charie
// Last update Fri Jun 26 15:21:33 2015 Pierre Charie
//

#ifndef		AI_HPP
# define	AI_HPP

# include	<stdbool>
# include	<stream>
# include	<iostream>
# include	<map>
# include	<stdexcept>
# include	<vector>
# include       <stdlib.h>


class Ai
{
public:

  Ai();
  ~Ai();

  void		action(std::string msg);

  void		setVision(std::string canSee);
  void		checkVision();
  void		setInventory(std::string inventory);
  void		checkInventory();
  void		communicate(std::string cmd);
  void		setInstruction(int mapCase, std::string obj);
  void		move();

private:
  std::map<int, std::vector<std::string> >	_vision;
  std::map<std::string, int>			_inventory;
  std::map<std::pair<int, std::string>, int *>  _forUp;
  std::string					_ID;
  std::string					_level;
  std::string					_targetID;

  std::list<std::string>			_instruction;
  bool						_mustWait;

  bool						_waitInv;
  bool						_waitVis;
};

#endif
