#include <stdio.h>
#include <unistd.h> /* allows to use execl */
#include "/pub/FISE_OSSE11/syscall/lire.c"

int main() {
    lire();
    lire();
    execl("/home/ewen.expuesto/OSSE11/TP3/lire","nom",NULL); /* ou remplacer la path par le fichier /lire.out */ /* ou utiliser $realpath./lire */
    perror("[execl]");
    return 0;
}