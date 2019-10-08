
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>

int main(int argc, char const *argv[]) {
  char *argv1[6];
  switch(fork()){
    case -1 :
      printf("Erreur\n");
      break;
    case 0 :
      argv1[0] = "convert";
      argv1[1] = "../images/ireland1.jpg";
      argv1[2] = "-radial-blur";
      argv1[3] = "10";
      argv1[4] = "/images/ireland1blurredbyex3.jpg";
      argv1[5] = NULL;
      execv("/usr/bin/convert", argv1);
      break;
    default :
      printf("Je suis le papa \n");
      wait(NULL);
      break;
  }
  return 0;
}
