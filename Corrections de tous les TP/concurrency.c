#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define N 3

struct input {
    int nb;
    int* ptr;
};

struct output {
    int before;
    int after;
};

void* f(void* args) {
    struct input*  in  = args;
    struct output* out = malloc(sizeof(struct output));
    out->before = *(in->ptr);
    printf("I am thread number %d.\n", in->nb);
    out->after  = out->before + in->nb;
    *(in->ptr)  = out->after;
    return out;
}


int main() {
    int value = 0;
    pthread_t th[N];
    struct input args[N];

    for (int i=0; i<N; ++i) {
        args[i].nb  = (i+1);
        args[i].ptr = &value;
        pthread_create(&th[i], NULL, f, &args[i]);
    }

    for (int i=0; i<N; ++i) {
        struct output* res;
        pthread_join(th[i], (void**)&res);
        printf("%d: %d -> %d\n", i+1, res->before, res->after);
        free(res);
    }

    printf("value = %d\n", value);
    return 0;
}
