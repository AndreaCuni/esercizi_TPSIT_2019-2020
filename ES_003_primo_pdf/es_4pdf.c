#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define LUNG_NOME 50 //creo la costante per la lunghezza massima della stringa

typedef struct imp
{                       //cero la struttura imp
    char *nome_imp;     //creo un puntatore a char per salvare il nome dell'impiegato
    int id_imp;         //creo una variabile per salvare l'identificativo dell'impiegato
} Imp;

int main()
{
    Imp **vett;                          //creo un vettore di puntatori alla struttura Imp
    int num;                             //creo la variabile num per memorizzare il numero di impiegati
    int i = 0;                           //contatore
    char riga[LUNG_NOME];                //creo la stringa di appoggio riga
    Imp imp[num];                        //creo un vettore per memorizzare il contenuto delle strutture

    printf("quanti impiegati ci sono?"); //chiedo quanti sono gli impiegati
    scanf("%d", &num);

    vett = (Imp **)malloc(num * sizeof(Imp *)); //alloco uno spazio al vettore di puntatori
    for (i = 0; i < num; i++)
    {                                                                            
        printf("inserire il nome dell'impiegato (max %d caratteri)", LUNG_NOME); 
        fflush(stdin);                                                           
        gets(riga);                                                              
        (imp + i)->nome_imp = (char *)malloc(strlen(riga) * sizeof(char));        //alloco il nome dell'impiegato e lo assegno a nome_imp
        strcpy((imp + i)->nome_imp, riga);                                        //copio il nome dell'impiegato nella struttura Imp
        (imp + i)->id_imp = 1000 + i;                                             //assegno all'impiegato un identificatore
        *(vett + i) = (imp + i);                                                  //assegno alla cella del vettore di puntatori il puntatore della struttura
    }
    for (i = 0; i < num; i++)
    {                                                                                                //ripeto il ciclo per il numero di impiegati
        printf("\n id_imp= %d \t nome_imp= %s", (*(*(vett + i))).id_imp, (*(*(vett + i))).nome_imp); //stampo l'identificativo e il nome dell'impiegato
    }

    free(vett); //libero lo spazio utilizzato dal vettore di strutture
}