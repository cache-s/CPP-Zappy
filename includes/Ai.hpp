//
// Ai.hpp for  in /home/charie_p/rendu/PSU_2014_zappy/includes
//
// Made by Pierre Charie
// Login   <charie_p@epitech.net>
//
// Started on  Wed Jun 17 18:01:03 2015 Pierre Charie
// Last update Thu Jun 18 13:35:58 2015 Pierre Charie
//

#ifndef		AI_HPP
# define	AI_HPP

class Ai
{
 public:

  Ai();
  ~Ai();

  void action();

  void setVision();
  void setInventory();

 private:
  std::map<int, std::vector<std::string> > _vision;
  std::map<std::string, int> _inventory;
};

#endif
