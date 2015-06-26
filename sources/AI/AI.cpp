//
// AI.cpp for zappy in /home/cache-_s/rendu/PSU_2014_zappy/sources/AI
// 
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
// 
// Started on  Wed Jun 24 11:29:59 2015 Sebastien Cache-Delanos
// Last update Fri Jun 26 16:06:25 2015 Sebastien Cache-Delanos
//

#include		"AI.hpp"

AI::AI()
{
  _isWaiting = false;
  _cmdRcv = "";
  _cmdSnd = "";
  _objective = "";

  _handleResponse["avance"] = &AI::forward;
  _handleResponse["droite"] = &AI::right;
  _handleResponse["gauche"] = &AI::left;
  _handleResponse["voir"] = &AI::vision;
  _handleResponse["inventaire"] = &AI::inventory;
  _handleResponse["expulse"] = &AI::expulse;
  _handleResponse["incantation"] = &AI::incantation;
  _handleResponse["fork"] = &AI::fork;
  _handleResponse["connect_nbr"] = &AI::connect_nbr;
  _handleResponse["mort"] = &AI::death;

  /*
  **  TODO:
  **  - add "prendre objet"
  **  - add "pose objet"
  */
}

AI::~AI()
{

}

char*			AI::call(const char* cmdRcv)
{
  _cmdRcv = cmdRcv;
  act();

  char *ret = new char[_cmdSnd.length() + 1];
  strcpy(ret, _cmdSnd.c_str());
  return (ret);
}

void			AI::act()
{
  if (_isWaiting)
    {
      (this->*_handleResponse[_cmdSnd])();
      _isWaiting = false;
    }
  if (_objective == "")
    {
      _cmdSnd = "inventaire";
      _isWaiting = true;
    }
  std::cout << _cmdRcv << std::endl;
  //doObjective
}

void			AI::forward()
{
  std::cout << "forward" << std::endl;
}

void			AI::right()
{
  std::cout << "right" << std::endl;
}

void			AI::left()
{
  std::cout << "left" << std::endl;
}

void			AI::vision()
{
  std::cout << "vision" << std::endl;
}

void			AI::inventory()
{
  std::cout << "inventory" << std::endl;
}

void			AI::expulse()
{
  std::cout << "expulse" << std::endl;
}

void			AI::incantation()
{
  std::cout << "incantation" << std::endl;
}

void			AI::fork()
{
  std::cout << "fork" << std::endl;
}

void			AI::connect_nbr()
{
  std::cout << "connect_nbr" << std::endl;
}

void			AI::death()
{
  std::cout << "death" << std::endl;
}
