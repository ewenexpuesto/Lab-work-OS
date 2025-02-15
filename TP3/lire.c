#include <stdio.h>
#include "/pub/FISE_OSSE11/syscall/lire.h"

int main() {
    fprintf(stderr, "Je suis le programme lire.\n");
    lire();
    return 0;
}

/* En exécutant cela, on rentre les données de data/in dans le programme lire.c */