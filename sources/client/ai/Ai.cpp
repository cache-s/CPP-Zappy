//
// Ai.cpp for  in /home/charie_p/rendu/PSU_2014_zappy/sources/client/ai
//
// Made by Pierre Charie
// Login   <charie_p@epitech.net>
//
// Started on  Wed Jun 17 17:31:45 2015 Pierre Charie
// Last update Mon Jun 29 14:44:56 2015 Pierre Charie
//

#include "Ai.hpp"

Ai::Ai(int ID)
{
  _ID = std::to_string(ID);
  _level = 1;

  _forUp[std::make_pair(1, "joueur")] = 1;
  _forUp[std::make_pair(2, "joueur")] = 2;
  _forUp[std::make_pair(3, "joueur")] = 2;
  _forUp[std::make_pair(4, "joueur")] = 4;
  _forUp[std::make_pair(5, "joueur")] = 4;
  _forUp[std::make_pair(6, "joueur")] = 6;
  _forUp[std::make_pair(7, "joueur")] = 6;

  _forUp[std::make_pair(1, "linemate")] = 1;
  _forUp[std::make_pair(2, "linemate")] = 1;
  _forUp[std::make_pair(3, "linemate")] = 2;
  _forUp[std::make_pair(4, "linemate")] = 1;
  _forUp[std::make_pair(5, "linemate")] = 1;
  _forUp[std::make_pair(6, "linemate")] = 1;
  _forUp[std::make_pair(7, "linemate")] = 2;

  _forUp[std::make_pair(1, "deraumêre")] = 0;
  _forUp[std::make_pair(2, "deraumêre")] = 1;
  _forUp[std::make_pair(3, "deraumêre")] = 0;
  _forUp[std::make_pair(4, "deraumêre")] = 1;
  _forUp[std::make_pair(5, "deraumêre")] = 2;
  _forUp[std::make_pair(6, "deraumêre")] = 2;
  _forUp[std::make_pair(7, "deraumêre")] = 2;

  _forUp[std::make_pair(1, "sibur")] = 0;
  _forUp[std::make_pair(2, "sibur")] = 1;
  _forUp[std::make_pair(3, "sibur")] = 1;
  _forUp[std::make_pair(4, "sibur")] = 2;
  _forUp[std::make_pair(5, "sibur")] = 1;
  _forUp[std::make_pair(6, "sibur")] = 3;
  _forUp[std::make_pair(7, "sibur")] = 2;

  _forUp[std::make_pair(1, "mendiane")] = 0;
  _forUp[std::make_pair(2, "mendiane")] = 0;
  _forUp[std::make_pair(3, "mendiane")] = 0;
  _forUp[std::make_pair(4, "mendiane")] = 0;
  _forUp[std::make_pair(5, "mendiane")] = 3;
  _forUp[std::make_pair(6, "mendiane")] = 0;
  _forUp[std::make_pair(7, "mendiane")] = 2;

  _forUp[std::make_pair(1, "phiras")] = 0;
  _forUp[std::make_pair(2, "phiras")] = 0;
  _forUp[std::make_pair(3, "phiras")] = 2;
  _forUp[std::make_pair(4, "phiras")] = 1;
  _forUp[std::make_pair(5, "phiras")] = 0;
  _forUp[std::make_pair(6, "phiras")] = 1;
  _forUp[std::make_pair(7, "phiras")] = 2;

  _forUp[std::make_pair(1, "thystame")] = 0;
  _forUp[std::make_pair(2, "thystame")] = 0;
  _forUp[std::make_pair(3, "thystame")] = 0;
  _forUp[std::make_pair(4, "thystame")] = 0;
  _forUp[std::make_pair(5, "thystame")] = 0;
  _forUp[std::make_pair(6, "thystame")] = 0;
  _forUp[std::make_pair(7, "thystame")] = 1;

}

Ai::~Ai()
{
}

