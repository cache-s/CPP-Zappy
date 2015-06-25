<//
// Ai.cpp for  in /home/charie_p/rendu/PSU_2014_zappy/sources/client/ai
//
// Made by Pierre Charie
// Login   <charie_p@epitech.net>
//
// Started on  Wed Jun 17 17:31:45 2015 Pierre Charie
// Last update Thu Jun 25 12:01:18 2015 Pierre Charie
//

#include "Ai.cpp"

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
  mort; //TODO
}

void		Ai::setInventory()
{
  std::string	inventory;
  std::string	bigItem;
  std::string	item;
  std::string	number;
  int		nbr;
  //inventory = inventaire(); //TODO
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

void Ai::setVision()
{
  std::string	canSee;
  std::string	mapCase;
  std::string	item;
  int		caseNbr = 0;
  bool		bDone;

  //canSee = vision() //TODO
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

  if (cmd == "AliveCheck")
    answer = "Alive(" + _level + ")";
  if (cmd.find ("PING ") && cmd.find(_ID))
    answer = "PONG " + _ID;
  if (cmd.find ("INV(") && cmd.find(_level))
    answer = cmd;
  if (cmd.find("OKINV") && cmd.find(_level)) //TODO verifier si la syntaxe issue de getline est correcte
    {
      str.erase (str.begin(), str.find("("));

      std::istringstream iss(cmd);
      std::string line;
      getline(iss, line, ",");
      _targetID == line;
    }
  if (cmd.find("STOPINV") && cmd.find(_targetID))
    _targetID = NULL;
  //todo envois answer;
}


void Ai::move()
{
  int direction;
  if (_targetID != NULL)
    {

      //"broadcast PING " + _targetID; TODO
      //direction = on listen jusqu'a un pong _targetID);
      if (direction == 8 || direction == 1 || direction == 2)
	avance; //TODO
      if (direction == 6 || direction == 7)
	droite; //TODO
      if (direction == 4 || direction == 3 || direction == 5)
	gauche; //TODO
    }
  else
    {
      srand (time(NULL));
      direction = rand() % 10;
      if (direction < 4)
	gauche; //TODO
      else
	avance; //TODO
    }
}

void Ai::checkInventory()
{
}

void Ai::checkVision()
{
  int i = 0;

  while (i < ((_level * 2) - 1))
    {
      int j = 0;
      while (_vision[i][j])
	{
	  if (_inventory[_vision[i][j]] < _forUp[std::make_pair(_level, _vision[i][j])])
	    {
	      if (i == 0)
		ramasse;
	      else
		{
		  //TODO on y va
		}
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
      if (_inventory == NULL || msg.find("ko"))
	this->setInventory();
      if (_vision == NULL)
	this->setVision();
      if (!_instruction.empty())
	{
	  std::string cmd = _instruction.front(); //TODO
	  _instruction.pop_front();
	  return cmd; //TODO
	}
      if (_mustWait == true)
	return NULL;

      checkVision();
      //faire OP ici;
    }
  catch (const to_C &e)
    {
      return e.what();
    }

  // _inventory = NULL;
  _vision = NULL;

  //TODO select broadcast:
  // Si on envois PING, on passe mustWait à false tant qu'on recoit pas pong.
  // Si on recoit "INV(LVL)" et qu'on est du bon level, on répond la même chose;
  // Si on envoit la demande d'invocation, on compte en static le nombre de réponse. Si pas assez, on reset;
  // Si on recoit "OKINV(uneID, LVL), on rush cet endroit. (en ping pong)
  // Si on recoit "STOPINV(uneID, LVL), et qu'on s'y dirigeait, on abandonne; (deja assez de gens)
}
