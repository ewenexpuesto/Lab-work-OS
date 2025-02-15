#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <assert.h>

void sigpipe(int sig) {
    assert(sig == SIGPIPE);
    fprintf(stderr, "SIGPIPE received... aborting in 5 seconds\n");
    sleep(5);
    exit(0);
}

int main(int argc, char* argv[]) {
    if (argc != 1) {
        fprintf(stderr, "usaage: %s\n", argv[0]);
        exit(1);
    }

    fprintf(stderr, "%s: started\n", argv[0]);
    signal(SIGPIPE, sigpipe);
    
    while (1) {
        char c;
        int statut = read(0, &c, 1);
        if (statut == -1) {
            perror("[read]");
            exit(2);
        } else if (statut == 0) {
            write(2, ".", 1);
            usleep(100000); /* 0.1s */
        } else { /* statut == 1 */
            write(1, &c, 1);
        }
    }

    return 0;
}

/* QUESTION 1 */
/*
Lignes 24 + 10 à 15
Attache le gestionnaire au signal SIGPIPE.
Le gestionnaire affiche un message, attend 5 secondes, puis termine
le processus avec 0 comme code de retour.

Lignes 26 à 38 boucle infinie :
Ligne 28 : lecture d'un caractère c sur le flux d'entrée standard ;
Ligne 29 à 31 : si une erreur de lecture s'est produite, on écrit
un message d'erreur et on arrête/termine le processus ;
Ligne 32 à 34 : si la fin du flux d'entrée (fin du clavier) est détectée, on écrit un "."
sur le flux de sortie puis on attend 0.1 seconde ;
Ligne 36 : dans les autres cas, on écrit le caractère c dans le flux de sortie standard
*/

/* QUESTION 3 d */

/*  Situation : 4 curseurs en même temps */
/*
Le premier écrivain écrit aaaa puis bbbb
Le deuxième écrit cccc puis dddd à la place de aaaa et bbbb
Mais le lecteur ne lit pas ce qui a été remplacé
Toutefois l'écriture du eeee se fait après le curseur de lecteur, donc on les voit
Le premier écrivain écrit par dessus le eeee (il reprend là où était son curseur)
Les lecteurs lisent alors seulement gggg
=> voir où sont les curseurs pour chaque processus, avec un dessin, voir photo 16 déc
*/

/*
Soit P1 et P2 deux processus, et f fichier régulier :
— Une lecture sur f n’est pas bloquante. Si on est en fin de fichier, le noyau renvoie une valeur
indiquant la fin de fichier.
— Si P1 et P2 écrivent dans f à la même position, la donnée de f à cette position sera celle
de la dernière écriture.
— Si P1 et P2 lisent dans f à la même position, les données lues seront les mêmes si il n’y a
pas eu d'écriture dans f à cette position entre les lectures.
— Si P1 fait une lecture et P2 une écriture dans f à la position ℓ, P1 reçoit la donnée écrite
par P2 si :
i. la lecture de P1 est faite après l’écriture de P2,
ii. il n’y a pas eu d’autre écriture entre la lecture de P1 et l’écriture de P2.
*/

/* Remarque : quand les processus sont en parallèle, 
on ne sait pas dans quel ordre s'affichent les entrées */

/* QUESTION 4 */
/* 
Voir photos 16 décembre
Tuer tous les processus écrivains : le pipe se vide, il n'y a plus d'écrivains, donc
les lecteurs affichent des points car la lecture n'est plus bloquante
On relance des écrivains et donc on affiche gggg
So on tue les lecteurs, on reçoit un SIGPIPE (l'équivalent d'un vigile au carrefour quand plus de caisse)


Une lecture f est bloquante, si f est ... et qu'il existe encore 

vide, écrivain
lecteur
En absence de lecteur, une écriture sur une f génère l'émision du signal SIGPIPE.
Si ce signal n'est ni attrapé ni ignoré, ceci entraine la terminaison/l'arrêt du processus.
Si ce signal est attrapé ou ignoré, l'écriture renvoie une  erreur et la variable
ERRNO reçoit un EPIPE
- ...
- même
- (i) vide
- (ii) lecture
- (iii) écriture
*/