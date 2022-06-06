#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED
#define max_length 134
#define righe_mappa 7
#define colonne_mappa 19
#include <stdbool.h>
void reading();

typedef struct  {
    int x;
    int y;
}posizione;

void go (char mappa[righe_mappa][colonne_mappa], char direzione, posizione *prova);

void osserva (char mappa [righe_mappa][colonne_mappa], posizione *prova);



typedef struct  {
    bool chiave_1;
    bool chiave_2;
    bool chiave_3;
    bool secchio;
    bool sedia;
    bool tavolo;
    bool vaso;
}raccoglibile;
void raccogli (char mappa [righe_mappa][colonne_mappa], posizione *prova, raccoglibile *example);


void leggi_inventario( raccoglibile *example);


#endif // FUNCTION_H_INCLUDED
