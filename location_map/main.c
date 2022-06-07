#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "function.h"
#define comando1 1
#define comando2 2
#define comando3 3
#define comando4 4
#define comando5 5
#define comando6 6
#define comando7 7
int main ()
{
    //Viene definita la varabile (matrice di char) e viene chiamata la funzione reading per convertire il file di testo nella mappa.
    char mappavera [righe_mappa][colonne_mappa];
    reading(mappavera);

    //inizializzazione variabili e strutture
    char direzione_scelta = 'a';
    posizione coordinate_matrice;
    coordinate_matrice.x = 3;
    coordinate_matrice.y = 5;
    raccoglibile inventario;
    inventario.chiave_1 = false;
    inventario.chiave_2 = false;
    inventario.chiave_3 = false;
    inventario.secchio = false;
    inventario.vaso = false;
    int comando = 0;

    //Prima dell'inizio del gioco
    printf("benvenuto in S.Anna\n Questi sono i comandi che hai:\n1)go\n2)osserva\n3)raccogli\n4)inventario\n5)comandi\n6)mostra mappa\n7)esci\n");
    //printf("%d", coordinate_matrice.y);
    //printf("la posizione attuale e' %d\n", mappavera[coordinate_matrice.y][coordinate_matrice.x]);
    //go(esempio, &coordinate_matrice);

    //Inizio del gioco (ciclo while)
    while(comando != 7) // || gioco finito
    {
        //system("cls");
        //stampa_matrice(mappavera, &coordinate_matrice);
        printf("Cosa vuoi fare?\n");
        scanf("%d", &comando);
        switch(comando)
        {
            case comando1:
                printf("In quale direzione vuoi andare?");
                scanf("%s", &direzione_scelta);
                system("cls");
                go(mappavera, direzione_scelta, &coordinate_matrice);
                stampa_matrice(mappavera, &coordinate_matrice);
                printf("la posizione attuale e' %c\n", mappavera[coordinate_matrice.y][coordinate_matrice.x]);
                break;
            case comando2:
                osserva(mappavera, &coordinate_matrice);
                break;
            case comando3:
                //Enigma raccolta prima chiave
                if (mappavera[coordinate_matrice.y][coordinate_matrice.x] == 'e')
                {
                    if (inventario.secchio == false)
                    {
                        printf("Questa chiave è incandescente, non puoi raccoglierla a mani nude");
                    }
                    else
                    {
                        raccogli(mappavera, &coordinate_matrice, &inventario);
                    }
                }
                //enigma raccolta seconda chiave
                if (mappavera[coordinate_matrice.y][coordinate_matrice.x] == 'k')
                {
                    if (inventario.sedia == false)
                    {
                        printf("Questa chiave si trova troppo in alto, non riesci a raggiungerla");
                    }
                    else
                    {
                        raccogli(mappavera, &coordinate_matrice, &inventario);
                    }
                }
                //enigma raccolta terza chiave
                if (mappavera[coordinate_matrice.y][coordinate_matrice.x] == 'y')
                {
                    if (inventario.vaso == false)
                    {
                        printf("Questa chiave si trova troppo in alto, non riesci a raggiungerla");
                    }
                    else
                    {
                        raccogli(mappavera, &coordinate_matrice, &inventario);
                    }
                }
                raccogli(mappavera, &coordinate_matrice, &inventario);
                break;
            case comando4:
                leggi_inventario(&inventario);
                break;
            case comando5:
                printf("Questi sono i comandi che hai:\n1)go\n2)osserva\n3)raccogli\n4)inventario\n5)comandi\n6)mostra mappa\n7)esci\n");
                break;
            case comando6:
                stampa_matrice(mappavera, &coordinate_matrice);
                break;
            case comando7:
                break;
        }
    }
    return 0;
}
