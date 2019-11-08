/*crea una lista e la stampa*/
#include <stdio.h>
#include <stdlib.h>
struct El
{
    int valore;
    struct El *next;
};
int main()
{
    int n;
    struct El *lista;   //puntatore al primo elemento della lista
    struct El *l;
    lista = NULL; /* inizializzo il puntatore NULL */

    do
    {
        printf("Inserisci un naturale o -1 per terminare\n");
        scanf("%d", &n);
        if (n >= 0)
        {
            if (lista == NULL) /* verifico se il puntatore lista assume valore NULL */
            {
                /* in questo caso alloco in memora per una struttura */
                lista = (struct El *)malloc(sizeof(struct El));
                l = lista;
            }
            else /* se il puntatore lista è diverso da NULL */
            {
                /* assegno al puntatore l della elemento corrente un puntatore che punta all'elemento successivo  */
                l->next = (struct El *)malloc(sizeof(struct El));
                l = l->next;
            }
            l->valore = n;  /* assegno n al campo valore dell'elemento corrente */
            l->next = NULL; /* assegno al campo next dell'elemento corrente il valore NULL */
        }
    } while (n >= 0);

    printf("numeri inseriti: \n");
    stampaRicorsiva(lista);
    contaElementi(lista);

    //l = lista; /* assegno alla variabile di appoggio l il puntatore al primo elemento della lista */
    //printf("numeri inseriti: \n");
    //while (l != NULL)
    //{
    //    printf("%d - %p \n", l->valore, l->next);
    //    l = l->next; /* il puntatore corrente è assegnato al puntatore all'elemento successivo */
    //}
    //printf("\n");
    return 0;

}

void contaLista(l){
    
}

void stampaRicorsiva(struct El *l){
    if (l != NULL)
    {
        printf("%d - %p \n", l->valore, l->next);
        l = l->next; /* il puntatore corrente è assegnato al puntatore all'elemento successivo */
        stampaRicorsiva(l);
    }
    return;
}

