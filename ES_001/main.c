/*

ES_001_csv
Author: Cuniberti Andrea
Class: 4AROB
date:16-09-2019

Creare un programma in linguaggio C che legga il file vgsales.csv e lo importi in un array di strutture.
Ogni riga contiene i campi separati da virgole, per cui puo' essere comodo creare una funzione split
che dalla riga letta ritorni la struttura valorizzata.

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define L_STRINGA 50       //definisco la dimensione massima per le stringhe della tabella
#define L_RIGA 500         //definisco la dimensione massima di ogni riga del file
#define NUMERO_RIGHE 16600 //definisco il numero righe da leggere del file CSV
#define N_ELEM 11          //definisco il numero delle colonne della tabella
#define SEPARATORE ","     //definisco il carattere separatore dei vari campi

typedef struct Tabella
{ //dichiarazione della struttura
    int Rank;
    int Year;
    char Name[L_STRINGA];
    char Platform[L_STRINGA];
    char Genre[L_STRINGA];
    char Publisher[L_STRINGA];
    float NA_Sales;
    float EU_Sales;
    float JP_Sales;
    float Other_Sales;
    float Global_Sales;
} Tabella;

void ScannerizzaTabella(Tabella dati[], int *elementi, char descr[][L_STRINGA]); //dichiarazione delle funzioni
void StampaTabella(Tabella dati[], int elementi, char descr[][L_STRINGA]);

Tabella dati[NUMERO_RIGHE]; //dichiarazione della tabella

int main()
{
    int elementi = 0;              //conta il numero di elementi
    char descr[N_ELEM][L_STRINGA]; //salva la descrizione delle colonne della tabella

    ScannerizzaTabella(dati, &elementi, descr);
    StampaTabella(dati, elementi, descr);

    fflush(stdin); //pulisco la testiera
    getch();       //attendo la pressione un tasto
    return 0;
}

void ScannerizzaTabella(Tabella dati[], int *elementi, char descr[][L_STRINGA])
{
    FILE *fp;
    fp = fopen("vgsales.csv", "r"); //apro il file in read
    int i = -1;                     //lo inizializzo a -1 per memorizzare la prima riga della tabella
    char riga[L_RIGA];              //dichiaro il vettore di char dove memorizzerò una riga alla volta
    char *campo;                    //dichiaro il puntatore campo di tipo char

    while (i < NUMERO_RIGHE && fgets(riga, L_RIGA, fp) != NULL)
    {
        if (i != -1)
        {                                     //memorizzo l'intestazione
            campo = strtok(riga, SEPARATORE); //prelevo i campi della tabella dalla riga e li salvo
            dati[i].Rank = atoi(campo);       //strtok permette di dividere una stringa alla prima occorenza del secondo parametro
            campo = strtok(NULL, SEPARATORE); //successivamente se al posto della stringa inserisco NULL continuerà dal punto precedentemente
            strcpy(dati[i].Name, campo);      //strcpy permette di copiare il contenuto della seconda stringa nella prima
            campo = strtok(NULL, SEPARATORE);
            strcpy(dati[i].Platform, campo);
            campo = strtok(NULL, SEPARATORE);
            dati[i].Year = atoi(campo);
            campo = strtok(NULL, SEPARATORE);
            strcpy(dati[i].Genre, campo);
            campo = strtok(NULL, SEPARATORE);
            strcpy(dati[i].Publisher, campo);
            campo = strtok(NULL, SEPARATORE);
            dati[i].NA_Sales = atof(campo);
            campo = strtok(NULL, SEPARATORE);
            dati[i].EU_Sales = atof(campo);
            campo = strtok(NULL, SEPARATORE);
            dati[i].JP_Sales = atof(campo);
            campo = strtok(NULL, SEPARATORE);
            dati[i].Other_Sales = atof(campo);
            campo = strtok(NULL, SEPARATORE);
            dati[i].Global_Sales = atof(campo);
            *elementi = *elementi + 1; //incremento il contatore degli elementi
        }
        else
        { //altrimenti leggo la prima riga mi salvo le decrizioni nel vettore descrizione

            campo = strtok(riga, SEPARATORE);
            strcpy(descr[0], campo);
            campo = strtok(NULL, SEPARATORE);
            strcpy(descr[1], campo);
            campo = strtok(NULL, SEPARATORE);
            strcpy(descr[2], campo);
            campo = strtok(NULL, SEPARATORE);
            strcpy(descr[3], campo);
            campo = strtok(NULL, SEPARATORE);
            strcpy(descr[4], campo);
            campo = strtok(NULL, SEPARATORE);
            strcpy(descr[5], campo);
            campo = strtok(NULL, SEPARATORE);
            strcpy(descr[6], campo);
            campo = strtok(NULL, SEPARATORE);
            strcpy(descr[7], campo);
            campo = strtok(NULL, SEPARATORE);
            strcpy(descr[8], campo);
            campo = strtok(NULL, SEPARATORE);
            strcpy(descr[9], campo);
            campo = strtok(NULL, SEPARATORE);
            strcpy(descr[10], campo);
        }

        i++; //incremento la i per memorizzare nella riga successiva della mia tabella
    }

    fclose(fp);
    return;
}

void StampaTabella(Tabella dati[], int elementi, char descr[][L_STRINGA])
{
    int i;

    printf("%s\t", descr[0]); //stampo il primo elemento della descrizione

    for (i = 1; i < N_ELEM; i++)
    {                            //ripeto a partire del secondo elemento del vettore
        printf(";%s", descr[i]); //stampo la descrizione
    }

    for (i = 0; i < elementi; i++)
    { //stampo ogni riga della tabella
        printf("\n%d\t;%s;%s;%d;%s;%s;%.2f;%.2f;%.2f;%.2f;%.2f", dati[i].Rank,
               dati[i].Name, dati[i].Platform, dati[i].Year, dati[i].Genre, dati[i].Publisher,
               dati[i].NA_Sales, dati[i].EU_Sales, dati[i].JP_Sales, dati[i].Other_Sales, dati[i].Global_Sales);
    }

    return;
}