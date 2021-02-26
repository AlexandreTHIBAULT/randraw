#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>

void write(FILE * f);

void main(){
    FILE * f;
    int nbPattern = 5;
    int i;

    char * path = (char *) malloc(10000);
    char * paternPath = getenv("PATERN_PATH");

    srand(time(NULL));
    i = rand()%nbPattern;

    switch(i){
    case 0:
    	sprintf(path, "%s/fish.txt", paternPath);
        break;
    case 1:
    	sprintf(path, "%s/arrows.txt", paternPath);
        break;
    case 2:
    	sprintf(path, "%s/heart.txt", paternPath);
        break;
    case 3:
    	sprintf(path, "%s/hi.txt", paternPath);
        break;
    case 4:
    	sprintf(path, "%s/star.txt", paternPath);
        break;
    
    default:
    
        break;
    }
    
    f = fopen(path, "r");
    write(f);
    free(path);
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

    free(ligne);
    free(ligneColorD);
    free(ligneColorL);
    free(ligneC);
}
