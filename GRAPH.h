//
// Created by hanan on 09/04/2020.
//

#ifndef APA_GRAPH_H
#define APA_GRAPH_H
#include "SIM.h"
typedef struct{int v; int w; int wt;}Edge;
typedef struct graph* GRAPH;
typedef struct list* LIST;

GRAPH Ginit(int n, TAB tab);
void Ginsert(Edge edge, GRAPH graph);
void Printmatrix(GRAPH graph);
void OrdineA(GRAPH graph);
void Parchi(GRAPH graph);
int verifyV(char* verticeA, char* verticeB, char* verticeC, GRAPH graph);



#endif //APA_GRAPH_H
