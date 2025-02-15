/* remplaçons désormais le lseek par appel à fstat, stat ou lstat, voir man */
/* permet de récupérer la taille et d'autres informations sur le fichier */

/* see man 2 fstat "voir aussi stat(3type)" puis aller voir man 3type stat et voir exemples*/

#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#include <sys/stat.h> /* here is the change */

int main(int argc,char *argv[])
{
    if (argc!=2)
    {
        fprintf(stdin,"usage:%s <file>\n",argv[0]);
        exit(1);
    }
    int fd=open(argv[1],O_RDONLY);
    if (fd==-1)
    {
        perror("[open 1]");exit(2);
    };
    struct stat st; /* here is the change */ 
    if (fstat(fd,&st)==-1) /* here is the change, this gives the size */
    {
        perror("[fstat]");exit(3);
    };
    off_t sz=st.st_size;
    if (sz>0)
    {
        lseek(fd,SEEK_SET,0); /* here is the change */
        char* lnf=malloc((sz-1)*sizeof(char));
        if (read(fd,lnf,sz-1)!=sz-1)
        {
            perror("[read]");exit(4);
        };
        close(fd);
        fd=open(argv[1],O_WRONLY|O_TRUNC);
        if (write(fd,lnf,sz-1)!=sz-1)
        {
            perror("[write]");exit(5);
        };
        free(lnf);
    }
    close(fd);
}