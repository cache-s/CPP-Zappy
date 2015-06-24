//
// AI.cpp for zappy in /home/cache-_s/rendu/PSU_2014_zappy/sources/AI
// 
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
// 
// Started on  Wed Jun 24 11:29:59 2015 Sebastien Cache-Delanos
// Last update Wed Jun 24 11:38:37 2015 Sebastien Cache-Delanos
//

#include		"AI.h"

AI::AI()
{

}

AI::~AI()
{

}

const char*		AI::sayHello(const char* name)
{
  std::cout << "Hello " << name << " !" << std::endl;
  return (name);
}
