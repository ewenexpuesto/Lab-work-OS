#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "usage: %s <path> <path>\n", argv[0]);
        exit(1);
    }

    FILE* fin = fopen(argv[1], "r");
    if (fin == NULL) {
        perror("[fopen1]");
        exit(2);
    }

    FILE* fout = fopen(argv[2], "w");
    if (fout == NULL) {
        perror("[fopen2]");
        exit(3);
    }

    while (!feof(fin)) {
        char buf[2];
        int res = fread(buf, sizeof(char), 2, fin);
        if (res > 0) {
            fwrite(buf, sizeof(char), 1, fout);
        }
    }

    fclose(fin);
    fclose(fout);
    return 0;
}
