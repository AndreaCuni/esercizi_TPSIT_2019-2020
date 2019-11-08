#include <stdio.h>
#include <stdlib.h>

int main()
{
    float *punt; //dichiaro il puntatore di tipo decimale
    int dim;     //numeri da inserire
    int i = 0;   //contatore
    float max;   //creo la variabile per salvare il massimo

    do
    {
        printf("quanti numeri si vuole inserire?");
        scanf("%d", &dim);
    } while (dim <= 0); //verifico ceh la dimensione sia maggiore di 0

    punt = (float *)malloc(dim * sizeof(float)); //alloco lo spazio per il puntatore
    *punt = 0;

    for (i = 0; i < dim; i++)
    { //insierisco gli elementi del vettore
        printf("inserire un numero: ");
        scanf("%f", (punt + i));
    }

    for (i = 0; i < dim; i++)
    { //ripeto per il numero di elementi
        printf("\nil numero %d e': %f", i, *(punt + i));
    }

    max = *punt;

    for (i = 0; i < dim; i++)
    { //ricerca del maggiore
        if (max < *(punt + i))
        {                      //controllo se l'elemento attuale del vettore è maggiore di quello precedente
            max = *(punt + i); //aggiorno il massimo
        }
    }

    printf("\nil numero piu' grande e': %f", max); //stampo il valore massimo

    free(punt); //libero lo spazio occupato in memoria dal vettore punt
}