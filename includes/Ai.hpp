//
// Ai.hpp for  in /home/charie_p/rendu/PSU_2014_zappy/includes
//
// Made by Pierre Charie
// Login   <charie_p@epitech.net>
//
// Started on  Wed Jun 17 18:01:03 2015 Pierre Charie
// Last update Tue Jun 23 14:35:26 2015 Pierre Charie
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

  void action();

  void setVision();
  void setInventory();
  void checkInventory();
  void communicate(std::string cmd);
  void move();

private:
  std::map<int, std::vector<std::string> >	_vision;
  std::map<std::string, int>			_inventory;

  std::string					_ID;
  std::string					_level;

  std::string					_targetID;

};

#endif
