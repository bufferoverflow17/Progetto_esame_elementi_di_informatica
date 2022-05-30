#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED
#define righe_mappa 4
#define colonne_mappa 5
void reading();

typedef struct  {
    int x;
    int y;
}posizione;
void go (char direzione, posizione *prova);

/*typedef struct {
    int muro = 1;
    int oggetto2

}*/

void osserva (posizione *prova, int mappa[righe_mappa][colonne_mappa]);


#endif // FUNCTION_H_INCLUDED
