#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED
#define righe_mappa 4
#define colonne_mappa 5

#include <stdio.h>
void reading();

typedef struct  {
    int x;
    int y;
}posizione;

void go (char direzione, posizione *prova);

void osserva (int mappa [righe_mappa][colonne_mappa], posizione *prova);

typedef enum { F, T } boolean;

int inventario()
{
    boolean piccone, chiave;
    piccone = F;

    if (piccone == F) {
        printf("non hai questo oggetto\n");
    }
    else {
        printf("hai un piccone\n");
    }
    chiave = 2;
    if (chiave == F) {
        printf("non hai questo oggetto\n");
    }
    else {
        printf("hai la chiave\n");
    }
}



#endif // FUNCTION_H_INCLUDED
