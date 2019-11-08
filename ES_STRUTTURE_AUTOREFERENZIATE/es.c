#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 50

struct contact{
	char name[DIM];
	int number;
	struct contact* next;
    struct contact* pre
}Contact;


int main(){
    struct contact io;
	struct contact giovanni;
    struct contact mamma;

	strcpy(mamma.name, "giovanni");
	mamma.number = 35;
	mamma.previous = NULL;   

	strcpy(mamma.name, "mamma");
	mamma.number = 12;
	mamma.next = &io;    //punta a io
	
	strcpy(mamma.name, "io");
	mamma.number = 43;
	mamma.next = &giovanni;     //punta a giovanni
    return 0;
}
