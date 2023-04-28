#include <stdio.h>
#include <pthread.h>

// Function to calculate the summation of integers from 0 to N
void* summation(void* arg) {
    int N = *(int*)arg;
    int sum = 0;
    for (int i = 0; i <= N; i++) {
        sum += i;
    }
    printf("Summation of integers from 0 to %d is %d\n", N, sum);
    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <integer>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);

    pthread_t thread;
    int rc = pthread_create(&thread, NULL, summation, &N);
    if (rc) {
        printf("Error creating thread; return code from pthread_create() is %d\n", rc);
        return 1;
    }

    pthread_exit(NULL);
}

