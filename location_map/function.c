#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "function.h"

#define max_length 134
#define righe_mappa 7
#define colonne_mappa 19



//Funzione lettura file mappa e conversione in matrice di interi
void reading(char mappa[righe_mappa][colonne_mappa])
{
    //definizione variabili
    int i;
    int j;
    //char celle_map[max_length];
    char *path_map;
    char line[max_length] = {0};

    //lettura file e conversione in stringa
    path_map = "map.txt";
    FILE *file = fopen(path_map, "r");
    fgets(line, max_length, file);

    //Conversione in array di interi
    /*for (i = 0; i < max_length -1; i++)
    {
        celle_map[i] = line[i] - '0';
        //printf("%d\n", celle_map[i]);

    }*/

    //Conversione in matrice di interi
    for (i = 0; i < righe_mappa ; i++ )
    {
        for (j = 0; j < colonne_mappa; j++)
        {
            mappa[i][j] = line[j];
            int incremento = colonne_mappa * (i+1);
            line[j] = line[j + incremento];
        }
    }

    //stampa matrice
    for (i = 0; i < righe_mappa; i++)
    {
        for (j = 0; j < colonne_mappa; j++)
        {
            printf("%c ", mappa[i][j]);
        }
        printf("\n");
    }
}

void go (char mappa[righe_mappa][colonne_mappa], char direzione, posizione *prova)
{
    char nord = 'N' , nord2 = 'n';
    char sud = 'S' , sud2 = 's';
    char west = 'W' , west2 = 'w';
    char est = 'E' , est2 = 'e';

    if ((direzione == nord || direzione == nord2))
    {
         if (mappa[prova->x][prova->y -1] != 'X')
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
        if  (mappa[prova->x][prova->y ] != 'X')
        {
           prova->y++;
        }
        else if ( mappa[prova->x][prova->y !=5] != ' ')
        {
           printf ("Non puoi proseguire in questa direzione\n");
        }
        else
        {
            printf ("Davanti a te c'e' un muro, procedi in un altra direzione\n");
        }
    }
    else if ((direzione == west || direzione == west2) )
    {
        if (mappa[prova->x -1][prova->y] != 'X')
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
        if (mappa[prova->x ][prova->y] != 'X')
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
    if (mappa[prova->x][prova->y] == '#')
    {
        printf("sei davanti a un letto\n");
    }
    if (mappa[prova->y][prova->x] == 'k')
    {
        printf("Hai trovato una chiave\n");
    }
    if(mappa[prova->y][prova->x]== 'e')
    {
        printf ("hai trovato la seconda chiave\n");
    }
    if(mappa[prova->y][prova->x]=='y')
    {
        printf("hai trovato l'ultima chiave\n");
    }
    if(mappa[prova->y][prova->x]=='U')
    {
        printf("hai trovato un secchio\n");
    }
    if (mappa[prova->y][prova->x]=='h')
    {
        printf ("hai trovato una sedia\n");
    }
    if(mappa[prova->y][prova->x]=='O')
    {
        printf("stai osservando un tavolo\n");
    }
    if(mappa[prova->y][prova->x]=='V')
    {
        printf("hai trovato un vaso\n");
    }
}


void raccogli (char mappa [righe_mappa][colonne_mappa], posizione *prova, raccoglibile *example)
{

    if (mappa[prova->y][prova->x]== 'k')
    {
        example->chiave_1 =true;
    }
    if (mappa[prova->y][prova->x]=='e')
    {
        example->chiave_2=true;
    }
    if (mappa[prova->y][prova->x]=='y')
    {
       example->chiave_3=true;
    }
    if (mappa[prova->y][prova->x]=='V')
    {
        example->vaso=true;
    }
    if(mappa[prova->y][prova->x]=='h')
    {
        example->sedia=true;
    }


}

void leggi_inventario( raccoglibile *example)
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
        printf("hai un secchio");
    }
    if(example->vaso == false)
    {
      printf("_\n");
    }
    else
    {
        printf("hai un vaso\n");
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




