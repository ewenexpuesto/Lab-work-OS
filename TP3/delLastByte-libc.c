#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
    if (argc!=2)
    {
        fprintf(stdin,"usage:%s <file>\n",argv[0]);
        exit(1);
    }
    FILE* f=fopen(argv[1],"r"); /* here */
    if (f==NULL) /* here */
    {
        perror("[fopen 1]");exit(2);
    };
    fseek(f,SEEK_END,0); /* doesn't return anything because of Microsoft */
    int sz=ftell(f); /* thus we have to compute the size here */
    if (sz==-1)
    {
        perror("[fstat]");exit(3);
    };
    if (sz>0)
    {
        fseek(f,SEEK_SET,0); /* here */
        char* lnf=malloc((sz-1)*sizeof(char));
        if (fread(f,sizeof(char),sz-1,f)!=sz-1) /* here */
        {
            perror("[fread]");exit(4);
        };
        fclose(f);
        f=fopen(argv[1],"w");
        if (fwrite(lnf,sizeof(char),sz-1,f)!=sz-1)
        {
            perror("[write]");exit(5);
        };
        free(lnf);
    }
    close(f);
}