#ifndef HEADER_H
#define HEADER_H

typedef struct {
    char *cuvant;
} _v;

typedef struct {
    char litera;
    int tip; // -1 0 1; -1 - consoana, 0 - semivocala, 1 - vocala
} lit;

char *citire();
int numarCuvinte(char *propozitie);
_v *alocareVectorCuvinte(int nrCuvinte);
_v *generareVectorCuvinte(char *propozitie);
void afisareVectorCuvinte(_v *vector, int nrCuvinte);
_v *generareVectorInSilabe(_v *vector, int nrCuvinte);
char *despartireCuvant(char *word);
int eVocala(char c);

#endif
