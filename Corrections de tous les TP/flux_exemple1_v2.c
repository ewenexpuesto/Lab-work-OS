#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>


int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "usage: %s <path> <path>\n", argv[0]);
        exit(1);
    }

    int fdin = open(argv[1], O_RDONLY);
    if (fdin == -1) {
        perror("[open1]");
        exit(2);
    }

    int fdout = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR);
    if (fdout == -1) {
        perror("[open2]");
        exit(3);
    }

    int res;
    do {
        char buf[2];
        res = read(fdin, buf, 2);    /* buf == &buf[0] */
        if (res == -1) { perror("[read]");  exit(4); }
        if (res ==  0) break;
        if (write(fdout, buf, 1) == -1) { perror("[write]"); exit(5); }
    } while (res == 2);

    close(fdin);
    close(fdout);
    return 0;
}
