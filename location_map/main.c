#include <stdio.h>
#include <stdlib.h> //librerie standard con funzioni principali
#include <string.h> //libreria per la lettura delle stringhe
#include "function.h" //header delle funzioni create da noi

#define comando1 1
#define comando2 2
#define comando3 3
#define comando4 4  //i comandi sono stati definiti come variabili globali, perchè sicuramente non verrano cambiate, e non ci interessa che abbiano posizione in memoria
#define comando5 5
#define comando6 6
#define comando7 7

int main ()
{
    //Viene definita la varabile (matrice di char) e viene chiamata la funzione reading per convertire il file di testo nella mappa.
    char mappavera [righe_mappa][colonne_mappa];
    reading(mappavera); //chiamata alla funzione reading

    //inizializzazione variabili e strutture
    char direzione_scelta = 'a';
    posizione coordinate_matrice;

    coordinate_matrice.x = 3; //sto inizializzando la posizione di inizio del gioco
    coordinate_matrice.y = 5;

    raccoglibile inventario;
    inventario.chiave_1 = false;
    inventario.chiave_2 = false;
    inventario.chiave_3 = false;
    inventario.sedia = false;
    inventario.tavolo = false;
    int comando = 0;
    int chiave_inserita1 = 0;
    int chiave_inserita2 = 0;
    int chiave_inserita3 = 0;
    char scelta_porta;

    //Prima dell'inizio del gioco
    printf("benvenuto in S.Anna\n Questi sono i comandi che hai:\n1)go\n2)osserva\n3)raccogli\n4)inventario\n5)comandi\n6)mostra mappa\n7)esci\n");

    //Inizio del gioco (ciclo while)
    while(comando != 7 && mappavera[coordinate_matrice.y][coordinate_matrice.x] != 'w') // || gioco finito
    {
        fflush(stdin); //funzione che pulisce il buffer della scanf, è stato fatto per risolvere un bug per il quale allo scan di un carattere anziche un intero faceva partire un loop infinito di "cosa vuoi fare'"
        printf("Cosa vuoi fare (current command: %d)?\n", comando);
        scanf("%d", &comando);
        if (!(comando >= 1 && comando <= 7)) //controllo affinche se inserisco un comando non valido mi viene detto che il comando non è valido
        {
            printf("Comando non valido\n");
            continue; //cosi che mi viene chiesto di nuovo cosa voglio fare
        }

        switch(comando)
        {
            case comando1:
                printf("In quale direzione vuoi andare?\n");
                scanf("%s", &direzione_scelta);

                //enigma porta
                if ((mappavera[coordinate_matrice.y][coordinate_matrice.x] == '_') && ((direzione_scelta == 's') || (direzione_scelta == 'S')))
                {
                    printf("Hai bisogno di tre chiavi, per aprire questa porta\n");
                    if ((inventario.chiave_1 == true) && (inventario.chiave_2 == true) && (inventario.chiave_3 == true))
                    {
                        while (!(chiave_inserita1 == 2 && chiave_inserita2 == 1 && chiave_inserita3 == 3) && (scelta_porta != 'n'))
                        {
                            scelta_porta = 'a';
                            printf("Inserisci le chiavi nell'ordine corretto \ncome per esempio:\n4\n5\n6\ntocca a te ora\n");
                            scanf("%d%d%d", &chiave_inserita1, &chiave_inserita2, &chiave_inserita3);
                            if ((chiave_inserita1 > 3 || chiave_inserita1 < 1) || (chiave_inserita2 > 3 || chiave_inserita2 < 1) || (chiave_inserita3 > 3 || chiave_inserita3 < 1))
                            {
                                printf("Non hai inserito i valori esatti(sono accettate solo combinazioni di 1,2,3, riprova: \n");
                            }
                            else
                            {
                                while (scelta_porta != 's' && scelta_porta != 'n')
                                {
                                    if (chiave_inserita1 == 2 && chiave_inserita2 == 1  && chiave_inserita3 == 3)
                                    {
                                        scelta_porta = 's'; //appezzottamento
                                    }
                                    else
                                    {
                                        printf("La risposta non è corretta, vuoi rintentare(rispondi s/n)\n?");
                                        scanf("\n%c", &scelta_porta);
                                    }
                                }
                            }

                        }
                        if (scelta_porta == 'n') //se io esco dal while e rientro nel gioco, scelta porta e le variabili chiave inserita devono essere resettate
                        {
                            scelta_porta = 'a';
                            int chiave_inserita1 = 0;
                            int chiave_inserita2 = 0;
                            int chiave_inserita3 = 0;
                            break; //chiudo il comando, così che mi possa essere richiesto di nuobo
                        }
                        else
                        {
                            printf("HAI VINTO!");
                            go(mappavera, 's', &coordinate_matrice);
                            break;
                        }
                    }
                    else
                    {
                        printf("Non hai raccolto tutte le chiavi\n");
                    }
                }
                else
                {
                     //esecuzione del comando indipendentemente dalla posizione
                    system("cls"); //serve a pulire la console ogni bolta che viene chiamata la funzione go che ti fa muovere. Questa funzione scritta cosi funziona solo per windows
                    go(mappavera, direzione_scelta, &coordinate_matrice);
                    stampa_matrice(mappavera, &coordinate_matrice); //chiaramente adesso la matrice viene stampata con le coordinate aggiornate perchè go + stata chiamata prima
                    printf("la posizione attuale e' %c\n", mappavera[coordinate_matrice.y][coordinate_matrice.x]); //per motivi di debug
                }
                break;
            case comando2:
                osserva(mappavera, &coordinate_matrice);
                break;
            case comando3:
                //Enigma raccolta prima chiave
                if (mappavera[coordinate_matrice.y][coordinate_matrice.x] == 'e')
                {
                    if (inventario.secchio == false)
                    {
                        printf("Questa chiave e' incandescente, non puoi raccoglierla a mani nude\n");
                    }
                    else
                    {
                        raccogli(mappavera, &coordinate_matrice, &inventario);
                    }
                }
                //enigma raccolta seconda chiave
                else if (mappavera[coordinate_matrice.y][coordinate_matrice.x] == 'k')
                {
                    if (inventario.sedia == false)
                    {
                        printf("Questa chiave si trova troppo in alto, non riesci a raggiungerla\n");
                    }
                    else
                    {
                        raccogli(mappavera, &coordinate_matrice, &inventario);
                    }
                }
                //enigma raccolta terza chiave
                else if (mappavera[coordinate_matrice.y][coordinate_matrice.x] == 'y')
                {
                    if (inventario.vaso == false)
                    {
                        printf("Questa chiave si trova troppo in alto, non riesci a raggiungerla\n");
                    }
                    else
                    {
                        raccogli(mappavera, &coordinate_matrice, &inventario);
                    }
                }
                else
                {
                     raccogli(mappavera, &coordinate_matrice, &inventario);
                }
                break;
            case comando4:
                leggi_inventario(&inventario);
                break;
            case comando5:
                printf("Questi sono i comandi che hai:\n1)go\n2)osserva\n3)raccogli\n4)inventario\n5)comandi\n6)mostra mappa\n7)esci\n");
                break;
            case comando6:
                stampa_matrice(mappavera, &coordinate_matrice);
                break;
            case comando7:
                break;
        }
    }
    return 0;
}
