//
// AI_c_connector.cpp for zappy in /home/cache-_s/rendu/PSU_2014_zappy
// 
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
// 
// Started on  Wed Jun 24 11:39:45 2015 Sebastien Cache-Delanos
// Last update Wed Jun 24 18:05:23 2015 Sebastien Cache-Delanos
//

#include			<cstdlib>

#include			"AI_c_connector.h"
#include			"AI.h"

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

  const char* AI_call(const char *cmdRcv)
  {
    lazyAI();
    return (AI_instance->call(cmdRcv));
  }

#ifdef __cplusplus
}
#endif
