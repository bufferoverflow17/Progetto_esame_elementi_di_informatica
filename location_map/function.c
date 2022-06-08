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
    /*for (i = 0; i < righe_mappa; i++)
    {
        for (j = 0; j < colonne_mappa; j++)
        {
            printf("%c ", mappa[i][j]);
        }
        printf("\n");
    }*/
}

void stampa_matrice (char mappa [righe_mappa][colonne_mappa], posizione *prova)
{
    int i, j;
    for (i = 0; i < righe_mappa; i++)
    {
        for (j = 0; j < colonne_mappa; j++)
        {
            if (i == prova->y && j == prova->x)
            {
                printf("%s", "* ");
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
    char nord = 'N' , nord2 = 'n';
    char sud = 'S' , sud2 = 's';
    char west = 'W' , west2 = 'w';
    char est = 'E' , est2 = 'e';

    if ((direzione == nord || direzione == nord2))
    {
         if (mappa[prova->y -1][prova->x ] != 'X')
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
        if  ((mappa[prova->y +1][prova->x] != 'X') && ( mappa[prova->y +1][prova->x] != ' '))
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
    if (mappa[prova->y][prova->x] == '#')
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
        printf("hai trovato la terza chiave\n");
    }
    else if (mappa[prova->y][prova->x] =='U')
    {
        printf("hai trovato un secchio\n");
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
        printf("hai trovato un vaso\n");
    }
    else if (mappa[prova->y][prova->x] == '.')
    {
        printf ("sei sul pavimento\n");
    }
}


void raccogli (char mappa [righe_mappa][colonne_mappa], posizione *prova, raccoglibile *example)
{

    if ((mappa[prova->y][prova->x] == 'e') && (example->chiave_1 == false))
    {
        example->chiave_1 = true;
    }
    else if ((mappa[prova->y][prova->x] == 'k') &&  (example->chiave_2 == false))
    {
        example->chiave_2 = true;
    }
    else if ((mappa[prova->y][prova->x] =='y') &&  (example->chiave_3 == false))
    {
       example->chiave_3 = true;
    }
    else if ((mappa[prova->y][prova->x] == 'V') &&  (example->vaso == false))
    {
        example->vaso = true;
    }
    else if ( (mappa[prova->y][prova->x] == 'h') && (example->sedia == false) )
    {
        example->sedia = true;
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




