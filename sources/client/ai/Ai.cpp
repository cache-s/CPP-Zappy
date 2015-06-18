//
// Ai.cpp for  in /home/charie_p/rendu/PSU_2014_zappy/sources/client/ai
//
// Made by Pierre Charie
// Login   <charie_p@epitech.net>
//
// Started on  Wed Jun 17 17:31:45 2015 Pierre Charie
// Last update Wed Jun 17 18:20:20 2015 Pierre Charie
//

#include "Ai.cpp"

Ai::Ai()
{

}

Ai::~Ai()
{

}

void action()
{

  //TODO select :
  // Si on recoit "AliveCheck", on repond "Alive(sonID)"
  // Si on recoit "PING sonID", on répond "PONG sonID"
  // Si on recoit "INV(uneID, LVL)" et qu'on est du bon level, on répond la même chose, avec la même ID;
  // Si on envoit la demande d'invocation, on compte en static le nombre de réponse. Si pas assez, on reset;
  // Si on recoit "OKINV(uneID, LVL), on rush cet endroit. (en ping pong)
  // Si on recoit "STOPINV(uneID, LVL), et qu'on s'y dirigeait, on abandonne; (deja assez de gens)

  std::string tmpInventory;

  inventory =

}