void		Ai::setInventory(std::string inventory) //Work
{
  std::string	bigItem;
  std::string	item;
  std::string	number;
  int		nbr;
  std::istringstream iss(inventory);

  while(std::getline(iss, bigItem, ','))
    {
      std::istringstream issItem(bigItem);
      std::getline(issItem, item, ' ');
      if (item[0] == '{')
	item.erase(0,1);
      if (item[0] == ' ')
	item.erase(0,1);
      std::getline(issItem, number);
      std::istringstream (number) >> nbr;
      // std::cout << "item = " << item << " nbr = " << nbr << std::endl;
      _inventory[item] = nbr;
    }

}

void Ai::setVision(std::string canSee) //WORK
{
  std::string	mapCase;
  std::string	item;
  int		caseNbr = 0;

  std::istringstream iss(canSee);


  while(std::getline(iss, mapCase, ','))
    {
      std::istringstream issItem(mapCase);
      while (std::getline(issItem, item, ' '))
	{
	  if (item[0] == '{')
	    item.erase(0,1);
	  if (item.find('}') != std::string::npos)
	    item.erase(item.find('}'));
	  while (item[0] == ' ')
	    item.erase(0,1);
	  if (item != "")
	    std::cout << "item " << item << " at case " << caseNbr << std::endl;
	  _vision[caseNbr].push_back(item);
	}
	caseNbr++;
    }
}

void Ai::communicate(std::string cmd)
{
  std::string answer;

  if (cmd.find("AliveCheck") != std::string::npos)
    throw to_C("broadcast Alive");
  if (cmd.find("PING") != std::string::npos && cmd.find(_ID) != std::string::npos)
    {
      std::string ret =  "broadcast PONG " + _ID;
      throw to_C(ret.c_str());
    }
  if (!_targetID.empty())
    {
      if (_waitPong != true)
	{
	  _waitPong = true;
	  std::string ret = "broadcast PING " + _targetID;
	  throw to_C(ret.c_str());
	}
      if (cmd.find("PONG") != std::string::npos && cmd.find(_targetID) != std::string::npos)
	{
	  _waitPong = false;
	  int direction = cmd[8] - '0';
	  move(direction);
	}
    }
  if (cmd.find ("INV(") != std::string::npos && cmd.find(_level) != std::string::npos)
    {
      std::string ret = "broadcast ";
      cmd.erase(0, 10);
      ret += cmd;
      throw to_C(ret);
    }
  if (cmd.find("OKINV") != std::string::npos && cmd.find(_level) != std::string::npos) //TODO verifier si la syntaxe issue de getline est correcte
    {
      cmd.erase(0, cmd.find('('));

      std::istringstream iss(cmd);
      std::string line;
      std::getline(iss, line, ',');
      _targetID = line;
    }
  if (cmd.find("STOPINV") != std::string::npos && cmd.find(_targetID) != std::string::npos)
    _targetID.clear();
}


void	Ai::move(int direction)
{
  if (!_targetID.empty() && direction != 0)
    {
      //"broadcast PING " + _targetID; TODO
      //direction = on listen jusqu'a un pong _targetID);
      if (direction == 8 || direction == 1 || direction == 2)
	throw to_C("avance");
      if (direction == 6 || direction == 7)
	throw to_C("droite");
      if (direction == 4 || direction == 3 || direction == 5)
	throw to_C("gauche");
    }
  else
    {
      srand (time(NULL));
      direction = rand() % 10;
      if (direction < 4)
	throw to_C("gauche");
      else
	throw to_C("avance");
    }
}

void	Ai::checkInventory()
{
}

void	Ai::setInstruction(int mapCase, std::string obj) //WORK
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
  std::cout << "pos = " << pos << "median =" << median << std::endl;

  std::cout << "Y = " << y << " X = " << x << std::endl;

  while (y > 0)
    {
      _instruction.push_back("avance");
      y--;
    }
  if (x > 0)
    {
      _instruction.push_back("droite");
      while (x > 0)
	{
	  _instruction.push_back("avance");
	  x--;
	}
    }
  else if (x < 0)
    {
      _instruction.push_back("gauche");
      while (x < 0)
	{
	  _instruction.push_back("avance");
	  x++;
	}
    }
  std::string tmp;
  tmp = "prend " + obj;
  _instruction.push_back(tmp);
}

