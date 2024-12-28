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

char *despartireCuvant(char *cuvant) {
    int lungime = strlen(cuvant);
    char *rezultat = malloc(2 * lungime + 1); // Extra space for hyphens
    int pozRezultat = 0;
    int ultimaVocala = -1;

    // Copy first character
    rezultat[pozRezultat++] = cuvant[0];
    
    if (eVocala(cuvant[0])) {
        ultimaVocala = 0;
    }

    for (int i = 1; i < lungime; i++) {
        // Rules for splitting:
        // 1. Between two vowels
        // 2. Between consonant and vowel if consonant follows vowel
        // 3. Between consonants if second starts a valid syllable
        
        if (eVocala(cuvant[i])) {
            if (ultimaVocala == i-1) {
                rezultat[pozRezultat++] = '-';
            }
            rezultat[pozRezultat++] = cuvant[i];
            ultimaVocala = i;
        } else {
            // Current char is consonant
            if (i < lungime-1 && eVocala(cuvant[i+1])) {
                // Next char is vowel
                if (ultimaVocala != -1 && i-ultimaVocala > 1) {
                    rezultat[pozRezultat++] = '-';
                }
            }
            rezultat[pozRezultat++] = cuvant[i];
        }
    }
    
    rezultat[pozRezultat] = '\0';
    return rezultat;
}


_v *generareVectorInSilabe(_v *vector, int nrCuvinte) {
    _v *inSilabe = alocareVectorCuvinte(nrCuvinte);

    for (int i = 0; i < nrCuvinte; ++i) {
        inSilabe[i].cuvant = despartireCuvant(vector[i].cuvant);
    }
    return inSilabe;
}
