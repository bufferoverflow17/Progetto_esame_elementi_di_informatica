#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED
#define righe_mappa 4
#define colonne_mappa 5
#include <stdbool.h>
void reading();

typedef struct  {
    int x;
    int y;
}posizione;

void go (char direzione, posizione *prova);

void osserva (int mappa [righe_mappa][colonne_mappa], posizione *prova);

typedef struct  {
    bool oggetto1;
    bool oggetto2;
}raccoglibile;


#endif // FUNCTION_H_INCLUDED
