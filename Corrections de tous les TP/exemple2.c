#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>


void child(char* path) {
    int len = strlen(path);
    if (len > 5 && strncmp(path+len-4, ".pdf", 4) == 0) {
	execl("/usr/bin/xpdf", "xpdf", path, NULL);
	perror("[execl1]");
	exit(1);
    } else if (len > 3 && strncmp(path+len-2, ".c", 2) == 0) {
	execl("/usr/bin/emacs", "xpdf", path, NULL);
	perror("[execl2]");
	exit(2);
    }
   
    fprintf(stderr, "Invalid file format\n");
    exit(3);
}

int main() {
    char path[128];

    while (!feof(stdin) && scanf("%100s", path) == 1) {

	struct stat st;
	if (stat(path, &st) == -1) {
	    fprintf(stderr, "'%s' not found\n", path);
	    continue;
	}
	if (!S_ISREG(st.st_mode)) {
	    fprintf(stderr, "'%s' is not a regular file\n", path);
	    continue;
	}

	switch (fork()) {
	    case -1:
		perror("[fork]");
		exit(4);
		break;
	    case 0:
		child(path);
		break;
	    default:
		wait(NULL);
	}
    }

    return 0;
}
