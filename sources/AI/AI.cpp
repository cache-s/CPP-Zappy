//
// AI.cpp for zappy in /home/cache-_s/rendu/PSU_2014_zappy
//
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
//
// Started on  Wed Jul  1 17:08:00 2015 Sebastien Cache-Delanos
// Last update Fri Jul  3 12:20:46 2015 Pierre Charie
//

#include		"AI.hpp"

AI::AI()
{
  _isWaiting = false;
  _update = false;
  _cmdRcv = "";
  _cmdSnd = "";
  _level = 1;

  srand (time(NULL));

  _stones.push_back("linemate");
  _stones.push_back("deraumere");
  _stones.push_back("sibur");
  _stones.push_back("mendiane");
  _stones.push_back("phiras");
  _stones.push_back("thystame");

  _handleResponse["voir"] = &AI::vision;
  _handleResponse["inventaire"] = &AI::inventory;
  _handleResponse["incantation"] = &AI::incantation;
  _handleResponse["connect_nbr"] = &AI::connect_nbr;

  _needResponse.push_back("voir");
  _needResponse.push_back("inventaire");
  _needResponse.push_back("incantation");
  _needResponse.push_back("connect_nbr");

  _lvlUp[std::make_pair(1, "joueur")] = 1;
  _lvlUp[std::make_pair(2, "joueur")] = 2;
  _lvlUp[std::make_pair(3, "joueur")] = 2;
  _lvlUp[std::make_pair(4, "joueur")] = 4;
  _lvlUp[std::make_pair(5, "joueur")] = 4;
  _lvlUp[std::make_pair(6, "joueur")] = 6;
  _lvlUp[std::make_pair(7, "joueur")] = 6;

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
  return (ret);
}

void			AI::act()
{
  // if (_cmdRcv.find("message"))
  //   {
  //     communicate();
  //     return;
  //   }

  if (_isWaiting)
    (this->*_handleResponse[_lastSnd])();
  if (!_isWaiting)
    {
      if (_todo.empty())
	setObjective();
      if (!_todo.empty())
	{
	  _cmdSnd = _todo.front();
	  _todo.pop_front();
	}
    }
  if (_cmdSnd != "")
    {
      for (unsigned int i = 0; i < _needResponse.size(); ++i)
	if (_cmdSnd == _needResponse[i])
	  _isWaiting = true;
      _lastSnd = _cmdSnd;
    }
}

void    AI::move(int direction)
{
  if (direction != 0)
    {
      if (direction == 8 || direction == 1 || direction == 2)
        _cmdSnd = "avance";
      if (direction == 6 || direction == 7)
	_cmdSnd = "droite";
      if (direction == 4 || direction == 3 || direction == 5)
        _cmdSnd = "gauche";
    }
}


void			AI::communicate()
{
  std::string answer;

  if (_cmdRcv.find("AliveCheck") != std::string::npos)
    _cmdSnd = "broadcast Alive";
  if (_cmdRcv.find("PING") != std::string::npos && _cmdRcv.find(_ID) != std::string::npos)
    {
      std::string ret =  "broadcast PONG " + _ID;
      _cmdSnd = ret;
    }
  if (!_targetID.empty())
    {
      if (_waitPong != true)
        {
          _waitPong = true;
	  std::string ret = "broadcast PING " + _targetID;
          _cmdSnd = ret;
        }
      if (_cmdRcv.find("PONG") != std::string::npos && _cmdRcv.find(_targetID) != std::string::npos)
        {
          _waitPong = false;
          int direction = _cmdRcv[8] - '0';
          move(direction);
        }
    }
  if (_cmdRcv.find ("INV(") != std::string::npos && _cmdRcv.find(_level) != std::string::npos)
    {
      std::string ret = "broadcast ";
      _cmdRcv.erase(0, 10);
      ret += _cmdRcv;
      _cmdSnd = ret;
      return;
    }
  if (_cmdRcv.find("OKINV") != std::string::npos && _cmdRcv.find(_level) != std::string::npos) //TODO verifier si la syntaxe issue de getline est correcte
{
  _cmdRcv.erase(0, _cmdRcv.find('('));

  std::istringstream iss(_cmdRcv);
  std::string line;
  std::getline(iss, line, ',');
  _targetID = line;
}
  if (_cmdRcv.find("STOPINV") != std::string::npos && _cmdRcv.find(_targetID) != std::string::npos)
    _targetID.clear();

}

void			AI::setObjective()
{
  if (_update == false)
    {
      _update = true;
      _todo.push_back("inventaire");
      _todo.push_back("voir");
      return;
    }
  _update = false;
  if (_inventory["nourriture"] < (5 + (_level * 3)))
    lookFor("nourriture");
  else if (tryIncant() == false)
    getMissingStones();
}

