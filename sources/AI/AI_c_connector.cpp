//
// AI_c_connector.cpp for zappy in /home/cache-_s/rendu/PSU_2014_zappy
//
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
//
// Started on  Wed Jun 24 11:39:45 2015 Sebastien Cache-Delanos
// Last update Sun Jun 28 17:30:16 2015 Pierre Charie
//

#include			<cstdlib>

#include			"AI_c_connector.h"
#include			"AI.hpp"
#include			"Ai.hpp"

#ifdef __cplusplus
extern "C" {
#endif

  static Ai *AI_instance = NULL;

  void lazyAI()
  {
    if (AI_instance == NULL)
      {
	AI_instance = new Ai(42); //TODO transmettre du client l'ID
      }
  }

  char* AI_call(const char *cmdRcv)
  {
    lazyAI();
    return (AI_instance->action(cmdRcv));
  }

#ifdef __cplusplus
}
#endif
