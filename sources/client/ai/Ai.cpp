//
// Ai.cpp for  in /home/charie_p/rendu/PSU_2014_zappy/sources/client/ai
//
// Made by Pierre Charie
// Login   <charie_p@epitech.net>
//
// Started on  Wed Jun 17 17:31:45 2015 Pierre Charie
// Last update Tue Jun 23 15:12:08 2015 Pierre Charie
//

#include "Ai.cpp"

Ai::Ai(int ID)
{
  _ID = std::to_string(ID);
  _level = 1;
}

Ai::~Ai()
{
  mort; //TODO
}

void Ai::setInventory()
{
  std::string inventory;
  std::string bigItem;
  std::string item;
  std::string number;
  int nbr
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
  if (cmd.find("OKINV") && cmd.find(_targetID))
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
  this->setInventory();
  if (_inventory[nourriture] < 126)
    ;//TODO chercher bouffe dans champ de vision et y aller.
}

void Ai::action()
{

  //TODO select broadcast:
  // Si on recoit "AliveCheck", on repond "Alive(sonLvl)"
  // Si on recoit "PING sonID", on répond "PONG sonID"
  // Si on recoit "INV(LVL)" et qu'on est du bon level, on répond la même chose;
  // Si on envoit la demande d'invocation, on compte en static le nombre de réponse. Si pas assez, on reset;
  // Si on recoit "OKINV(uneID, LVL), on rush cet endroit. (en ping pong)
  // Si on recoit "STOPINV(uneID, LVL), et qu'on s'y dirigeait, on abandonne; (deja assez de gens)
}
