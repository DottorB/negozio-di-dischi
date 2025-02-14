/* gestione automatizzata di un archivio di dischi musicali. La capienza massima è di 100 dischi
divisi tutti in titolo, nome, autore o gruppo a cui appartengono.
Ci sarà la possibilità di inserire dischi nuovi, visualizzare quelli presenti organizzati in base
allo stesso autore o gruppo e cercare nell'archivio il disco più costoso.*/
#include<stdio.h>
#include "header.h"


int main() {
    int scelta_operazione;
    int indice = 0;
    int indice_max = 0;
    float max_costo;

    printf("Benvenuto nel negozio di dischi di Enrico Bucci \n");

    int disco = 6; //variabile che indica i dischi già presenti
    int n_codice = disco + 1; //variabile che indica il codice di ciascun disco
    int trovato;
    int continua = 1; //variabile che permette di fare 2 o più operazioni prima della chiusura del programma
    //gestisce la continuità del programma
    while (continua) {
        printf("Selezionare un'opzione \n");

        //tramite una serie di printf si presentano i comandi legati alle varie operazioni
        printf("-digitare 1 se si vuole inserire un nuovo disco all'archivio (aggiungi i tuoi gusti!)\n");
        printf("-digitare 2 se si vuole visualizzare tutti i dischi (cerca il disco che piu' ti piace!)\n");
        printf("-digitare 3 se si desidera prendere in prestito un disco(approfitta finche' e' ancora in negozio!)\n");
        printf("-digitare 4 se si desidera sapere il disco piu' costoso (scopri il disco piu' costoso che abbiamo!)\n");
        printf("-digitare 0 se non si desidera fare alcuna operazione \n");

        //con scanf si registra la risposta dell'utente
        scanf("%d", &scelta_operazione);

        //pulisce il buffer, così da poter usare "fgets" nella funzione aggiungi_disco
        getchar();
        //utilizzo uno switch per la selezione dell'operazione desiderata
        switch (scelta_operazione) {
            case 0: printf("grazie per averci scelti arrivederci! \n"); //chiude il programma
                return 0;
            case 1: aggiungi_disco(&disco, &n_codice);
                break;
            case 2: visualizza_dischi(&disco);
                break;
            case 3: preleva_disco(trovato, &disco);
                break;
            case 4: piu_costoso(&disco, indice, &indice_max, &max_costo);
                break;
            //messaggio di errore se viene scritto un numero diverso da quelli indicati
            default: printf("Operazione non valida. Riprova.\n");
                break;
        }


        //messaggio che pone all'utente la possibilità di continuare o meno l'esecuzione del programma
        printf("premi 1 se desideri fare un'altra operazione, premi 0 se desideri chiudere il programma \n");

        scanf("%d", &continua);

        if (continua == 0) //se si imposta la variabile uguale a 0 finisce il programma
        {
            printf("grazie per averci scelti arrivederci! \n"); //messaggio di chiusura del programma
        }
    }
}

