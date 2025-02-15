#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv) /* what type ? */
{
    if (argc==0)
    {
        fprintf(stdin,"usage:%f <argc>\n",argc);
        exit(1);
    }
    FILE* f=fopen(argv,"r");
    fread(,argv,argv,f)
}
