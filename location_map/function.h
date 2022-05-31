#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED
#define righe_mappa 4
#define colonne_mappa 5
#include <stdbool.h>
#include <stdio.h>
void reading();

typedef struct  {
    int x;
    int y;
}posizione;
void go (char direzione, posizione *prova);

typedef enum { F, T } boolean;

int inventario()
{
    boolean piccone, chiave;
    piccone = F;

    if (piccone == F) {
        printf("non hai piccone\n");
    }
    else {
        printf("hai piccone\n");
    }
    chiave = 2;
    if (chiave == F) {
        printf("non hai chiave\n");
    }
    else {
        printf("hai la chiave\n");
    }
}




#endif // FUNCTION_H_INCLUDED
