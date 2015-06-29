//
// AI.cpp for zappy in /home/cache-_s/rendu/PSU_2014_zappy/sources/AI
// 
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
// 
// Started on  Wed Jun 24 11:29:59 2015 Sebastien Cache-Delanos
// Last update Mon Jun 29 19:26:42 2015 Sebastien Cache-Delanos
//

#include		"AI.hpp"

AI::AI()
{
  _isWaiting = false;
  _cmdRcv = "";
  _cmdSnd = "";
  _objective = "";
  _state = 1;
  _level = 1;

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

  _lvlUp[std::make_pair(1, "joueur")] = 0;
  _lvlUp[std::make_pair(2, "joueur")] = 1;
  _lvlUp[std::make_pair(3, "joueur")] = 1;
  _lvlUp[std::make_pair(4, "joueur")] = 3;
  _lvlUp[std::make_pair(5, "joueur")] = 3;
  _lvlUp[std::make_pair(6, "joueur")] = 5;
  _lvlUp[std::make_pair(7, "joueur")] = 5;

  _lvlUp[std::make_pair(1, "linemate")] = 1;
  _lvlUp[std::make_pair(2, "linemate")] = 1;
  _lvlUp[std::make_pair(3, "linemate")] = 2;
  _lvlUp[std::make_pair(4, "linemate")] = 1;
  _lvlUp[std::make_pair(5, "linemate")] = 1;
  _lvlUp[std::make_pair(6, "linemate")] = 1;
  _lvlUp[std::make_pair(7, "linemate")] = 2;

  _lvlUp[std::make_pair(1, "deraumere")] = 0;
  _lvlUp[std::make_pair(2, "deraumere")] = 1;
  _lvlUp[std::make_pair(3, "deraumere")] = 0;
  _lvlUp[std::make_pair(4, "deraumere")] = 1;
  _lvlUp[std::make_pair(5, "deraumere")] = 2;
  _lvlUp[std::make_pair(6, "deraumere")] = 2;
  _lvlUp[std::make_pair(7, "deraumere")] = 2;

  _lvlUp[std::make_pair(1, "sibur")] = 0;
  _lvlUp[std::make_pair(2, "sibur")] = 1;
  _lvlUp[std::make_pair(3, "sibur")] = 1;
  _lvlUp[std::make_pair(4, "sibur")] = 2;
  _lvlUp[std::make_pair(5, "sibur")] = 1;
  _lvlUp[std::make_pair(6, "sibur")] = 3;
  _lvlUp[std::make_pair(7, "sibur")] = 2;

  _lvlUp[std::make_pair(1, "mendiane")] = 0;
  _lvlUp[std::make_pair(2, "mendiane")] = 0;
  _lvlUp[std::make_pair(3, "mendiane")] = 0;
  _lvlUp[std::make_pair(4, "mendiane")] = 0;
  _lvlUp[std::make_pair(5, "mendiane")] = 3;
  _lvlUp[std::make_pair(6, "mendiane")] = 0;
  _lvlUp[std::make_pair(7, "mendiane")] = 2;

  _lvlUp[std::make_pair(1, "phiras")] = 0;
  _lvlUp[std::make_pair(2, "phiras")] = 0;
  _lvlUp[std::make_pair(3, "phiras")] = 2;
  _lvlUp[std::make_pair(4, "phiras")] = 1;
  _lvlUp[std::make_pair(5, "phiras")] = 0;
  _lvlUp[std::make_pair(6, "phiras")] = 1;
  _lvlUp[std::make_pair(7, "phiras")] = 2;

  _lvlUp[std::make_pair(1, "thystame")] = 0;
  _lvlUp[std::make_pair(2, "thystame")] = 0;
  _lvlUp[std::make_pair(3, "thystame")] = 0;
  _lvlUp[std::make_pair(4, "thystame")] = 0;
  _lvlUp[std::make_pair(5, "thystame")] = 0;
  _lvlUp[std::make_pair(6, "thystame")] = 0;
  _lvlUp[std::make_pair(7, "thystame")] = 1;
}

AI::~AI()
{
}

char*			AI::call(const char* cmdRcv)
{
  char*			ret;

  _cmdRcv = cmdRcv;
  act();
  if (_cmdSnd != "")
    ret = &_cmdSnd[0u];
  else
    ret = NULL;
  usleep(10000);
  return (ret);
}

void			AI::act()
{
  if (_isWaiting)
    (this->*_handleResponse[_lastSnd])();
  else
    {
      if (_objective == "" && _path.empty())
	setObjective();
      if (!_path.empty())
	{
	  _cmdSnd = _path.front();
	  _path.pop_front();
	}
    }
  if (_cmdSnd != "")
    _lastSnd = _cmdSnd;
}

