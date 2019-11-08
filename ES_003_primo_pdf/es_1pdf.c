#include <stdio.h>
#include <stdlib.h>

int main()
{
    float *p; // creo un puntatore p
    int dim;
    float element;
    int k;

    printf("inserire la dimensione del vettore: "); //chiedo la dimensione del vettore
    scanf("%d", &dim);

    p = (float *)malloc(dim * sizeof(float)); //alloco in memoria lo spazio per il

    for (k = 0; k < dim; k++)
    { //inserisco gli elementi del vettore
        printf("\nil %d elemento: ", k);
        scanf("%f", &element);
        printf("indirizzo: %p \n", p);
        p++;
    }

    return 0;
}