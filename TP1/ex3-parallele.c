
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>
#include <sys/wait.h>
int i;
int main(int argc, char const *argv[])

{
    int retour;
    for(i = 1 ; i < argc ; i++){
        retour = fork();
        if(retour == 0){
            break;
        }
    }

    if(retour == 0){
        char *argv1[6];
        const char *fichier = argv[i];
        const char *mod = "Modified-";
        argv1[0] = "convert";
        argv1[1] = fichier;
        argv1[2] = "-radial-blur";
        argv1[3] = "10";

        //Bug avec StrCat, solution alternative :
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
    }

    wait(NULL);
        
    return 0;
}
    
