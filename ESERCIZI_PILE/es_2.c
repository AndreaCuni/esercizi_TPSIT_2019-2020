/*
Es 2 Pile: Scrivere un programma che chieda all’utente una string composta da parentesi aperte e chiuse: 
(,),[,],{,} e che verifichi se le coppie e l’ordine delle (,),[,],{,} sono corretti. Utilizzare uno stack.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct El{
    char valore;
    struct El* next;
}El;

struct El* pop(struct El** head);
void push(struct El** head, struct El* element);
void stampaLista(struct El* l);

int main(){
    struct El* head=NULL;
    struct El* element;
    struct El* item;
    char string[1000];

    printf("\nInserire la stringa:  ");
    fflush(stdin);
    scanf("%s", string);
    int i=0;
    do{
        if(string[i]=='('||string[i]==')'||string[i]=='['||string[i]==']'||string[i]=='{'||string[i]=='}'){
            element = (struct El*) malloc(sizeof(struct El));
            element->valore=string[i];
            if(head==NULL){
                push(&head,element);
            }else
            { 
                if(head->valore=='('&&element->valore==')'){
                    item=pop(&head);
                    free(item);
                }else if(head->valore=='['&&element->valore==']'){
                    item=pop(&head);
                    free(item);
                }else if(head->valore=='{'&&element->valore=='}'){
                    item=pop(&head);
                    free(item);
                }else{
                    push(&head,element);
                }
            }
        }
        i++;

    }while(string[i]!='\0');
    printf("\nfine caricamento \n");
    stampaLista(head);
    if(head==NULL){
        printf("le parentesi sono giuste");
    }

    printf("\n\npremere un tasto per continuare...");
    fflush(stdin);
    getch();
    return 0;
 }

void push(struct El** head, struct El* element){ //inserisco un elemento
	if (*head==NULL){
        element->next = NULL;
		*head = element;
	}else{
		element->next = *head;
		*head = element;
	}
}

struct El* pop(struct El** head){   //tolgo un elemento
	struct El* ret = *head;
	if(*head==NULL){
		return NULL;
	}else{
		*head = ret->next;
	}
	return ret;
}

void stampaLista(struct El* l){  //inserire l'inizio della lista
    if(l!=NULL){    //ripeto finchè esiste un elemento successivo
        printf("%c \n",l->valore);    //stampo il valore dell'elemento della lista e l'indirizzo del successivo
        l=l->next; //passo all'elemento successivo della lista
        stampaLista(l); //passo all'elemento successivo
    }
    return;
}