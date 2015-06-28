//
// Ai.cpp for  in /home/charie_p/rendu/PSU_2014_zappy/sources/client/ai
//
// Made by Pierre Charie
// Login   <charie_p@epitech.net>
//
// Started on  Wed Jun 17 17:31:45 2015 Pierre Charie
// Last update Sun Jun 28 17:35:50 2015 Pierre Charie
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

void		Ai::setInventory(std::string inventory)
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
      if (item[0] == ' ')
	item.erase(1,1);
      std::getline(issItem, number);
      std::istringstream (number) >> nbr; //a verif que ca marche
      _inventory[item] = nbr; // ou _inventory.insert( std::make_pair(item, nbr) ); ?
    }

}

void Ai::setVision(std::string canSee)
{
  std::string	mapCase;
  std::string	item;
  int		caseNbr = 0;
  bool		bDone;

  std::istringstream iss(canSee);

  while(std::getline(iss, mapCase, ','))
    {
      std::istringstream issItem(mapCase);
      bDone = false;
      while (std::getline(issItem, item, ' '))
	{
	  if (item[0] == ' ')
	    item.erase(1,1);
	  _vision[caseNbr].push_back(item);
	  caseNbr++;
	  bDone = true;
	}
      if (bDone == false)
	caseNbr++;
    }
}

void Ai::communicate(std::string cmd)
{
  std::string answer;

  if (cmd.find("AliveCheck"))
    throw to_C("broadcast Alive");
  if (cmd.find("PING") && cmd.find(_ID))
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
      if (cmd.find("PONG") && cmd.find(_targetID))
	{
	  _waitPong = false;
	  int direction = cmd[8] - '0';
	  move(direction);
	}
    }
  if (cmd.find ("INV(") && cmd.find(_level))
    {
      std::string ret = "broadcast ";
      cmd.erase(0, 10);
      ret += cmd;
      throw to_C(ret);
    }
  if (cmd.find("OKINV") && cmd.find(_level)) //TODO verifier si la syntaxe issue de getline est correcte
    {
      cmd.erase(0, cmd.find('('));

      std::istringstream iss(cmd);
      std::string line;
      std::getline(iss, line, ',');
      _targetID = line;
    }
  if (cmd.find("STOPINV") && cmd.find(_targetID))
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

void	Ai::setInstruction(int mapCase, std::string obj)
{
  int y = 0, x = 0, pos = 0, i = 3, median = 0;

  while (pos <= mapCase)
    {
      pos += i;
      i += 2;
      y++;
    }
  median = (pos + 1 + pos - i) / 2;
  x = pos - median;

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
  else
    {
      _instruction.push_back("gauche");
      while (x < 0)
	{
	  _instruction.push_back("avance");
	  x++;
	}
    }
  std::string tmp;
  tmp = "ramasse " + obj;
  _instruction.push_back(tmp);
}

void	Ai::checkVision()
{
  int i = 0;

  while (i < ((_level * 2) - 1))
    {
      size_t j = 0;
      while (j < _vision[i].size())
      	{
	  std::string item = _vision[i][j];
      	  if ((item == "nourriture" && _inventory["nourriture"] < 126) || (item != "nourriture" && _inventory[item] < _forUp[std::make_pair(_level, item)]))
      	    {
      	      if (i == 0)
      	  	throw to_C("ramasse");
      	      else
      	  	setInstruction(i, item);
      	    }
      	  j++;
      	}
      i++;
    }
}

char *Ai::action(std::string msg)
{

  try
    {
      communicate(msg);
      if (_waitInventory != true && (_inventory.empty()  || msg.find("ko")))
	{
	  _waitInventory = true;
	  return((char*)"inventaire");
	}
      if (_waitInventory == true)
	this->setInventory(msg);
      if (_waitVision != true &&  _vision.empty())
	{
	  _waitVision = true;
	  return((char*)"voir");
	}
      if (_waitVision == true)
	this->setVision(msg);
      if (!_instruction.empty())
	{
	  std::string cmd = _instruction.front();
	  _instruction.pop_front();
	  return (char*)cmd.c_str();
	}
      if (_mustWait == true)
	return NULL;

      checkVision();
      //faire OP ici;
      move(0);
    }
  catch (const to_C &e)
    {
      _vision.clear();
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
