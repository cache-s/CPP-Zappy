
#include		"AI.hpp"

AI::AI()
{
  _isWaiting = false;
  _update = false;
  _triedInv = false;
  _waitSum = false;
  _waitPong = false;
  _waitCome = false;
  _startInc = false;
  _targetID = "";
  _targetDir = -1;
  _cmdRcv = "";
  _cmdSnd = "";
  _level = 1;
  _foodBegin = -1;

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




  try
    {
      _cmdSnd = "";
      _cmdRcv = cmdRcv;
      act();
      if (_cmdSnd != "")
	ret = &_cmdSnd[0u];
      else
	ret = NULL;
      return (ret);
    }
  catch (...)
    {
      std::cerr << "Exception caught." << std::endl;
    }
  return NULL;
}

void			AI::setId(int id)
{
  _ID = std::to_string(id);
  std::cout << "MY ID IS " << _ID << std::endl;
}

void			AI::act()
{

  if (_cmdRcv.find("niveau actuel") != std::string::npos || (_cmdRcv.find("STOPINV") != std::string::npos && _cmdRcv.find(_targetID) != std::string::npos))
    {
      _targetID = "";
      _targetDir = -1;
      _triedInv = false;
      _waitSum = false;
      _waitCome = false;
      _startInc = false;
      _foodBegin = -1;
      _waitPong = false;

    }
  inventory();
  vision();
  std::cout << "on a " << _inventory["nourriture"] << std::endl;
  if (_inventory["nourriture"] < 3 && _inventory["nourriture"] != 0)
    {
      if (_waitSum == true || _waitCome == true || _startInc == true)
      	{
	  std::cout << "ON ARRETE l'INCANT\n";
      	  std::string msg = "broadcast STOPINV " + _ID;
      	  _todo.push_front(msg);
      	}
      std::cout << "PLUS DE BOUFFE\n";
      _waitSum = false;
      _waitCome = false;
      _startInc = false;
      _triedInv = false;
      _targetID = "";
    }

  if (_startInc == true)
    {
      static bool tmp = true;
      if (tmp == true)
	{
	  _cmdSnd = "voir";
	  tmp = false;
	  return;
	}
      tmp = true;
      vision();
      std::cout << "on est pret à incanter\n";
      _cmdRcv = "";
      _waitSum = false;
      _triedInv = false;
      tryIncant();
      _startInc = false;

    }

  if (_cmdRcv.find("PING") != std::string::npos && _cmdRcv.find(_ID) != std::string::npos)
    {
      int direction = _cmdRcv[_cmdRcv.find("message") + 8] - '0';
      std::cout << "DIRECTION QUI VIENT = " << direction << std::endl;
      if (direction == 0)
	{
	  int       peopleNbr = 0;
	  for (unsigned int j = 0; j < _vision[0].size(); ++j)
	    {
	      peopleNbr++;
	    }
	  // if (peopleNbr == _lvlUp[std::make_pair(_level, "joueur")])
	  //   {
	      std::cout << "GOGOINCANT\n";
	      _startInc = true;
	      tryIncant();
	      return;
	    // }
	}
      else
	{
	  std::string ret =  "broadcast PONG " + _ID;
	  _cmdSnd = ret;
	}
      return;
    }
  if (!_targetID.empty())
    {
      if (_cmdRcv.find("STOPINV") != std::string::npos && _cmdRcv.find(_targetID) != std::string::npos)
	{
	  return;
	  _targetID.clear();
	}

      if (_targetDir == -1)
	{
	  if (_waitPong == false)
	    {
	      static bool once = false;

	      if (once == true)
		{
		  _cmdSnd = "inventaire";
		  once = !once;
		  return;
		}
	      once = !once;
	      _waitPong = true;
	      std::string ret = "broadcast PING " + _targetID;
	      _cmdSnd = ret;
	      return;
	    }
	  if ((_cmdRcv.find("PONG") != std::string::npos) && (_cmdRcv.find(_targetID) != std::string::npos))
	    {
	      if (_cmdRcv != "ok")
		{
		  _waitPong = false;
		  int direction = _cmdRcv[_cmdRcv.find("message") + 8] - '0';
		  std::cout << "direction = " << direction << std::endl;
		  _targetDir = direction;
		  move();
		  _cmdRcv = "";
		  return;
		}
	    }
	}
      else
	{
	  move();
	  return;
	}
      return;
    }
  else
    {
      if (_cmdRcv.find("message") != std::string::npos || _waitSum == true)
	{
	  try{
	    communicate();
	    if (_cmdSnd.find("OKINV") != std::string::npos && _waitCome != true)
	      {
		_waitCome = true;
		return;
	      }
	    if (_waitSum == true)
	      {
		static bool once = true;

		if (_cmdSnd.find("PONG") != std::string::npos)
		  return;
		if (once == true)
		  {
		    _cmdSnd = "inventaire"; //pour eviter les INV en chaine
		    vision();
		  }
		else
		  {
		    _cmdSnd = "voir";
		    inventory();
		  }
		once = !once;
	      }
	  }catch (const std::exception &e)
	    {
	      std::cerr << "Exception : Error in communication" << std::endl;
	    }
	  return;
	}
    }
  if (_isWaiting && (_lastSnd == "voir" || _lastSnd == "inventaire" || _lastSnd == "incantation" || _lastSnd == "connect_nbr"))
  // if (_isWaiting)
    (this->*_handleResponse[_lastSnd])();
  if (!_isWaiting || (_lastSnd != "voir" && _lastSnd != "inventaire" && _lastSnd != "incantation" && _lastSnd != "connect_nbr"))
    {
      try
	{
	  if (_todo.empty())
	    setObjective();
	}
	  catch (const std::exception &e)
	    {
	      std::cerr << "Exception : Error in setting objectives" << std::endl;;
	    }
	  try
	    {
	      if (!_todo.empty())
		{
		  _cmdSnd = _todo.front();
		  if (!_targetID.empty())
		    std::cout << "on fait " << _cmdSnd << std::endl;
		  _todo.pop_front();
		}
	    }
	  catch (const std::exception &e)
	    {
	      std::cerr << "Exception : Error in popping list of inctruction" << std::endl;;
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

void    AI::move()
{
  _todo.clear();
  if (_targetDir != 0)
    {
      if (_targetDir == 8 || _targetDir == 1 || _targetDir == 2)
 	_cmdSnd = "avance";
      // _todo.push_front("avance");
      if (_targetDir == 6 || _targetDir == 7)
	_cmdSnd = "droite";
      // _todo.push_front("droite");
      if (_targetDir == 4 || _targetDir == 3 || _targetDir == 5)
	_cmdSnd = "gauche";
      // _todo.push_front("gauche");
   }
  else
    std::cout << "ON EST ARRIVEJENZFJIZEHFUOZEHFUZEIOFHZEIUFZEHFUHZEUI\n\n\n";
  _targetDir = -1;
}


void			AI::communicate()
{
  std::string answer;

  listenSummon();
  if (_cmdSnd.find("OKINVOC") != std::string::npos)
    return;
  if (_cmdRcv.find("AliveCheck") != std::string::npos)
    _cmdSnd = "broadcast Alive";
  if (_cmdRcv.find("INV(") != std::string::npos && _cmdRcv.find(std::to_string(_level)) != std::string::npos)
    {
      std::string ret = "broadcast RDY(";
      ret += std::to_string(_level);
      ret += ", ";
      ret += _ID;
      _cmdSnd = ret;
      std::cout << "on renvoie " << ret << std::endl;
      return;
    }
  if (_cmdRcv.find("OKINVOC(") != std::string::npos && _cmdRcv.find(_ID) != std::string::npos)
    {
      _cmdRcv.erase(0, _cmdRcv.find('('));

      std::istringstream iss(_cmdRcv);
      std::string line;
      std::getline(iss, line, ',');
      line.erase(0,1);
      _targetID = line;
      std::cout << "TARGET ID = " << _targetID << std::endl;
      _cmdRcv.clear();
    }
  if (_cmdRcv.find("STOPINV") != std::string::npos && _cmdRcv.find(_targetID) != std::string::npos)
    _targetID.clear();
}

void			AI::setObjective()
{
  if (_update == false || _waitSum == true)
    {
      _update = true;
      _todo.push_back("inventaire");
      _todo.push_back("voir");
      return;
    }
  _update = false;
  if (_inventory["nourriture"] < (10 + (_level * 3)))
    lookFor("nourriture");
  else
    {
      if (tryIncant() == false)
	getMissingStones();
      else
	{
	  std::cout << "ON ARRETE l'INCANT apres tryincant;\n";
      	  std::string msg = "broadcast STOPINV " + _ID;
	  _todo.push_back(msg);
	}
    }


}

void			AI::listenSummon()
{
  static std::vector<std::string>	invID;
  std::string			newID;

  if (_foodBegin != -1)
    {
      if (_cmdRcv.find("RDY") != std::string::npos && _cmdRcv.find(std::to_string((_level))) != std::string::npos)
	{
	  std::cout << "ON A RECU UN RDY BORDEL\n";
	  if (invID.size() < (unsigned)_lvlUp[std::make_pair(_level, "joueur")] - 1)
	    {
	      std::cout << "SUMMON MSG == " << _cmdRcv << std::endl;
	      //	      newID = _cmdRcv.substr(_cmdRcv.find('(') + 1, ((_cmdRcv.find('(') + 1) - _cmdRcv.find(','))); // TODO verifier qu'on ai exactement l'ID
	      newID = _cmdRcv;
	      newID.erase(0, 17);
	      std::cout << "new ID = " << newID;
	      invID.push_back(newID);
	    }
	}
      if (_foodBegin - _inventory["nourriture"] > 1)
	{
	  std::cout << "On call les gens, si assez de reponse!\n";
	  std::cout << "ppl nbr = " << invID.size() << std::endl;
	  std::cout << "we need " << (unsigned)_lvlUp[std::make_pair(_level, "joueur")] << std::endl;
	  if (invID.size() >= (unsigned)_lvlUp[std::make_pair(_level, "joueur")] - 1)
	    {
	      std::string cmd = "broadcast OKINVOC(";
	      cmd += _ID;
	      std::cout << "ON LES CALL TOUUUUUUUUUUSSSS\n";
	      for (unsigned int i = 0; i < (unsigned)_lvlUp[std::make_pair(_level, "joueur")] - 1; ++i)
		{
		  cmd += ", ";
		  cmd += invID[i];
		}
	      std::cout << "on send " << cmd << std::endl;
	      _cmdSnd = cmd;
	      _foodBegin = -1;
	      return;
	    }
	  else
	    {
	      std::cout << "PAS ASSEZ DE REPONNNNSE\n";
	      _waitSum = false;
	    }
	  _foodBegin = -1;
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
  std::cout << "tried inv == " << _triedInv << std::endl;
  if (peopleNbr < _lvlUp[std::make_pair(_level, "joueur")] && _triedInv == false && _waitSum != true)
    {
      std::cout << "ON RAMENE LA MILLEFA" << std::endl;
      _triedInv = true;
      _waitSum = true;
      _foodBegin = _inventory["nourriture"];
      std::string msg = "broadcast INV(";
      msg += std::to_string(_level);
      msg += ")";
      //TODO se mettre en position d'ecoute immobile pendant... 2? unité de bouffe. (pour pas qu'il en ramasse plus et fausse le calcul); On ne le lance qu'une fois par niveau. Si ca echoue, on deviendra non plus hote mais guest de la prochaine invoc'
      _todo.push_back(msg);
      return false;
    }
  if (peopleNbr == _lvlUp[std::make_pair(_level, "joueur")] && _triedInv == false)
    {
      grabAll();
      dropToIncant();
      _todo.push_back("incantation");
      return (true);
    }
  return false;
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
  for (unsigned int i = 0; i < _stones.size(); ++i)
    {
      if (_inventory[_stones[i]] < _lvlUp[std::make_pair(_level, _stones[i])])
	lookFor(_stones[i]);
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
  _triedInv = false;
  return;
}

void			AI::vision()
{

  if (_cmdRcv.find("{ ") != std::string::npos)
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
}

void			AI::inventory()
{
  if (_cmdRcv.find("{n") != std::string::npos)
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
	  number = std::stoi(tmp[i].substr(tmp[i].find(" ")));
	  thing = tmp[i].substr(0, tmp[i].find(" "));
	  _inventory[thing] = number;
	}
      _isWaiting = false;
    }
}
