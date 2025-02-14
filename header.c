#include<stdio.h>
#include<string.h>
#include "header.h"


//inizializzo un array di struct di 100 dischi con 6 dischi iniziali contenenti tutte le informazioni
disco archivio[100] = {
    //nome, autore o band, costo di noleggio, codice, presenza
    {"I Want to Break Free", "Queen", 15.20, 1, 1},
    {"Back in Black", "ACDC", 14.40, 2, 1},
    {"Doomsday", "MF DOOM", 20.50, 3, 1},
    {"Whatever It Takes", "Imagine Dragons", 18.50, 4, 1},
    {"Borderline", "Tame Impala", 19.90, 5, 1},
    {"Don't Stop Me Now", "Queen", 20.00, 6, 1}
};


void aggiungi_disco(int *disco_nuovo, int *n_codice) {
    //controllo della quantità di dischi, se sono minori di 100, si può continuare
    if (*disco_nuovo < 100) {
        //inserimento titolo del disco
        printf("Inserisci il titolo del disco \n");
        fgets(archivio[*disco_nuovo].titolo, 50,stdin);
        archivio[*disco_nuovo].titolo[strcspn(archivio[*disco_nuovo].titolo, "\n")] = '\0';
        //inserimento autore o band
        printf("inserisci l'autore o la band del disco \n");
        fgets(archivio[*disco_nuovo].autore_band, 50, stdin);
        archivio[*disco_nuovo].autore_band[strcspn(archivio[*disco_nuovo].autore_band, "\n")] = '\0';
        //inserimento prezzo del noleggio
        printf("inserisci il prezzo del  disco \n");
        scanf("%f", &archivio[*disco_nuovo].costo_prestito);
        getchar();
        //chiamata alla funzione assegna codice, per associare al disco aggiunto un codice
        archivio[*disco_nuovo].disponibile = 1;
        assegna_codice(n_codice, disco_nuovo);
        (*disco_nuovo)++;
    } else //se i dischi sono 100 non si possono più aggiungere
    {
        //messaggio che avvisa l'utente che è stato superato il limite di dischi
        printf("il nostro archivio e' pieno! non e' possibile aggiungere ulteriori dischi \n");
    }
}

//assegna automaticamente il codice a un disco
void assegna_codice(int *n_codice, int *disco_nuovo) {
    archivio[*disco_nuovo].codice = *n_codice;
    //indica il codice del disco
    printf("il codice del disco e' %d \n", *n_codice);
    //aumenta ogni volta il valore numerico del codice
    (*n_codice)++;
} //permette la visualizzazione di tutti i dischi presenti nell'archivio
void visualizza_dischi(int *disco_nuovo) {
    //tramite due cicli annidati organizza i dischi per autore o band
    for (int i = 0; i < *disco_nuovo; i++) {
        for (int j = i + 1; j < *disco_nuovo; j++) {
            if (strcmp(archivio[i].autore_band, archivio[j].autore_band) > 0) {
                disco var_temp = archivio[i];
                archivio[i] = archivio[j];
                archivio[j] = var_temp;
            }
        }
    } //tramite altri due cicli annidati fa si che anche i codici siano sistemati
    for (int i = 0; i < *disco_nuovo; i++) {
        for (int j = i + 1; j < *disco_nuovo; j++) {
            if (archivio[i].codice > archivio[j].codice) {
                int var_temp = archivio[i].codice;
                archivio[i].codice = archivio[j].codice;
                archivio[j].codice = var_temp;
            }
        }
    }
    //con un ciclo for procedo all visualizzazione di tutti i dischi
    for (int i = 0; i < *disco_nuovo; i++) {
        printf("Titolo:%s \n", archivio[i].titolo);
        printf("Autore/Band:%s \n", archivio[i].autore_band);
        printf("Costo prestito:%.2f \n", archivio[i].costo_prestito);
        printf("Codice: %d \n", archivio[i].codice);
        printf("\n");
    }
}

//funzione che permette di "noleggiare" un disco se è presente
void preleva_disco(int trovato, int *disco_nuovo) {
    char nome_disco[50];

    printf("inserire il nome del disco da noleggiare \n");
    //tramite "fgets" si possono scrivere anche titoli di canzoni con più parole
    fgets(nome_disco, 50,stdin);
    //tramite "strcspn" fa si che il carattere "\n" venga sostituito da "\0" così che non venga visualizzato
    nome_disco[strcspn(nome_disco, "\n")] = '\0';

    trovato = 0;

    for (int i = 0; i < *disco_nuovo; i++) {
        //tramite strcmp si controlla se il disco scritto corrisponda a un disco presente nell'archivio
        if (strcmp(nome_disco, archivio[i].titolo) == 0) {
            trovato = 1;

            // se è disponibile viene noleggiato e la variabile della disponibilità viene azzerata (non è possibile noleggiarlo di nuovo)
            if (archivio[i].disponibile == 1) {
                printf("disco noleggiato con successo, goditi la tua musica preferita \n");

                archivio[i].disponibile = 0;
            } else {
                //se non c'è il disco desiderato, un messaggio di testo avviserà l'utente che non può noleggiarlo
                printf("ci dispiace, purtroppo il disco e' stato gia' noleggiato \n");
            }
            break;
        }
    }

    if (!trovato) // se il nome non è presente nell'archivio si cerca di nuovo
    {
        printf("disco non trovato, riprovi per favore \n");

        preleva_disco(trovato, disco_nuovo);
    }
}

//funzione che confronta tutti i dischi per trovare il più costoso tramite un approccio ricorsivo e incrementale
void piu_costoso(int *disco, int indice, int *indice_max, float *max_costo) {
    //esaminati tutti i dischi, presenta il messaggio con il disco più costoso
    if (indice == *disco) {
        printf("il disco con il costo maggiore e' %s ", archivio[*indice_max].titolo);

        printf("con il costo di %.2f \n", *max_costo);
        return;
    } //sostituisce il disco più costoso, se ne rivela un altro
    if (archivio[indice].costo_prestito > *max_costo) {
        //sostituisce l'indice
        *indice_max = indice;
        //sostituisce il costo
        *max_costo = archivio[indice].costo_prestito;
    }
    //tramite chiamata ricorsiva aumenta l'indice fino a quando non finiscono i confronti
    piu_costoso(disco, indice + 1, indice_max, max_costo);
}
