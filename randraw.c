#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>

void write(FILE * f);

void main(){
    FILE * f;
    int nbPattern = 3;
    int i;

    srand(time(NULL));
    i = rand()%nbPattern;

    switch(i){
    case 0:
        f = fopen( "/home/yreln/Documents/Prog/C/randraw/paterns/hi.txt", "r");
        break;
    case 1:
        f = fopen( "/home/yreln/Documents/Prog/C/randraw/paterns/fish.txt", "r");
        break;
    case 2:
        f = fopen( "/home/yreln/Documents/Prog/C/randraw/paterns/star.txt", "r");
        break;
    
    default:
    
        break;
    }

    write(f);
}

void write(FILE * f){
    char * ligne = (char *) malloc(10000);
    char * ligneColorD = (char *) malloc(10000);
    char * ligneColorL = (char *) malloc(10000);

    char * ligneC = (char *) malloc(10000);

    int n=0;

	while (fgets(ligne, (10000), f) != NULL) {
        ligne[strlen(ligne)-1] = ' ';
		sprintf(ligneColorD, "%s\\033[0;30m%s\\033[0;31m%s\\033[0;32m%s\\033[0;33m%s\\033[0;34m%s\\033[0;35m%s\\033[0;36m%s\\033[0;37m%s\n",ligneColorD, ligne, ligne, ligne, ligne, ligne, ligne, ligne, ligne);
        sprintf(ligneColorL, "%s\\033[0;90m%s\\033[0;91m%s\\033[0;92m%s\\033[0;93m%s\\033[0;94m%s\\033[0;95m%s\\033[0;96m%s\\033[0;97m%s\n",ligneColorL, ligne, ligne, ligne, ligne, ligne, ligne, ligne, ligne);
	}

    ligneColorL[strlen(ligneColorL)-1] = ' ';
    sprintf(ligneC, "echo \'\n%s\n%s\'", ligneColorD, ligneColorL);
    system(ligneC);
}
