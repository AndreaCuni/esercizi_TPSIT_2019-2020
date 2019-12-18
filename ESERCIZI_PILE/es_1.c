/*
Es 1 Pile: Creare un programma che dato un numero intero, avente un numero arbitrario di cifre inserite
dall’utente, lo scriva in output con le cifre in ordine inverso. Utilizzare una pila e le implementazioni
dei metodi push e pop
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct El{
    int valore;
    struct El* next;
}El;

bool controlloStringa(char cifra[]);
struct El* pop(struct El** head);
void push(struct El** head, struct El* element);
void stampaPila(struct El** head);

int main(){
    struct El* head;
    struct El* element;
    char cifra[1000];
    
    printf("\nInserire il numero:  ");      //richiedo il numero
    fflush(stdin);
    scanf("%s", cifra);
    
    int i=0;    //contatore per scorrere i caratteri della stringa
    do{
        element = (struct El*) malloc(sizeof(struct El));   //alloco lo spazio necessario al puntatore
        element->valore=cifra[i]-48;    //aggiorno il valore in base a quello della stringa, tolgo 48 per il codice ASCII
        i++;
        push(&head,element);    //aggiungo l'elemento alla mia pila
    }while(cifra[i]!='\0'); //lo ripeto finchè non ho finito di leggere la stringa

    stampaPila(&head);

    printf("\n\npremere un tasto per continuare...");
    fflush(stdin);
    getch();
    return 0;
 }

void push(struct El** head, struct El* element){ //aggiungo l'elemento
	if (*head==NULL){
		*head = element;
		element->next = NULL;
	}else{
		element->next = *head;
		*head = element;
	}
}

struct El* pop(struct El** head){   //tolgo e leggo l'elemento
	struct El *ret = *head;
	if(*head==NULL){
		return NULL;
	}else{
		*head = ret->next;
	}
	return ret;
}



void stampaPila(struct El** head){  //stampo la pila
    struct El *ret;
    int i=1;
    ret=pop(head);

    while(ret!=NULL){   //ripeto finchè ci sono elementi
        printf("\n valore [%d]: %d", i, ret->valore);
        i++;
        free(ret);  //libero lo spazio che ormai non mi serve più
        ret=pop(head);  //leggo il prossimo elemento
    }
    
    return;
}