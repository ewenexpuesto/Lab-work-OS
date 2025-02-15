#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main() {
    printf("h"); fflush(stdout);

    int fd = open("/tmp/fifo", O_RDONLY);
    if (fd == -1) {
        perror("[open]");
        exit(1);
    }

    char ch;
    if (read(fd, &ch, 1) == -1) {
        perror("[read]");
        exit(2);
    }

    printf("o\n");
    return 0;
}