void			AI::listenSummon()
{
  static std::vector<std::string>	invID;
  static int			foodBegin = -1;
  std::string			newID;

  if (foodBegin == -1)
    foodBegin = _inventory["nourriture"];
      if (_cmdRcv.find("OKINV") != std::string::npos && _cmdRcv.find(std::to_string(_level)) != std::string::npos)
	{
	  if (invID.size() < (unsigned)_lvlUp[std::make_pair(_level, "joueur")])
	    {
	      std::cout << "SUMMON MSG == " << _cmdRcv << std::endl;
	      newID = _cmdRcv.substr(_cmdRcv.find('(') + 1, ((_cmdRcv.find('(') + 1) - _cmdRcv.find(','))); // TODO verifier qu'on ai exactement l'ID
	      invID.push_back(newID);
	    }
	}
  if (foodBegin - _inventory["nourriture"] > 2)
    {
      if (invID.size() < (unsigned)_lvlUp[std::make_pair(_level, "joueur")])
	{
	  for (unsigned int i = 0; i < invID.size(); ++i)
	    {
	      std::string cmd = "broadcast COME(";
	      cmd += std::to_string(_level);
	      cmd += ")";
	      invID[i];
	    }
	}
    }
}

bool			AI::tryIncant()
{
  int			peopleNbr = 0;

  for (unsigned int i = 0; i < _stones.size(); ++i)
    {
      if (_inventory[_stones[i]] < _lvlUp[std::make_pair(_level, _stones[i])])
	return (false);
    }
  for (unsigned int j = 0; j < _vision[0].size(); ++j)
    {
      if (_vision[0][j] == "joueur")
        peopleNbr++;
    }
  if (peopleNbr < _lvlUp[std::make_pair(_level, "joueur")])
    {
      std::string msg = "broadcast INV(";
      msg += std::to_string(_level);
      msg += ")";
      //TODO se mettre en position d'ecoute immobile pendant... 2? unité de bouffe. (pour pas qu'il en ramasse plus et fausse le calcul); On ne le lance qu'une fois par niveau. Si ca echoue, on deviendra non plus hote mais guest de la prochaine invoc'
      _todo.push_back(msg);
      return false;
    }
  grabAll();
  dropToIncant();
  _todo.push_back("incantation");
  return (true);
}

void			AI::grabAll()
{
  for (unsigned int j = 0; j < _vision[0].size(); ++j)
    {
      std::string item = _vision[0][j];
      if (item != "joueur")
	{
	  std::string inst = "prend " + item;
	  _todo.push_back(inst);
	}
    }
}

void			AI::dropToIncant()
{
  for (unsigned int i = 0; i < _stones.size(); ++i)
    {
      std::string inst = "pose " + _stones[i];
      for (int j = 0; j < _lvlUp[std::make_pair(_level, _stones[i])]; ++j)
	_todo.push_back(inst);
    }
}

void			AI::getMissingStones()
{
  for (int i = 0; i < (((_level + 1) * _level) + _level); ++i)
    {
      for (unsigned int j = 0; j < _vision[i].size(); ++j)
        {
	  std::string item = _vision[i][j];
          if (item.find("joueur") == std::string::npos && _inventory[item] < _lvlUp[std::make_pair(_level, item)])
            {
              if (i == 0)
                {
		  std::string inst = "prend " + item;
		  _todo.push_back(inst);
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
  direction = rand() % 10;
  if (direction < 3)
    _todo.push_back("gauche");
  else
    _todo.push_back("avance");
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
      _todo.push_back("avance");
      y--;
    }
  if (x > 0)
    {
      _todo.push_back("droite");
      while (x > 0)
        {
          _todo.push_back("avance");
          x--;
        }
    }
  else if (x < 0)
    {
      _todo.push_back("gauche");
      while (x < 0)
        {
          _todo.push_back("avance");
          x++;
        }
    }
  std::string tmp;
  tmp = "prend " + obj;
  _todo.push_back(tmp);
}

void			AI::connect_nbr()
{
  _isWaiting = false;
}

void			AI::incantation()
{
  if (_cmdRcv == "ko\n")
    {
      _isWaiting = false;
      _todo.push_back("inventaire");
      return;
    }
  if (_cmdRcv.find("niveau actuel") == std::string::npos)
    {
      _cmdSnd = "";
      return;
    }
  _level++;
  _isWaiting = false;
  return;
}

void			AI::vision()
{
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
      std::cout << "inventaire = " << tmp[i] << std::endl;
      number = std::stoi(tmp[i].substr(tmp[i].find(" ")));
      thing = tmp[i].substr(0, tmp[i].find(" "));
      _inventory[thing] = number;
    }
  _isWaiting = false;
}
