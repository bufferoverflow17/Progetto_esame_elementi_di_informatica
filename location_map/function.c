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

void go (char direzione, posizione *prova)
{
    char nord = 'N' , nord2 = 'n';
    char sud = 'S' , sud2 = 's';
    char west = 'W' , west2 = 'w';
    char est = 'E' , est2 = 'e';

    if ((direzione == nord || direzione == nord2) && (prova->y != 0))
    {
         --prova->y;
        //printf("%d", prova->y);
    }
    else if ((direzione == sud || direzione == sud2) && (prova->y != righe_mappa-1) )
    {
        prova->y++;
    }
    else if ((direzione == west || direzione == west2) && (prova->x != 0))
    {
        --prova->x;
    }
    else if ((direzione == est || direzione == est2) && (prova->x != colonne_mappa-1))
    {
        prova->x++;
    }
    else
    {
        printf ("Non puoi proseguire in questa direzione, riprova \n");
    }
}


void osserva (int mappa [righe_mappa][colonne_mappa], posizione *prova)
{
    if (mappa[prova->y][prova->x] == 1)
    {
        printf("sei davanti a un muro");
    }
    if (mappa[prova->y][prova->x] == 7)
    {
        printf("Hai trovato piccone");
    }

}


void raccogli (int mappa [righe_mappa][colonne_mappa], posizione *prova, raccoglibile *example)
{

    if (mappa[prova->y][prova->x]== 2)
    {
        example->oggetto1 = true;
    }
    if (mappa[prova->y][prova->x]==7)
    {
        example->oggetto2 =true;
    }


}

void leggi_inventario( raccoglibile *example)
{
    if (example->oggetto1 == false)
    {
        printf("_\n");
    }
    else {
        printf("Hai un piccone\n");
     }

    if (example->oggetto2 == false)
    {
        printf("_\n");
    }
    else {
        printf("hai la chiave\n");}
}



