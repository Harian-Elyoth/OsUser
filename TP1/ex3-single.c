
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]) {
  char *argv1[6];
  const char *fichier = argv[1];
  switch(fork()){
    case -1 :
      printf("Erreur\n");
      break;
    case 0 :
      printf("Fichier : %s\n", fichier);
      argv1[0] = "convert";
      argv1[1] = fichier;
      argv1[2] = "-radial-blur";
      argv1[3] = "10";
      char *NouveauNomFichier = "Modified-"; 
      printf("NouveauNom1 : %s\n", NouveauNomFichier);
      strcat(NouveauNomFichier, fichier);//Ce code c'est de la merde
      printf("NouveauNom2 : %s\n", NouveauNomFichier);

      argv1[4] = NouveauNomFichier;
      argv1[5] = NULL;
      execv("/usr/bin/convert", argv1);
      break;
    default :
      printf("Je suis le papa \n");
      wait(2);
      break;
  }
  return 0;
}
