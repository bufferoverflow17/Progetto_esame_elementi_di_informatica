#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"
#define max_length 10
#define comando1 1
#define comando2 2
int main ()
{
    //char esempio = 'n';
    char direzione_scelta = 'a'
    ;
    int mappavera [righe_mappa][colonne_mappa];
    reading(mappavera);
    posizione coordinate_matrice;
    coordinate_matrice.x = 3;
    coordinate_matrice.y = 3;
    int comando = 0;
    printf("benvenuto in S.Anna\n Questi sono i comandi che hai:\n 1)go\n2)esci\n");
    //printf("%d", coordinate_matrice.y);
    //printf("la posizione attuale e' %d\n", mappavera[coordinate_matrice.y][coordinate_matrice.x]);
    //go(esempio, &coordinate_matrice);
    printf("Cosa vuoi fare?\n");
    while(comando != 2) // || gioco finito
    {
        scanf("%d", &comando);
        switch(comando)
        {
            case comando1:
                printf("In quale direzione vuoi andare?");
                scanf("%s", &direzione_scelta);
                go(direzione_scelta, &coordinate_matrice);
                printf("la posizione attuale e' %d\n", mappavera[coordinate_matrice.y][coordinate_matrice.x]);
                break;
            case comando2:
                return -1;
                break;
        }
    }
    return 0;
}
