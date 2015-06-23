/*
** cmd_move_forward.c for  in /home/bourma_m/Projet/SystemUnix/zappy/sources/serveur
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Fri May  8 11:35:41 2015 Mathieu Bourmaud
** Last update Mon Jun 15 16:20:43 2015 Mathieu Bourmaud
*/

#include		"serveur.h"

int			cmd_see(t_serv *serv, t_client *client, char *cmd)
{
  (void)serv;
  (void)cmd;
  if (my_write(client->fd, "cmd_see") == EXIT_FAILURE)
    return (EXIT_FAILURE);

  /* 
     Permet de regarder ce qui se trouve sur les cases alentours, en fonction d'un champ de vision. Le champ de vision augmente en fonction du niveau d'incantation et commence à 1.
     -
     
     char *algodelamortquitue(t_client *player)
     {
      char *oùestquoi;
      int i = 0;
      tmp_x_left = player->posX; //Seulement au début pour donner la valeur de départ du joueur
      tmp_x_right = player->posX; // Pareil que ci dessus
      tmp_y = player->posY; 

      regarder à player->pos
      si rien sur la case écrire ",", sinon écrire "Nom de l'objet," dans oùestquoi;
      i++;

      tant que i != player->lvl 
      {
      	//A réfléchir mais en gros rajouter + 2 à chaque incrémentation de level de chaque coté des cases du lvl du dessous.
	 i++;
      }
      return (oùestquoi);
     }

     
     Rien a envoyer à la GFX
     Send to IA : case1, case2, case3 [...]
       Exemple -> thysthame,,,nourriture,,
   */
  return (EXIT_SUCCESS);
}
