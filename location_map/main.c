#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"
#define max_length 10
#define comando1 1
#define comando2 2
#define comando3 3
#define comando4 4
#define comando5 5
int main ()
{
    //char esempio = 'n';
    char direzione_scelta = 'a';
    int mappavera [righe_mappa][colonne_mappa];
    reading(mappavera);
    posizione coordinate_matrice;
    coordinate_matrice.x = 3;
    coordinate_matrice.y = 3;
    raccoglibile inventario;
    inventario.oggetto1 = false;
    inventario.oggetto2 = false;
    int comando = 0;
    printf("benvenuto in S.Anna\n Questi sono i comandi che hai:\n 1)go\n2)osserva\n3)raccogli\n4)inventario\n5)esci\n");
    //printf("%d", coordinate_matrice.y);
    //printf("la posizione attuale e' %d\n", mappavera[coordinate_matrice.y][coordinate_matrice.x]);
    //go(esempio, &coordinate_matrice);
    while(comando != 5) // || gioco finito
    {
        printf("Cosa vuoi fare?\n");
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
                osserva(mappavera, &coordinate_matrice);
                break;
            case comando3:
                raccogli(mappavera, &coordinate_matrice, &inventario);
                break;
            case comando4:
                leggi_inventario(&inventario);
                break;
            case comando5:
                break;

        }
    }
    return 0;
}
