#include <stdio.h>

FILE *fopen(const char *filename, const char *mode);
// *mode = "w" -> write ; "a" -> append ; "r" -> read ; "W+" -> write + read ; "r+" -> read + write ; "a+" -> append + read ;

int main(){
    File *f;
    f = fopen("nomFichier.txt", "r");
    
    if(f==NULL){
        printf("Erreur lors de l'ouverture d'un fichier");
        exit(1);
    }

    fclose(f);

    return 0;
}

void rien(){
    printf("rien");
}