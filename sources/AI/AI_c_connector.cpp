//
// AI_c_connector.cpp for zappy in /home/cache-_s/rendu/PSU_2014_zappy
// 
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
// 
// Started on  Wed Jun 24 11:39:45 2015 Sebastien Cache-Delanos
// Last update Fri Jul  3 16:12:19 2015 Sebastien Cache-Delanos
//

#include			<cstdlib>

#include			"AI_c_connector.h"
#include			"AI.hpp"

#ifdef __cplusplus
extern "C" {
#endif

  static AI *AI_instance = NULL;

  void lazyAI()
  {
    if (AI_instance == NULL)
      {
	AI_instance = new AI();
      }
  }

  char* AI_call(const char *cmdRcv)
  {
    lazyAI();
    return (AI_instance->call(cmdRcv));
  }

  void AI_setId(int id)
  {
    lazyAI();
    return (AI_instance->setId(id));
  }


#ifdef __cplusplus
}
#endif
