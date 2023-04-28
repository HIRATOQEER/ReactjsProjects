#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* thread_func(void* arg) {
    pid_t pid = getpid();
    pthread_t tid = pthread_self();
    printf("Worker thread: Process ID %d, Thread ID %lu\n", pid, tid);
    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: ./program <number of threads>\n");
        return 1;
    }

    int num_threads = atoi(argv[1]);
    pthread_t threads[num_threads];

    for (int i = 0; i < num_threads; i++) {
        if (pthread_create(&threads[i], NULL, thread_func, NULL) != 0) {
            perror("pthread_create");
            return 1;
        }
    }

    for (int i = 0; i < num_threads; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
            return 1;
        }
    }

    return 0;
}

