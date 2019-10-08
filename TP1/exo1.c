/*
HARIAN
Elyoth
EISE


        TP1 Exercice 1



ps permet de visualiser les différents processus utilisateurs en cours d'éxecution par L'OS


ps u permet de visualiser les processus utilisateurs mais aussi leurs caractéristiques soit le pourcentage d'utilisation par le CPU ou la mémoire,
 ou encore leurs status.

ps ux permet de visualiser l'historique de tout les processus utilisateurs réalisés depuis l'ouverture de la session.


ps aux renvoi tous les processus en cours d'éxecution par le système entier depuis le root.

ps faux premet de visualiser ps aux au format d'arbre.

pstree fait comme ps faux avec une visualisation graphique d'arbre plus lisible.

htop ou top permet de visualiser tous les processus en temps réels.

//1.2

├─mate-terminal─┬─bash─┬─pstree
│               │      └─xterm───bash─┬─xeyes
│               │                     └─xterm───bash───xclock
│               ├─{dconf worker}
│               ├─{gdbus}
│               └─{gmain}

*/

//1.3

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char const *argv[]) {
  pid_t retour;
  pid_t retour2;
  retour = fork();
  switch(retour){
    case 0 :
      retour2 = fork();
      if(retour2 != 0){
        fork();
      }
      break;
    case -1 :
      printf("Erreur pas de création de fils");
      break;
    default :
      break;

  return 0;
}
