#include...

int mypipe[2];

void child(const char* path, int begin, int end, int nb) {
    void(mypipe[0]);
    for (i=begin, i<end, i=i+1) {
        if (write(mypipe[1],&cmt,sizeof(int))!=sizeof(int)) {
            perror("[write]");
            exit(32);
        }
    }
    exit(0);
}

int main(int argc, char* argv[]) {
    if (pipe(mypipe)==-1) {
        perror("(pipe)"):
        exit(42);
    }
    for (i=1; i<=4; i=i+1) {
        fork()
        ...
    }
    int sum=0;
    int cmt;
    close(mypipe[2]);
    for (i=1, i<=4, i+=1) {
        wait(NULL);
        if (read(pipefd[0]; &cmt, sizeof(int)!=sizeof(int))) {
            perror("read");
            exit(62);
        }
        sum+=cmt;
    }
    close(mypipe[0]);
    printf("%d\n", sum);
    return 0;
}