#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SIM.h"
#include "GRAPH.h"



int main() {
    FILE* fp;
    char vertice1[30];
    char vertice2[30];
    char rete1[30];
    char rete2[30];
    int t;
    TAB tab;
    int n=0;
    fp = fopen("C:\\Users\\hanan\\OneDrive\\Desktop\\APA\\grafo.txt","r");
    if(fp==NULL) EXIT_FAILURE;
    while(fscanf(fp,"%s %s %s %s %d\n", vertice1, rete1, vertice2, rete2, &t)!=EOF)
    {
        n++;//in base questo alloca sia la matrice di simboli che il numero di archi
    }
    fclose(fp);
    //ALLOCAZIONE DELLA TABELLA DI SIMBOLI
    tab = Sinit(n);
    fp = fopen("C:\\Users\\hanan\\OneDrive\\Desktop\\APA\\grafo.txt","r");
    //FUNZIONE INSERIMENTO DEI VERTICI
    while(fscanf(fp,"%s %s %s %s %d\n", vertice1, rete1, vertice2, rete2, &t)!=EOF)
    {
        char* vertice;
        if(searchbyname(tab, vertice1)==-1){
            vertice = strdup(vertice1);
            insert(vertice,tab);
        }

        if(searchbyname(tab, vertice2)==-1) {
            vertice = strdup(vertice2);
            insert(vertice, tab);
        }
    }
    stampa(tab);
    //printf("%d\n", getsize(tab));


    GRAPH G;
    G = Ginit(getsize(tab), tab);
    rewind(fp);
    while(fscanf(fp,"%s %s %s %s %d\n", vertice1, rete1, vertice2, rete2, &t)!=EOF)
    {
        Edge e;
        e.v = searchbyname(tab,vertice1);
        e.w = searchbyname(tab, vertice2);
        Ginsert(e,G);
    }

    Printmatrix(G);

    printf("\n");
    OrdineA(G);
    printf("\n");
    Parchi(G);
    //int verifyV(char* verticeA, char* verticeB, char* verticeC, GRAPH graph)
    if(verifyV("Tatooine","Shiva","Uriel",G)==1) printf("hey ziki good job");
    fclose(fp);
    return 0;
}






