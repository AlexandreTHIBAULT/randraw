#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>
#include <dirent.h> 

void write(FILE * f);

void main(){
    DIR *d;
    struct dirent *dir;
    FILE * f;
    int nbPattern = 0;
    int i;
    char * path = (char *) malloc(10000);
    char * paternPath = getenv("PATERN_PATH");

    d = opendir(paternPath);
    if(d==NULL){
        printf("PATERN_PATH not defined");
        return;
    }

    while ((dir = readdir(d)) != NULL) {
        nbPattern++;
        //printf("%s\n", dir->d_name);
    }
    nbPattern -= 2;

    //printf("%d\n", nbPattern);

    srand(time(NULL));
    i = rand()%nbPattern;

    d = opendir(paternPath);
    while ((dir = readdir(d)) != NULL) {
    
        if(strcmp(dir->d_name, ".") && strcmp(dir->d_name, "..")){
            if(!i){
                //printf("%s\n", dir->d_name);
                sprintf(path, "%s/%s", paternPath, dir->d_name);
                f = fopen(path, "r");
                //printf("%s\n", path);
                write(f);
                free(path);
                return;
            }
            i--;
        }
        //printf("%d\n", i);
    }
    
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
