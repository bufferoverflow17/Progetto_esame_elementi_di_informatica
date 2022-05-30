#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

#define max_length 21
#define righe_mappa 4
#define colonne_mappa 5


//Funzione lettura file mappa e conversione in matrice di interi
void reading(int mappa[righe_mappa][colonne_mappa])
{
    //definizione variabili
    int i;
    int j;
    int celle_map[max_length];
    char *path_map;
    char line[max_length] = {0};

    //lettura file e conversione in stringa
    path_map = "map.txt";
    FILE *file = fopen(path_map, "r");
    fgets(line, max_length, file);

    //Conversione in array di interi
    for (i = 0; i < max_length -1; i++)
    {
        celle_map[i] = line[i] - '0';
        //printf("%d\n", celle_map[i]);

    }

    //Conversione in matrice di interi
    for (i = 0; i < righe_mappa ; i++ )
    {
        for (j = 0; j < colonne_mappa; j++)
        {
            mappa[i][j] = celle_map[j];
            int incremento = colonne_mappa * (i+1);
            celle_map[j] = celle_map[j + incremento];
        }
    }

    //stampa matrice
    for (i = 0; i < righe_mappa; i++)
    {
        for (j = 0; j < colonne_mappa; j++)
        {
            printf("%5d\t", mappa[i][j]);
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
    if (direzione == nord || direzione == nord2 )
    {
        --prova->y;
        //printf("%d", prova->y);
    }
    if (direzione == sud || direzione == sud2 )
    {
        prova->y++;
    }
    if (direzione == est || direzione == est2)
    {
        --prova->x;
    }
    if (direzione == west || direzione == west2)
    {
        prova->x++;
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
