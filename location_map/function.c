#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "function.h"

#define max_length 134 //rappresenta al numero di caratteri +1  del file map.txt
#define righe_mappa 7
#define colonne_mappa 19



//Funzione lettura file mappa e conversione in matrice di caratteri
void reading(char mappa[righe_mappa][colonne_mappa])
{
    //definizione variabili
    int i;
    int j;
    //char celle_map[max_length];
    char *path_map;  //definizione di un puntatore a una variabile pathmap che attualmente non ha ancora nessun valore
    char line[max_length] = {0};  //definizione di una stringa( vettore di char) con dimensione max length e inizializzata a 0.

    //lettura file e conversione in stringa
    path_map = "map.txt"; //deve il valore map.txt
    FILE *file = fopen(path_map, "r"); //File * file è una variabile con puntatore a cui assegno il valore di lettura, del file che ottengo attraverso la funzione fopen. "r" vuol dire che deve soltanto leggere
    fgets(line, max_length, file); //Mi restituisce il file che ha letto come un vettore di char (line).

    //Conversione in array di interi
    /*for (i = 0; i < max_length -1; i++)
    {
        celle_map[i] = line[i] - '0';
        //printf("%d\n", celle_map[i]);

    }*/

    //Conversione in matrice di caratteri
    for (i = 0; i < righe_mappa ; i++ )  //
    {
        for (j = 0; j < colonne_mappa; j++)
        {
            mappa[i][j] = line[j];
            int incremento = colonne_mappa * (i+1); //questa parte di codice fa si che ad gni ciclo di j, la j corrispondente deve essere aumentata di un crto incremento che per i = 0, è proprio il numero di colonne, ma che all'aumentare del numero di righe (i) deve aumentare esso stesso. La ragione di questo accorgimento è che altrimenti "mappa" avrebbe tutte le righe uguali alla prima. Perche le j sarebbero sempre le stesse.
            line[j] = line[j + incremento];
        }
    }

    //stampa matrice
    /*for (i = 0; i < righe_mappa; i++)
    {
        for (j = 0; j < colonne_mappa; j++)
        {
            printf("%c ", mappa[i][j]);
        }
        printf("\n");
    }*/
}


//questa funzione non fa altro che stampare la matrice che è definita dalla funzione reading
void stampa_matrice (char mappa [righe_mappa][colonne_mappa], posizione *prova)
{
    int i, j;
    for (i = 0; i < righe_mappa; i++)
    {
        for (j = 0; j < colonne_mappa; j++)
        {
            if (i == prova->y && j == prova->x) //questa parte di codice mi permette di stampare la posizione attuale del personaggio
            {
                printf("%s", "* ");  //we live in an asteriscocentric world!
            }
            else
            {
               printf("%c ", mappa[i][j]);
            }
        }
        printf("\n");
    }
}

void go (char mappa[righe_mappa][colonne_mappa], char direzione, posizione *prova)
{
    char nord = 'N' , nord2 = 'n';  //definizione dei caratteri che devono essere accettati dalla funzione
    char sud = 'S' , sud2 = 's';
    char west = 'W' , west2 = 'w';
    char est = 'E' , est2 = 'e';

    if ((direzione == nord || direzione == nord2))
    {
         if (mappa[prova->y -1][prova->x ] != 'X') //questo fa parte del controllo, semplicemente fimchè la mappa ha valore diverso da X, mi fa muovere(decrementa la posizione)
         {
             --prova->y;
         }
         else
         {
             printf("Davanti a te c'e' un muro, procedi in un altra direzione\n");
         }
    }
    else if ((direzione == sud || direzione == sud2) )
    {
        if  ((mappa[prova->y +1][prova->x] != 'X') && ( mappa[prova->y +1][prova->x] != '/'))
        {
           prova->y++;
        }
        else
        {
            printf ("Davanti a te c'e' un muro, procedi in un altra direzione\n");
        }
    }
    else if ((direzione == west || direzione == west2) )
    {
        if (mappa[prova->y ][prova->x -1] != 'X')
        {
            --prova->x;
        }
        else
        {
            printf ("Davanti a te c'e' un muro, procedi in un altra direzione\n");
        }

    }
    else if ((direzione == est || direzione == est2) )
    {
        if (mappa[prova->y ][prova->x +1] != 'X')
       {
          prova->x++;
       }
       else
        {
            printf ("Davanti a te c'e' un muro, procedi in un altra direzione\n");
        }
    }

    else
    {
        printf ("Non puoi proseguire in questa direzione, riprova \n");
    }
}


