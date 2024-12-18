#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(void) {
    char *propozitie = citire();
    printf("Propozitia citita: %s\n", propozitie);

    int nrCuvinte = numarCuvinte(propozitie);
    printf("Numarul de cuvinte: %d\n", nrCuvinte);

    _v *vector = generareVectorCuvinte(propozitie);
    printf("Cuvintele din vector:\n");
    afisareVectorCuvinte(vector, nrCuvinte);

    _v *inSilabe = generareVectorInSilabe(vector, nrCuvinte);
    printf("Cuvintele despărțite în silabe:\n");
    afisareVectorCuvinte(inSilabe, nrCuvinte);

    for (int i = 0; i < nrCuvinte; ++i) {
        free(vector[i].cuvant);
        free(inSilabe[i].cuvant);
    }
    free(vector);
    free(inSilabe);
    free(propozitie);

    return 0;
}
