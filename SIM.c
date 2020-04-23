//
// Created by hanan on 10/04/2020.
//

#include "SIM.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct tab{char** tabella;int MAX; int now;};





TAB Sinit(int n) //inizializza la tabella
{
    TAB tab;
    tab = malloc(sizeof(*tab));
    tab->tabella = malloc(2*n*sizeof(char*));
    tab->now = 0;
    int MAX = n;
    return tab;
    //TABELLA ALLOCATA
}

void insert(char* vertice,TAB tab) //ALL'ESAME è MEGLIO PRATICARE LA SOLUZIONE PIU FACILE, meglio una lista o oppure un tabella di simboli tramite hash
{
    int i = tab->now++;
    while( (i>0) && strcmp(vertice,tab->tabella[i-1])<0)
    {
        tab->tabella[i] = tab->tabella[i-1];
        i--;
    }
    tab->tabella[i] = vertice;
}


char* searchbyindex(int i, TAB tab)
{
    if(tab->tabella[i]!=NULL)
        return tab->tabella[i];
    return NULL;
}

int searchbyname(TAB tab, char* vertice){
    int i;
    if(tab->now==0) return -1;
    for(i=0;i<tab->now;i++)
    {
        if(strcmp(tab->tabella[i], vertice)==0) return i;
    }
    return -1;
}

void stampa(TAB tab)
{
    int i;
    for(i=0;i<tab->now;i++)
    {
        printf("%s\n",tab->tabella[i]);
    }
}

int getsize(TAB tab)
{
    return tab->now;
}