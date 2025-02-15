/* QUESTION 1 */

/* Voici la fonction de /pub/FISE_OSSE11/syscall/lire.c */
/*
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#include "lire.h"

void lire()
{
    int nbCarLus, nbCarEcrits;
    char tab[100];

    nbCarLus = read(0, tab, 100);
    if (nbCarLus == -1) {
        fprintf(stderr, "lire(): pb de lecture : %s\n", strerror(errno));
        exit(1);
    }

    fprintf(stderr, "lire(): nbCarLus = %d\n", nbCarLus);

    nbCarEcrits=write(1,tab,nbCarLus);
    if (nbCarEcrits == -1) {
        fprintf(stderr, "lire(): pb d'ecriture : %s\n", strerror(errno));
        exit(1);
    }
}

Le fichier lire.h contient
#ifndef FILE_LIRE_H
#define FILE_LIRE_H

void lire();

#endif
*/

/* read (0,...) allows to read stdint and write (1,...) allows to write on stdout */