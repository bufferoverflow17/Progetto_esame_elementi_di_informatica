#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"
#define max_length 10

typedef struct
{
    int x;
    int y;
}posizione;

int main ()
{
    char prova = {"n"};
    int mappavera [righe_mappa][colonne_mappa];
    reading(mappavera);
    posizione coordinate_matrice = {3, 3};
    printf("la posizione attuale e' %d", mappavera[coordinate_matrice.x][coordinate_matrice.y]);
    go(prova, mappavera, coordinate_matrice.x, coordinate_matrice.y);
    printf("la posizione attuale e' %d", mappavera[coordinate_matrice.x][coordinate_matrice.y]);
    return 0;
}
