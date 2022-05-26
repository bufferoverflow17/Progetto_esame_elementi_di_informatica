#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"
#define max_length 10

int main ()
{
    char esempio = 'n';
    int mappavera [righe_mappa][colonne_mappa];
    reading(mappavera);
    posizione coordinate_matrice;
    coordinate_matrice.x = 3;
    coordinate_matrice.y = 3;
    //printf("%d", coordinate_matrice.y);
    printf("la posizione attuale e' %d\n", mappavera[coordinate_matrice.y][coordinate_matrice.x]);
    go(esempio, &coordinate_matrice);
    printf("la posizione attuale e' %d\n", mappavera[coordinate_matrice.y][coordinate_matrice.x]);
    return 0;
}
