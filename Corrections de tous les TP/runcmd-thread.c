#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <assert.h>


void** alloc_mem(unsigned int size) {
    void** mem = malloc(size * sizeof(void*));
    for (unsigned int i = 0; i < size; ++i) {
        mem[i] = malloc(1ul<<20);
        assert(mem[i] != NULL);
    }
    return mem;
}

void free_mem(void** mem, unsigned int size) {
    for (unsigned int i = 0; i < size; ++i) free(mem[i]);
    free(mem);
}

void* hello(void *p __attribute__((unused))) {
    execlp("/bin/echo", "echo", "hello", NULL);
    exit(1);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usagae: %s <int>\n", argv[0]);
        exit(1);
    }

    unsigned int size = strtoul(argv[1], NULL, 10);
    void* p = alloc_mem(size);

    for (int i=0; i<1000; i++) {
        pthread_t thid;
        pthread_create(&thid, NULL, hello, NULL);
        pthread_join(thid, NULL);
    }

    free_mem(p, size);
    return 0;
}
