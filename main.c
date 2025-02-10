/*gestione automatizzata di un archivio di dischi musicali. La capienza massima è di 100 dischi
divisi tutti tramite titolo, nome, autore o gruppo a cui appartengono.
Ci sarà la possibilità di inserire dischi nuovi, visualizzare quelli presenti di
uno stesso autore o gruppo e cercare nell'archivio il disco più costoso.*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

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
//inizializzo l'array di 100 dischi con 6 dischi iniziali contenenti tutte le informazioni
disco archivio[100]={
                    {"I Want to Break Free", "Queen",15.20,1,1},
                    {"Back in Black","ACDC",14.40,2,1},
                    {"Doomsday","MF DOOM",20.50,3,1},
                    {"Whatever It Takes","Imagine Dragons",18.50,4,1},
                    {"Bordeline","Tame Impala",19.90,5,1},
                    {"Don't Stop Me Now","Queen",20.00,6,1}
};

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

//funzione per aggiungere i dischi
void aggiungi_disco(int *disco_nuovo, int *n_codice)
{
    //se sono minori di 100 allora si possono aggiungere
    if (*disco_nuovo<100)

    {
        printf("Inserisci il titolo del disco \n");
        fgets(archivio[*disco_nuovo].titolo,50,stdin);
        archivio[*disco_nuovo].titolo[strcspn(archivio[*disco_nuovo].titolo,"\n")]='\0';

        printf("inserisci l'autore o la band del disco \n");
        fgets(archivio[*disco_nuovo].autore_band, 50, stdin);
        archivio[*disco_nuovo].autore_band[strcspn(archivio[*disco_nuovo].autore_band,"\n")]='\0';

        printf("inserisci il prezzo del  disco \n");
        scanf("%f",&archivio[*disco_nuovo].costo_prestito);
        getchar();

        archivio[*disco_nuovo].disponibile=1;
        (*disco_nuovo)++;
        assegna_codice(n_codice, disco_nuovo);


    }
    else //se i dischi sono 100 non si possono più aggiungere
    {
        printf("il nostro archivio e' pieno! non e' possibile aggiungere ulterior dischi \n");
    }


}
//assegna automaticamente il codice ad un disco
void assegna_codice(int *n_codice, int *disco_nuovo)
{

   char scelta;

   archivio[*disco_nuovo].codice=*n_codice; //aumenta il putatore legato al numero del codice

   printf("il codice del disco e' %d \n", *n_codice);

   (*n_codice)++;




}//permette la visualizzazione di tutti i disci presenti nell'archivio
void visualizza_dischi(int *disco_nuovo)
{
     //tramite due cicli annidati divido i dischi per autore o band
     for (int i=0; i<*disco_nuovo; i++)
   {
       for (int j=i+1; j<*disco_nuovo; j++)
       {
           if(strcmp(archivio[i].autore_band,archivio[j].autore_band)>0)
           {
    disco var_temp=archivio[i];
            archivio[i]=archivio[j];
            archivio[j]=var_temp;
           }
       }
   }  //tramite altri due cicli annidati faccio si che anche i codici siano sistemati
       for (int i=0; i<*disco_nuovo; i++)
   {
       for (int j=i+1; j<*disco_nuovo; j++)
       {
           if(archivio[i].codice>archivio[j].codice)
           {
        int var_temp=archivio[i].codice;
            archivio[i].codice=archivio[j].codice;
            archivio[j].codice=var_temp;
           }
       }
   }
    //con u for procedo all visualizzazione di tutti i dischi
    for ( int i=0; i<*disco_nuovo; i++)
    {
        printf("Titolo:%s \n",archivio[i].titolo);
        printf("Autore/Band:%s \n", archivio[i].autore_band);
        printf("Costo prestito:%.2f \n",archivio[i].costo_prestito);
        printf("Codice: %d \n",archivio[i].codice);
        printf("\n");
    }

}
//fuznione che permette di "noleggiare" un disco se è presente
void preleva_disco (int trovato, int *disco_nuovo)
{
  char nome_disco[50];

  printf("inserire il nome del disco da noleggiare \n");
//tramite fgets si possono scrivere anche titoli di canzoni con più parole
  fgets(nome_disco,50,stdin);
 //tramite strcspn facciamo si che il carattere \n venga sostituito da \0 così che non venga visualizzato
  nome_disco[strcspn(nome_disco,"\n")]='\0';

  trovato=0;

  for(int i=0; i<*disco_nuovo; i++)
  {
      //tramite strcmp si controlla se il disco scritto corrisponda a quello dell'archivio
      if(strcmp(nome_disco,archivio[i].titolo)==0){

      trovato=1;

    // se è disponibile viene noleggiato e la variabile della disponibilità viene azzerata (non è possibile riprenderlo)
      if (archivio[i].disponibile==1){

        printf("disco noleggiato con successo, goditi la tua musica preferita \n");

        archivio[i].disponibile=0;
      }
    else
    {   //se non c'è un messaggio di testo ne avviserà la mancanza
        printf("ci dispiace, purtroppo il disco e' stato gia' noleggiato \n");
    }
    break;

      }
  }

if (!trovato) // se i nomi non corrispondono, si ricerca
{
  printf("disco non trovato, riprovi per favore \n");

  preleva_disco(trovato, disco_nuovo);
}

}
//funzione che confronta tutti i dischi per trovare il più costsoso tramite un approccio ricorsivo e incrementale
void piu_costoso(int *disco_nuovo, int indice, int* indice_max, float *max_costo)
{
    //esaminati tutti i dischi presenta il messaggio con il disco più costoso
   if (indice==*disco_nuovo)
   {
       printf("il disco con il costo maggiore e' %s ", archivio[*indice_max].titolo);

       printf("con il costo di %.2f \n",*max_costo);
       return;
   }//sostituisco il disco maggiore se c'è un altro di costo ancora più alto
   if(archivio[indice].costo_prestito>*max_costo)
   {
       //sostituisco l'indice
       *indice_max=indice;
      //sostitusisco il costo
       *max_costo=archivio[indice].costo_prestito;
   }
   //tramite chiamata ricorsiva aumento l'indice fino a quando non finiscono i cofronti
    piu_costoso(disco_nuovo,indice+1,indice_max,max_costo);
}

