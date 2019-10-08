/*
HARIAN
Elyoth
EISE


        TP1 Exercice 2

*/

/*2.1 Un processus zombie est un processus qui s'est achevé,
 mais qui dispose toujours d'un identifiant de processus (PID) et reste donc encore visible dans la table des processus*/

//2.2

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char const *argv[]) {

  int retour;
  for(int i = 1 ; i < 6 ; i++){
    retour = fork();
    if(retour == 0){
      break;
    }
    printf("\nMon %deme fils a pour PID %d\n", i, retour);
  }
  if(retour != 0){
    sleep(10);
  }

  return 0;
}

/*3671069   3815  0.0  0.0  13448  5404 pts/0    Ss   11:00   0:00 bash
3671069   7522  0.0  0.1  69804 10212 pts/0    S    11:54   0:00  \_ xterm
3671069   7527  0.0  0.0  13440  5216 pts/1    Ss   11:54   0:00  |   \_ bash
3671069   7828  0.0  0.0   4220   776 pts/1    S+   12:00   0:00  |       \_ ./exo2
3671069   7829  0.0  0.0      0     0 pts/1    Z+   12:00   0:00  |           \_ [exo2] <defunct>
3671069   7830  0.0  0.0      0     0 pts/1    Z+   12:00   0:00  |           \_ [exo2] <defunct>
3671069   7831  0.0  0.0      0     0 pts/1    Z+   12:00   0:00  |           \_ [exo2] <defunct>
3671069   7832  0.0  0.0      0     0 pts/1    Z+   12:00   0:00  |           \_ [exo2] <defunct>
3671069   7833  0.0  0.0      0     0 pts/1    Z+   12:00   0:00  |           \_ [exo2] <defunct>
3671069   7834  0.0  0.0  27784  2872 pts/0    R+   12:00   0:00  \_ ps fu

On remarque que tout les enfants sont des Zombies : Z+ ; et que le parent est en Sleep : S*/