void	Ai::checkVision()
{
  int i = 0;

  while (i < (((_level + 1) * _level) + _level))
    {
      size_t j = 0;
      while (j < _vision[i].size())
      	{
	  std::string item = _vision[i][j];
      	  if ((item == "nourriture" && _inventory["nourriture"] < 126) || (item != "nourriture" && item != "joueur" && item != "" && _inventory[item] < _forUp[std::make_pair(_level, item)]))
      	    {
	      std::cout << "item en vue! = " << item << " case " << i << std::endl;
      	      if (i == 0)
		{
		  std::string inst = "prend " + item;
		  throw to_C(inst);
		}
      	      else
      	  	setInstruction(i, item);
      	    }
      	  j++;
      	}
      i++;
    }
}

#include <unistd.h>

char *Ai::action(std::string msg)
{

  try
    {
      usleep(100000);
      std::cout << "debut IA : msg = " << msg << std::endl;
      // if (msg.find("ok") != std::string::npos || msg.find("ko") != std::string::npos) //TODO gestion du KO
      // 	{
      // 	  std::cout << "NULL\n";
      // 	  return NULL;
      // 	}
      if (_waitOk == true)
      	{
      	  if (msg.find("ok") != std::string::npos || msg.find("ko") != std::string::npos)
      	    _waitOk = false;
      	  else
      	    throw to_C(_lastInstruction);
      	}
      std::cout << "1" << std::endl;
      communicate(msg);
      std::cout << "2" << std::endl;
      if (_waitInventory != true && (_inventory.empty()))
      	{
      	  _waitInventory = true;
      	  throw to_C("inventaire");
      	}
      std::cout << "3" << std::endl;
      if (_waitInventory == true)
      	{
      	  if (msg[0] == '{')
      	    {
      	      std::cout << "inventaire = " << msg << std::endl;
      	      _waitInventory = false;
      	      this->setInventory(msg);
      	    }
      	  else
      	    throw to_C("inventaire");
       	}
      if (_waitVision != true && (_vision.empty()))
      	{
      	  _waitVision = true;
      	  std::cout << "Vision!\n";
      	  throw to_C("voir");
      	}
      if (_waitVision == true)
      	{
      	  if (msg[0] == '{')
      	    {
      	      _waitVision = false;
      	      std::cout << "we see " << msg;
      	      this->setVision(msg);
      	    }
      	  else
      	    throw to_C("voir");
      	}
      if (!_instruction.empty())
      	{
      	  std::string cmd = _instruction.front();
      	  _instruction.pop_front();
      	  std::cout << "instruction : " << cmd;
      	  throw to_C(cmd.c_str());
      	}
      if (_mustWait == true)
      	return NULL;

      checkVision();
      if (!_instruction.empty())
      	{
      	  std::string cmd = _instruction.front();
      	  _instruction.pop_front();
      	  std::cout << "instruction : " << cmd << std::endl;
      	  throw to_C(cmd.c_str());
      	}
      // //   //faire OP ici;
      // //   std::cout << "On a rien a faire : msg = " << msg << std::endl;
      move(0);
    }
  catch (const to_C &e)
    {
      _vision.clear();
      // std::cout << "On a un objectif " << msg << std::endl;
      std::cout << "commande = " << e.what() << std::endl;
      std::string cmd = e.what();
      if (cmd.find("prend") != std::string::npos)
	  {
	    _lastInstruction = cmd;
	    _waitOk = true;
	  }
      return (char*)e.what();
    }
  return NULL;
  //TODO select broadcast:
  // Si on envois PING, on passe mustWait à false tant qu'on recoit pas pong.
  // Si on recoit "INV(LVL)" et qu'on est du bon level, on répond la même chose;
  // Si on envoit la demande d'invocation, on compte en static le nombre de réponse. Si pas assez, on reset;
  // Si on recoit "OKINV(uneID, LVL), on rush cet endroit. (en ping pong)
  // Si on recoit "STOPINV(uneID, LVL), et qu'on s'y dirigeait, on abandonne; (deja assez de gens)
}
