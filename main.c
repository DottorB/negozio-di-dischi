/*gestione automatizzata di un archivio di dischi musicali. La capienza massima è di 100 dischi
divisi tutti tramite titolo, nome, autore o gruppo a cui appartengono.
Ci sarà la possibilità di inserire dischi nuovi, visualizzare quelli presenti di
uno stesso autore o gruppo e cercare nell'archivio il disco più costoso.*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "header.h"


int main()
{

    int scelta_operazione;
    int indice=0;
    int indice_max=0;
    float max_costo;

    printf("Benvenuto nel negozio di dischi di Enrico Bucci \n");

    int disco_nuovo=6;//rappresenta i dischi presenti
    int n_codice=disco_nuovo+1;//rappresenta il codice (che parte da 1 e non da 0)
    int trovato,massimo; //rappresenta una variabile che userò nel noleggio e una per la classificazione del disco più costoso
    int continua=1; //rappresenta una variabile che permette di fare più operazioni

    while(continua){
    printf("Selezionare un'opzione \n");

    //tramite una serie di printf presento i comandi legati alle varie operazioni
    printf("-digitare 1 se si vuole inserire un nuovo disco all'archivio (aggiungi i tuoi gusti!)\n");
    printf("-digitare 2 se si vuole visualizzare tutti i dischi (cerca il disco che piu' ti piace!)\n");
    printf("-digitare 3 se si desidera prendere in prestito un disco(approfitta finche' e' ancora in negozio!)\n");
    printf("-digitare 4 se si desidera sapere il disco piu' costoso (scopri il disco piu' costoso che abbiamo!)\n");
    printf("-digitare 0 se non si desidera fare alcuna operazione \n");

    scanf("%d",&scelta_operazione);

    //pulisce il buffer, così da poter usare fgets nella fuzione aggiungi_disco
    getchar();
    //utilizzo uno switch per la selezione delle operazioni
    switch (scelta_operazione)
    {
        case 1: aggiungi_disco(&disco_nuovo, &n_codice);break;
        case 2: visualizza_dischi(&disco_nuovo);break;
        case 3: preleva_disco(trovato,&disco_nuovo);break;
        case 4: piu_costoso(&disco_nuovo,indice,&indice_max,&max_costo);break;
        default:printf("Operazione non valida. Riprova.\n");break;
    }


        //tramite printf presento il comando per poter coninuare o meno le operazioni
        printf("premi 1 se desideri fare un'altra operazione, premi 0 se desideri chiuere il programma \n");

        scanf("%d",&continua);

    if (continua==0) //se è uguale a 0 finisce il programma
    {
        printf("grazie per averci scelti arrivederci! \n");

    }
    }
}

