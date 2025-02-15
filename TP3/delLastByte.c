/*
 il faut lire tout le fichier puis recopier tout sauf le dernier bit
malloc est dans le man 3 car c'est du C standard

Fonctions à connaître : 
malloc puis free
open puis close
lseek puis fstat
read
write */

#include <stdio.h> /* errors */
#include <stdlib.h>

#include <unistd.h>
#include <fcntl.h> /* fonction de contrôle comme open */
#include <stdlib.h>

/*
/* I started writing a function, see the main or correction */
/*int delLastByte(const char f)
{
    int fd=open(f,0); /* what is the flag used for ? */ /* fd for file descriptor */
    /* int t=lseek(f,SEEK_END,0); /* until the end of the file */
    /* int* tab=malloc((t-1)*sizeof(int));
    for (int i=0;i<=t-1;i+=1)
    {
        void* buf;
        tab[i]=read(fd,buf,i);
    }
    int close(f);
    int fd=open(f,O_WRONLY|O_TRUNC);

    free(tab);

    return 0;
}*/

int main(int argc,char *argv[]) 
{
    if (argc!=2)
    {
        fprintf(stdin,"usage:%s <file>\n",argv[0]);
        exit(1);
    }
    int fd=open(argv[1],O_RDONLY); /* doesn't work with a file of infinite size */
    if (fd==-1)
    {
        perror("[open 1]");exit(2);
    };
    int sz=lseek(fd,SEEK_END,0);
    if (sz==-1)
    {
        perror("[lseek]");exit(3);
    };
    if (sz>0)
    {
        lseek(fd,SEEK_SET,0); /* places the cursos at the beginning of the file */
        char* lnf=malloc((sz-1)*sizeof(char)); /* warning : don't write char* */ /* malloc could fail if sz is 0, could be 2^63, using too much ram */
        if (read(fd,lnf,sz-1)!=sz-1) /* warning : the cursor must be placed accordingly */
        {
            perror("[read]");exit(4);
        };
        close(fd);
        fd=open(argv[1],O_WRONLY|O_TRUNC); /* la troncature permet d'enlever le dernier octet */
        if (write(fd,lnf,sz-1)!=sz-1)
        {
            perror("[write]");exit(5);
        };
        free(lnf);
    }
    close(fd);
}
/* on n'a pas vérifié que le nom de fichier était régulier mais ce n'est pas grave car on utilise read et open 
pour vérifier rigoureusement, il faudrait utiliser stat */