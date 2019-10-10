
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]) {
  char *argv1[6];
  const char *fichier = argv[1];
  const char *mod = "Modified-";
  argv1[0] = "convert";
  argv1[1] = fichier;
  argv1[2] = "-radial-blur";
  argv1[3] = "10";
  int l = strlen(fichier) + strlen(mod);
  char *NouveauNomFichier = malloc(sizeof(char)*l); 

  for(int i = 0 ; i < l ; i++){
    if (i < strlen(mod)){
      NouveauNomFichier[i] = mod[i];
    } 
    else
      NouveauNomFichier[i] = fichier[i-strlen(mod)];  
  }

  argv1[4] = NouveauNomFichier;
  argv1[5] = NULL;
  execv("/usr/bin/convert", argv1);


  return 0;
}
