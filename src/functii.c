#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "header.h"

char *citire() {
    char *propozitie = NULL;
    size_t size = 0, index = 0;
    char c;

    propozitie = malloc(128); 
    size = 128;

    while ((c = getchar()) != '.' && c != '\n') {
        if (index + 1 >= size) {
            size *= 2; 
            propozitie = realloc(propozitie, size);
        }
        propozitie[index++] = c;
    }
    propozitie[index] = '\0'; 
    return propozitie;
}

int numarCuvinte(char *propozitie) {
    int numar = 0;
    int inCuvant = 0;

    for (int i = 0; propozitie[i] != '\0'; i++) {
        if (isspace(propozitie[i])) {
            inCuvant = 0;
        } else if (!inCuvant) {
            inCuvant = 1;
            numar++;
        }
    }
    return numar;
}

_v *alocareVectorCuvinte(int nrCuvinte) {
    _v *vectorCuvinte = malloc(nrCuvinte * sizeof(_v));
    for (int i = 0; i < nrCuvinte; ++i) {
        vectorCuvinte[i].cuvant = NULL;
    }
    return vectorCuvinte;
}

_v *generareVectorCuvinte(char *propozitie) {
    int nrCuvinte = numarCuvinte(propozitie);
    _v *vector = alocareVectorCuvinte(nrCuvinte);

    char *p = strtok(propozitie, " ");
    int i = 0;
    while (p) {
        vector[i].cuvant = malloc(strlen(p) + 1);
        strcpy(vector[i].cuvant, p);
        p = strtok(NULL, " ");
        i++;
    }
    return vector;
}

void afisareVectorCuvinte(_v *vector, int nrCuvinte) {
    for (int i = 0; i < nrCuvinte; ++i) {
        printf("%s ", vector[i].cuvant);
    }
    printf("\n");
}

int eVocala(char c) {
    return strchr("aeiouAEIOU", c) != NULL;
}

//a e i o u
// formare semivocale : daca a si e sunt una langa alta => se desparte dupa a;


char *despartireCuvant(char *word) {
    lit *vector = 0;
    vector = malloc(255 * sizeof(lit));
    for(int i = 0; i < strlen(word); ++i) {
        if(eVocala(word[i])) {
            
        } else {
            vector[i].litera = word[i];
            vector[i].tip = -1;
        }
    }
}

_v *generareVectorInSilabe(_v *vector, int nrCuvinte) {
    _v *inSilabe = alocareVectorCuvinte(nrCuvinte);

    for (int i = 0; i < nrCuvinte; ++i) {
        inSilabe[i].cuvant = despartireCuvant(vector[i].cuvant);
    }
    return inSilabe;
}
