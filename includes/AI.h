/*
** AI.h for zappy in /home/cache-_s/rendu/PSU_2014_zappy
** 
** Made by Sebastien Cache-Delanos
** Login   <cache-_s@epitech.net>
** 
** Started on  Wed Jun 24 11:30:33 2015 Sebastien Cache-Delanos
// Last update Wed Jun 24 19:19:56 2015 Sebastien Cache-Delanos
*/

#ifndef				AI_H
# define			AI_H

# include			<iostream>
# include			<map>

class				AI
{
public:

  AI();
  ~AI();

  const char*			call(const char* cmdRdv);

private:

  void				forward();
  void				right();
  void				left();
  void				vision();
  void				inventory();
  void				expulse();
  void				incantation();
  void				fork();
  void				connect_nbr();
  void				death();

  std::string			_cmdRcv;
  std::string			_cmdSnd;
  bool				_isWaiting;

  typedef void (AI::*handleResponse)();
  std::map<std::string, handleResponse>	_handleResponse;
};

#endif				//AI_H
