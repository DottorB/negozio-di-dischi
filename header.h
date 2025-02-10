void assegna_codice(int *n_codice,int *disco_nuovo);
void aggiungi_disco (int *disco_nuovo, int *n_codice);
void visualizza_dischi(int *disco_nuovo);
void preleva_disco (int trovato,int *disco_nuovo);
void piu_costoso (int *disco_nuovo,int indice,int * indice_max,float* max_costo);


//inizializzo una struct per gestire i dischi e le loro informazioni
typedef struct
{  //array di caratteri per i titoli
    char titolo[50];
    //array di caratteri per gli autori o le band
    char autore_band[50];
    //array di numeri per il costo del disco
    float costo_prestito;
    //array di numeri per l'assegnazione del codice
    int codice;
    //array di numeri che indica la disponbilità di un disco
    int disponibile;
} disco;