void osserva (char mappa [righe_mappa][colonne_mappa], posizione *prova)
{
    if (mappa[prova->y][prova->x] == '#') //Quando la mappa ha un certo valore, printa una determinata stringa (riferita all'oggetto corrispondente)
    {
        printf("sei davanti a un letto\n");
    }
    else if (mappa[prova->y][prova->x] == 'k')
    {
        printf("Hai trovato la seconda chiave\n");
    }
    else if (mappa[prova->y][prova->x] == 'e')
    {
        printf ("hai trovato la prima chiave\n");
    }
    else if (mappa[prova->y][prova->x] == 'y')
    {
        printf("hai trovato una chiave, ma è chiusa in una teca\n");
    }
    else if (mappa[prova->y][prova->x] =='U')
    {
        printf("hai trovato un secchio d' acqua\n");
    }
    else if (mappa[prova->y][prova->x] == 'h')
    {
        printf ("hai trovato una sedia\n");
    }
    else if(mappa[prova->y][prova->x] == 'O')
    {
        printf("stai osservando un tavolo\n");
    }
    else if (mappa[prova->y][prova->x] == 'V')
    {
        printf("hai trovato un vaso...\nsembra esserci una piccola chiave al suo interno\n");
    }
    else if (mappa[prova->y][prova->x] == '.')
    {
        printf ("sei sul pavimento\n");
    }
}


void raccogli (char mappa [righe_mappa][colonne_mappa], posizione *prova, raccoglibile *example)
{
    if ((mappa[prova->y][prova->x] == 'U') && (example->secchio == false)) //controllo affinchè un oggetto già raccolto non sia rraccoglibile di nuovo
    {
        example->secchio = true; //ogni oggetto preso diventa vero nella struttura raccoglibile
        printf("Hai raccolto il secchio\n");
    }
    else if ((mappa[prova->y][prova->x] == 'e') && (example->chiave_1 == false))
    {
        example->chiave_1 = true;
        printf("hai raccolto la prima chiave\n");
    }
    else if ((mappa[prova->y][prova->x] == 'k') &&  (example->chiave_2 == false))
    {
        example->chiave_2 = true;
        printf("Hai raccolto la seconda chiave\n");
    }
    else if ((mappa[prova->y][prova->x] =='y') &&  (example->chiave_3 == false))
    {
       example->chiave_3 = true;
       printf("Hai aperto la teca e hai raccolto la terza chiave\n");
    }
    else if ((mappa[prova->y][prova->x] == 'V') &&  (example->vaso == false))
    {
        example->vaso = true;
        printf("Hai raccolto la piccola chiave al suo interno\n");
    }
    else if ( (mappa[prova->y][prova->x] == 'h') && (example->sedia == false) )
    {
        example->sedia = true;
        printf("Hai raccolto la sedia\n");
    }
    else if ((mappa[prova->y][prova->x] == 'O') || (mappa[prova->y][prova->x] == '.') || (mappa[prova->y][prova->x] == '#'))
    {
        printf("Non puoi raccogliere questo oggetto\n");
    }
    else
    {
        printf ("Hai gia raccolto la questo oggetto\n");
    }


}

void leggi_inventario( raccoglibile *example) //ci sono una serie di if che fa si che se un oggetto è falso nell'inventario non compaia altrimenti si.
{
    if (example->chiave_1 == false)
    {
        printf("_\n");
    }
    else
    {
        printf("Hai la prima chiave\n");
    }

    if (example->chiave_2 == false)
    {
        printf("_\n");
    }
    else
    {
        printf("hai la seconda chiave\n");
    }

    if (example->chiave_3 == false)
    {
        printf ("_\n");
    }
    else
    {
        printf("hai la terza chiave\n");
    }

    if (example->secchio == false)
    {
        printf("_\n");
    }
    else
    {
        printf("hai un secchio\n");
    }

    if(example->vaso == false)
    {
      printf("_\n");
    }
    else
    {
        printf("hai una piccola chiave\n");
    }

    if(example->sedia == false)
    {
        printf("_\n");
    }
    else
    {
        printf("hai una sedia\n");
    }
}




