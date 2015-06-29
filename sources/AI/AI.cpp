//
// AI.cpp for zappy in /home/cache-_s/rendu/PSU_2014_zappy/sources/AI
// 
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
// 
// Started on  Wed Jun 24 11:29:59 2015 Sebastien Cache-Delanos
// Last update Sun Jun 28 20:53:36 2015 Sebastien Cache-Delanos
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
  char*			ret;

  _cmdRcv = cmdRcv;
  std::cout << _cmdRcv << std::endl;
  act();
  ret = &_cmdSnd[0u];
  return (ret);
}

void			AI::act()
{
  if (_isWaiting)
    {
      (this->*_handleResponse[_cmdSnd])();
      _isWaiting = false;
      if (_objective == "")
	setObjective();
    }
  if (_objective == "")
    {
      _cmdSnd = "voir";
      _isWaiting = true;
    }
  //doObjective
}

void			AI::setObjective()
{
}

void			AI::forward()
{
}

void			AI::right()
{
}

void			AI::left()
{
}

void			AI::expulse()
{
}

void			AI::incantation()
{
}

void			AI::fork()
{
}

void			AI::connect_nbr()
{
}

void			AI::death()
{
}

void			AI::vision()
{
  if (_cmdRcv[0] != '{')
    return;
  _vision.clear();
  _cmdRcv.erase(0, 2);
  _cmdRcv.erase(_cmdRcv.end() - 2, _cmdRcv.end());

  int			index = 0;
  std::istringstream	iss1(_cmdRcv);
  std::string		buf1;
  std::string		buf2;

  while(std::getline(iss1, buf1, ','))
    {
      std::istringstream iss2(buf1);
      while (std::getline(iss2, buf2, ' '))
        {
          if (buf2[0] == ' ')
            buf2.erase(1,1);
	  if (buf2 != "")
	    _vision[index].push_back(buf2);
        }
      ++index;
    }
}

void			AI::inventory()
{
  if (_cmdRcv[0] != '{')
    return;
  std::stringstream		ss(_cmdRcv);
  std::vector<std::string>	tmp;
  std::string			thing;
  int				number;

  _inventory.clear();
  while(ss.good())
    {
      std::string		substr;
      getline(ss, substr, ',');
      tmp.push_back(substr);
    }
  tmp[0].erase(0, 1);
  tmp[tmp.size() - 1].erase(tmp[tmp.size() - 1].end() - 2, tmp[tmp.size() - 1].end());
  for (unsigned int i = 0; i < tmp.size(); ++i)
    {
      number = std::stoi(tmp[i].substr(tmp[i].find(" ")));
      thing = tmp[i].substr(0, tmp[i].find(" "));
      _inventory[thing] = number;
    }
  _isWaiting = false;
}
