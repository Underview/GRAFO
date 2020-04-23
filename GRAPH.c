//
// Created by hanan on 09/04/2020.
//

#include "GRAPH.h"
#include <stdio.h>
#include <stdlib.h>
#include "SIM.h"
typedef struct node* link;
struct node{Edge e;link next;};
struct list{link HEAD;int N;};


struct graph{Edge* edge;int E; int V;int **matrix;TAB tab;LIST ladj;};
//gli indici indicano il vertice di partenza
LIST listinit(int N)
{
    LIST l;
    int i;
    l = malloc(N*sizeof(*l));
    return l;
}
//creazione del nodo
void createNode(Edge e,link next)
{
    link n;
    n = malloc(sizeof(*n));
    n->e = e;
    n->next = NULL;
    next = n;
}
void ListG(GRAPH graph)//int i indica la colonna,
{
    int i;
    int j;
    for(i=0;i<graph->V;i++)
        for(j=0;j<graph->V;j++)
            printf("luigi");

}



GRAPH Ginit(int n, TAB tab)
{
    int i;
    int j;
    GRAPH graph;
    graph = malloc(sizeof(*graph));
    graph->tab = tab;
    graph->edge = malloc(n*sizeof(Edge));
    graph->E = 0;
    graph->V = n;
    graph->matrix = malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
    {
        graph->matrix[i] = malloc(n*sizeof(int));
    }

    for(i=0;i<n;i++) {
        for (j = 0; j < n; j++) {
            graph->matrix[i][j]=0;
        }
    }


    return graph;
}


void Ginsert(Edge edge, GRAPH graph)
{
    graph->matrix[edge.v][edge.w] = 1;
    graph->matrix[edge.w][edge.v] = 1;
}

void Printmatrix(GRAPH graph)
{
    int i;
    int j;
    for(i=0;i<graph->V;i++)
    {
        for(j=0;j<graph->V;j++)
        {
            printf("%d ",graph->matrix[i][j]);
        }
        printf("\n");
    }
}


void OrdineA(GRAPH graph) {
    int i;
    for (i = 0; i < graph->V; i++)
        printf("%s[%d]\n", searchbyindex(i, graph->tab), i);
}

void print(GRAPH graph, int j)
{
    int i;
    printf("incidono su %s[%d]\n", searchbyindex(j,graph->tab),j);
    for(i=0;i<graph->V;i++)
    {
        if(graph->matrix[j][i]==1)
        printf("%s[%d] \n", searchbyindex(i,graph->tab),i);
    }
}
void Parchi(GRAPH graph)
{
    int i=0;
    for(i=0; i<graph->V;i++)
    {
        print(graph,i);
        printf("\n");
    }

}



int WverifyV(int j,int b, int c, int N,int** matrix)
{
    int i;
    int count=0;
    for(i=0;i<N;i++)
    {
        if(matrix[j][i]==1)
        {
            if(i==b) count++;
            if(i==c) count++;
        }
    }
    return count==2 ? 1:0;
}

int verifyV(char* verticeA, char* verticeB, char* verticeC, GRAPH graph)
{
    int a = searchbyname(graph->tab, verticeA);
    int b = searchbyname(graph->tab, verticeB);
    int c = searchbyname(graph->tab, verticeC);


    int count=0;
    count+=WverifyV(a,b,c,graph->V,graph->matrix); //verifico adiacenza da a
    count+=WverifyV(c,a,b,graph->V,graph->matrix); //verifico adiacenza da b
    count+=WverifyV(b,c,a,graph->V,graph->matrix);//verifico adiacenza da c
    return count==3 ? 1:0; // se tutti e tre sono verificati allora ottimo lavoro
}

//TODO generare la rappresentazione a lista adiacenza, senza leggere nuovamente il file