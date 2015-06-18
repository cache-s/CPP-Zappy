/*
** errors.h for  in /home/bourma_m/Projet/SystemUnix/PSU_2014_myftp
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Mon Mar  9 15:00:38 2015 Mathieu Bourmaud
** Last update Tue Jun 16 19:14:41 2015 Martin Porrès
*/

#ifndef		_ERRORS_H_
# define	_ERRORS_H_

#include	<string.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>

#define		USAGE			"Usage : ./server [[[-p port] -p port] ... ] [-x world_x] [-y world_y] [-c max_clients] [-t speed] -n team_name1 team_name2 ..."
#define		ERR_SERVER		"Command /server has failed. Try again\n\
Usage : /server ip port"
#define		ERR_PORT		"The port must contains only numbers."
#define		ERR_USAGE_SRV		"Usage : ./server port."
#define		ERR_USAGE_CLT		"Usage : ./client -n \"team name\" -p port [-h hostname]\n"
#define		ERR_SOCKET		"socket() has failed."
#define		ERR_BIND		"bind() has failed."
#define		ERR_LISTEN		"listen() has failed."
#define		ERR_SELECT		"select() has failed."
#define		ERR_ACCEPT		"accept() has failed."
#define		ERR_CONNECT		"connect() has failed."
#define		ERR_GETPROTO		"getprotobyname() has failed."
#define		ERR_READ		"read() has failed"
#define		ERR_WRITE		"write() has failed"
#define		ERR_REALLOC		"realloc() has failed"
#define		ERR_MALLOC		"malloc() has failed"
#define		ERR_CWD			"getcwd() has failed"
#define		ERR_CHDIR		"chdir() has failed"
#define		ERR_INIT_CLT		"init_client() has failed"
#define		ERR_INIT_SRV		"init_server() has failed"
#define		ERR_STRDUP		"strdup() has failed"
#define		ERR_STRCAT		"strcat() has failed"
#define		ERR_STRCPY		"strcpy() has failed"

#define		ERR_UNKNOWNCOMMAND	"421"
#define		N421			":Unknown command"
#define		ERR_NEEDMOREPARAMS	"461"
#define		N461			":Not enough parameters"
#define		ERR_ALREADYREGISTRED	"462"
#define		N462			":You may not reregister"
#define		ERR_NONICKNAMEGIVEN	"431"
#define		N431			":No nickname given"
#define		ERR_NICKNAMEINUSE	"433"
#define		N433			":Nickname is already in use"
#define		ERR_NOSUCHSERVER	"402"
#define		N402			"<server name> :No such server"
#define		RPL_LIST		"322"
#define		N322			"<channel> <# visible> :<topic>"
#define		RPL_LISTSTART		"321"
#define		N321			"Channel :Users  Name"
#define		RPL_LISTEND		"323"
#define		N323			":End of /LIST"
#define		ERR_INVITEONLYCHAN	"473"
#define		N473			"<channel> :Cannot join channel (+i)"
#define		ERR_CHANNELISFULL	"471"
#define		N471			"<channel> :Cannot join channel (+l)"
#define		RPL_TOPIC		"332"
#define		N332			"<channel> :<topic>"
#define		ERR_BANNEDFROMCHAN	"474"
#define		N474			"<channel> :Cannot join channel (+b)"
#define		ERR_BADCHANNELKEY	"475"
#define		N475			"<channel> :Cannot join channel (+k)"
#define		ERR_TOOMANYCHANNELS	"405"
#define		N405			"<channel name> :You have joined \
too many channels"
#define		ERR_ALREADYREGISTRED	"462"
#define		N462			":You may not reregister"
#define		ERR_NOSUCHSERVER	"402"
#define		N402			"<server name> :No such server"
#define		RPL_USERSSTART		"392"
#define		N392			":UserID   Terminal  Host"
#define		RPL_NOUSERS		"395"
#define		N395			":Nobody logged in"
#define		ERR_USERSDISABLED	"446"
#define		N446			":USERS has been disabled"
#define		ERR_FILEERROR		"424"
#define		N424			":File error doing <file op> on <file>"
#define		RPL_USERS		"393"
#define		N393			":%-8s %-9s %-8s"
#define		RPL_ENDOFUSERS		"394"
#define		N394			":End of users"
#define		ERR_NORECIPIENT		"411"
#define		N411			":No recipient given (<command>)"
#define		ERR_CANNOTSENDTOCHAN	"404"
#define		N404			"<channel name> :Cannot send to channel"
#define		ERR_WILDTOPLEVEL	"414"
#define		N414			"<mask> :Wildcard in toplevel domain"
#define		ERR_NOSUCHNICK		"401"
#define		N401			":No such nick/channel"
#define		RPL_AWAY		"301"
#define		N301			"<nick> :<away message>"
#define		ERR_NOTEXTTOSEND	"412"
#define		N412			":No text to send"
#define		ERR_NOTOPLEVEL		"413"
#define		N413			"<mask> :No toplevel domain specified"
#define		ERR_TOOMANYTARGETS	"407"
#define		N407			"<target> :Duplicate recipients. No \
message delivered"
#define		ERR_ERRONEUSNICKNAME	"432"
#define		N432			":Erroneus nickname"
#define		ERR_NOTONCHANNEL	"442"
#define		N442			":You're not on that channel"
#define		ERR_NOSUCHCHANNEL	"403"
#define		N403			":No such channel"
#define		ERR_NOTREGISTERED	"451"
#define		N451			":You have not registered"
#define		N001			"Welcome to the Internet Relay Network "
#define		RPL_WELCOME		"001"
#define		N002			"Your host is "
#define		RPL_YOURHOST		"002"
#define	        N003			"This server was created the 23/03/15"
#define		RPL_CREATED		"003"
#define		N004			"Created by Mathieu & Martin \
Server version 2.0"
#define		RPL_MYINFO		"004"
#define		VALID_CHARS		"_-.0123456789ABCDEFGHIJKLMNOPQRSTUV\
WXYZabcdefghijklmnopqrstuvxyz()#"

#define		BAD_CMD			"The command is not valid. Please, \
refer to the help by typing help."
#define		CMD_FAIL		"The command was valid but has failed"
#define		HELPS			"/user <username> <hostname> <servername>\
 <realname>\n\
/nick <nickname>\n\
/join <channel name>\n\
/part <channel name> (or the default one)\n\
/msg <nickname> <message>\n\
/send_file <nickname> <filepath>\n\
/accept_file <nickname>\n\
/users\n\
/list"

int		my_error(const char *);
char		*my_error_null(const char *);
int		my_error_close(const char *, int);

#endif
