#include <stdio.h>
#include <unistd.h>

int main() {
    execl("/bin/ls", "ls", "-l", "/tmp", NULL);
    perror("[execl]");
    return 1;
}