void			AI::setObjective()
{
  if (_state == 1)
    {
      _cmdSnd = "inventaire";
      _isWaiting = true;
      _state++;
      return;
    }
  if (_state == 2)
    {
      _cmdSnd = "voir";
      _isWaiting = true;
      _state++;
      return;
    }
  _state = 1;
  if (_inventory["nourriture"] < 15)
    lookFor("nourriture");
  else if (tryIncant() == false)
    getMissingStones();
}

bool			AI::tryIncant()
{
  if (_inventory["linemate"] < _lvlUp[std::make_pair(_level, "linemate")])
    return (false);
  if (_inventory["deraumere"] < _lvlUp[std::make_pair(_level, "deraumere")])
    return (false);
  if (_inventory["sibur"] < _lvlUp[std::make_pair(_level, "sibur")])
    return (false);
  if (_inventory["mendiane"] < _lvlUp[std::make_pair(_level, "mendiane")])
    return (false);
  if (_inventory["phiras"] < _lvlUp[std::make_pair(_level, "phiras")])
    return (false);
  if (_inventory["thystame"] < _lvlUp[std::make_pair(_level, "thystame")])
    return (false);
  _cmdSnd = "incantation";
  std::cout << "ON INCANTE MDR" << std::endl;
  _isWaiting = true;
  return (true);
}

void			AI::getMissingStones()
{
  for (int i = 0; i < (((_level + 1) * _level) + _level); ++i)
    {
      for (unsigned int j = 0; j < _vision[i].size(); ++j)
        {
	  std::string item = _vision[i][j];
          if (_inventory[item] < _lvlUp[std::make_pair(_level, item)])
            {
              if (i == 0)
                {
		  std::string inst = "prend " + item;
		  _cmdSnd = inst;
		  return;
                }
              else
		{
		  setPath(i, item);
		  return;
		}
	    }
        }
    }
}

void			AI::lookFor(const std::string & toget)
{
  int			direction;

  _sightRange = ((_level + 1) * _level) + _level;
  for (int i = 0; i != _sightRange; ++i)
    for (unsigned int j = 0; j < _vision[i].size(); ++j)
      if (_vision[i][j] == toget)
	{
	  setPath(i, toget);
	  return;
	}
  srand (time(NULL));
  direction = rand() % 10;
  if (direction < 3)
    _cmdSnd = "gauche";
  else
    _cmdSnd = "avance";
}

void			AI::setPath(int mapCase, const std::string & obj)
{
  int y = 0, x = 0, pos = 0, i = 3, median = 0;

  while (pos < mapCase)
    {
      pos += i;
      i += 2;
      y++;
    }
  median = ((pos + 1 + pos - i) / 2) + 1;
  x = mapCase - median;
  while (y > 0)
    {
      _path.push_back("avance");
      y--;
    }
  if (x > 0)
    {
      _path.push_back("droite");
      while (x > 0)
        {
          _path.push_back("avance");
          x--;
        }
    }
  else if (x < 0)
    {
      _path.push_back("gauche");
      while (x < 0)
        {
          _path.push_back("avance");
          x++;
        }
    }
  std::string tmp;
  tmp = "prend " + obj;
  _path.push_back(tmp);
}

void			AI::printInventory()
{
  std::cout << "INVENTORY :" << std::endl;
  std::cout << "Nourriture = " << _inventory["nourriture"] << std::endl;
  std::cout << "Linemate   = " << _inventory["linemate"] << std::endl;
  std::cout << "Deraumere  = " << _inventory["deraumere"] << std::endl;
  std::cout << "Sibur      = " << _inventory["sibur"] << std::endl;
  std::cout << "Mendiane   = " << _inventory["mendiane"] << std::endl;
  std::cout << "Phiras     = " << _inventory["phiras"] << std::endl;
  std::cout << "Thystame   = " << _inventory["thystame"] << std::endl;
}

void			AI::forward()
{
  _isWaiting = false;
}

void			AI::right()
{
  _isWaiting = false;
}

void			AI::left()
{
  _isWaiting = false;
}

void			AI::expulse()
{
  _isWaiting = false;
}

void			AI::incantation()
{
  if (_cmdRcv[0] != 'n' && _cmdRcv[1] != 'i')
    {
      _cmdSnd = "";
      return;
    }
  if (_cmdRcv == "ko\n")
    {
      _isWaiting = false;
      return;
    }

  _level++;
  std::cout << "ELEVATION TERMINEE" << std::endl;
  _isWaiting = false;
}

void			AI::fork()
{
  _isWaiting = false;
}

void			AI::connect_nbr()
{
  _isWaiting = false;
}

void			AI::death()
{
  _isWaiting = false;
}

void			AI::vision()
{
  if (_cmdRcv[0] != '{' && _cmdRcv[1] != ' ')//TODO: Améliorer le check
    {
      _cmdSnd = "";
      return;
    }
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
  _isWaiting = false;
}

void			AI::inventory()
{
  if (_cmdRcv[0] != '{' && _cmdRcv[1] != 'n')//TODO: Améliorer le check
    {
      _cmdSnd = "";
      return;
    }
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
