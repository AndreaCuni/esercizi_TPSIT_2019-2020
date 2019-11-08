#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int dim, num;
    int* array;
    printf("quanto e' lungo il tuo array? \n");
    scanf("%d", &dim);
    array= malloc(dim*sizeof(4));
    if(array==NULL){
        printf("l'allocazione dell' array non e' andata a buon fine.");
    }else{
        for(int k=0;k<dim;k++){
            printf("carica un numero.");
            scanf("%d", &num);
        }
    }
}