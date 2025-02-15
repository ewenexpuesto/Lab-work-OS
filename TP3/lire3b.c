/* voir schéma des flux du cours : ici on ajoute le flux in.txt en 3 */
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    int fdin=open(argv[1],O_RDONLY);
    if(fdin==-1) {perror("[open 1]"); exit(2);}
    int fdout=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,S_IRUSR|S_IWUSR);
    if (fdout==-1) {/* ... */}
    /* on duplique le clavier et l'écran*/
    int kbd=dup(0);
    int screen=dup(1); /* à ce stade on a les flux 0,1 et 2 classiques avec kbd, screen*/
    lire();
    dup2(fdin,0);
    dup2(fdout,1)
    lire();
    /* fermeture des flux */
    dup2(kbd,0); close(fdin), close(kbd); dup2(screen,1); close(fdout); close(screen);
}
/*voir schéma photos */