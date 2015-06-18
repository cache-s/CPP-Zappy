//
// Ai.cpp for  in /home/charie_p/rendu/PSU_2014_zappy/sources/client/ai
//
// Made by Pierre Charie
// Login   <charie_p@epitech.net>
//
// Started on  Wed Jun 17 17:31:45 2015 Pierre Charie
// Last update Thu Jun 18 13:32:01 2015 Pierre Charie
//

#include "Ai.cpp"

Ai::Ai()
{

}

Ai::~Ai()
{

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

void Ai::action()
{

  //TODO select :
  // Si on recoit "AliveCheck", on repond "Alive(sonID)"
  // Si on recoit "PING sonID", on répond "PONG sonID"
  // Si on recoit "INV(uneID, LVL)" et qu'on est du bon level, on répond la même chose, avec la même ID;
  // Si on envoit la demande d'invocation, on compte en static le nombre de réponse. Si pas assez, on reset;
  // Si on recoit "OKINV(uneID, LVL), on rush cet endroit. (en ping pong)
  // Si on recoit "STOPINV(uneID, LVL), et qu'on s'y dirigeait, on abandonne; (deja assez de gens)
}
