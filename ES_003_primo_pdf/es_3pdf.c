#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LUNG 200

int main()
{
    char string[LUNG];
    printf("inserire un string (max %d caratteri)", LUNG); //chiedo di inserire la string
    gets(string);
    bool end = true; //creo la variabile di fine della stringa
    int cont = 0;    //creo un contatore
    int i;

    for (i = 0; end; i++)
    { //ripeto finchè non finisce la string
        if (*(string + i) == '\0')
        {                //controllo il carattere \0 (che termina la stringa)
            end = false; //esco dal ciclo
        }
        cont++; //incremento il contatore
    }

    printf("la string è lunga %d caratteri", cont); //stampo la dimensione della stringa
}