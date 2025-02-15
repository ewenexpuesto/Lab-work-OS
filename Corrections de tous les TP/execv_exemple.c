#include <stdio.h>
#include <unistd.h>

int main() {
    char* args[] = { "ls" , "-l" , "/tmp" , NULL };

    execv("/bin/ls", args);
    perror("[execv]");
    return 1;
}
