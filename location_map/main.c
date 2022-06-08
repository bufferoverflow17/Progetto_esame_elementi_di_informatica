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
    inventario.sedia = false;
    inventario.tavolo = false;
    int comando = 0;
    int chiave_inserita1 = 0;
    int chiave_inserita2 = 0;
    int chiave_inserita3 = 0;
    char scelta_porta;

    //Prima dell'inizio del gioco
    printf("benvenuto in S.Anna\n Questi sono i comandi che hai:\n1)go\n2)osserva\n3)raccogli\n4)inventario\n5)comandi\n6)mostra mappa\n7)esci\n");
    //printf("%d", coordinate_matrice.y);
    //printf("la posizione attuale e' %d\n", mappavera[coordinate_matrice.y][coordinate_matrice.x]);
    //go(esempio, &coordinate_matrice);

    //Inizio del gioco (ciclo while)
    while(comando != 7 && mappavera[coordinate_matrice.y][coordinate_matrice.x] != 'w') // || gioco finito
    {
        printf("Cosa vuoi fare?\n");
        scanf("%d", &comando);
        switch(comando)
        {
            case comando1:
                //enigma porta
                if (mappavera[coordinate_matrice.y][coordinate_matrice.x] == '_')
                {
                    printf("Hai bisogno di tre chiavi, per aprire questa porta. Inseriscile nell'ordine giusto\n");
                    if ((inventario.chiave_1 == true) && (inventario.chiave_2 == true) && (inventario.chiave_3 == true))
                    {
                        while (!(chiave_inserita1 == 2 && chiave_inserita2 == 1 && chiave_inserita3 == 3) && (scelta_porta != 'n'))
                        {
                            printf("Inserisci le chiavi nell'ordine corretto(es.456)\n");
                            scanf("\n%d%d%d", &chiave_inserita1, &chiave_inserita2, &chiave_inserita3);
                            while (scelta_porta != 's' && scelta_porta != 'n')
                            {
                                printf("La risposta non � corretta, vuoi rintentare(rispondi s/n)\n?");
                                scanf("\n%c", &scelta_porta);
                            }
                        }
                        if (scelta_porta == 'n')
                        {
                            break;
                        }
                        else
                        {
                            go(mappavera, direzione_scelta, &coordinate_matrice);
                        }
                    }
                    else
                    {
                        printf("Non hai raccolto tutte le chiavi\n");
                    }
                }
                //esecuzione del comando indipendentemente dalla posizione
                printf("In quale direzione vuoi andare?");
                scanf("%s", &direzione_scelta);
                system("cls"); //serve a pulire la console ogni bolta che viene chiamata la funzione go che ti fa muovere. Questa funzione scritta cosi funziona solo per windows
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
                        printf("Questa chiave � incandescente, non puoi raccoglierla a mani nude");
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
