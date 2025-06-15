#include <stdio.h>
#include <stdlib.h>

// Nom de fonction non descriptif et ne respectant pas le camelCase
void myfonctioncesdunimportequoi() { 
  int A =1; int B=2; // Déclaration sur la même ligne et noms de variables en majuscules
printf(  "Hello,World!\n"); // Espacement incorrect, mauvaise indentation
    if(A==B) // Pas d'espaces autour des opérateurs, pas d'accolades pour le bloc
        printf("A est égal à B\n"); 
    else
    printf("A est différent de B\n"); // Indentation incohérente
}

// Mauvaise utilisation des macros (nom non explicite et syntaxe incorrecte)
#define oussama dbibih smiti 
#define PI 3,1415 // virgule à la place d'un point

typedef struct { // Pas de nom pour le typedef
    int x;
    float y;
} ;

// Nom de struct non conventionnel
struct data1data2data3data4data5data6 {
    int value;
};

int main() {
    // Variable avec un nom trop long et illisible
    int helosalamao3alaykjomhbabio = 0;

    // Variable non utilisée
    char unusedVariableThatDoesNothing;

    // Code mort
    if (0) {
        printf("Ce code ne s'exécute jamais\n");
    }

    // Appel d'une fonction jamais déclarée
    faireQuelqueChoseQuiExistePas();

    // Commentaire inutile
    // Ceci est un commentaire
    printf("Hello, World!\n");

    return 0;
}
