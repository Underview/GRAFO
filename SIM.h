//
// Created by hanan on 10/04/2020.
//

#ifndef APA_SIM_H
#define APA_SIM_H

typedef struct tab* TAB;

TAB Sinit(int n);
void insert(char* vertice,TAB tab);
char* searchbyindex(int i, TAB tab);
int searchbyname(TAB tab, char* vertice);
void stampa(TAB tab);
int getsize(TAB tab);


#endif //APA_SIM_H
