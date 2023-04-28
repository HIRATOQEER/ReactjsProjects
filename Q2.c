#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int in_fd, out_fd, n;
    char buf[BUFSIZE];

    if (argc != 2) {
        printf("Usage: %s inputfile\n", argv[0]);
        exit(1);
    }

    // Open the input file for reading
    in_fd = open(argv[1], O_RDONLY);
    if (in_fd == -1) {
        perror("open");
        exit(1);
    }

    // Open the output file for writing, create if it doesn't exist, and set the file permissions
    out_fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (out_fd == -1) {
        perror("open");
        exit(1);
    }

    // Redirect standard input to the input file descriptor
    if (dup2(in_fd, STDIN_FILENO) == -1) {
        perror("dup2");
        exit(1);
    }

    // Redirect standard output to the output file descriptor
    if (dup2(out_fd, STDOUT_FILENO) == -1) {
        perror("dup2");
        exit(1);
    }

    // Read from standard input (which is redirected to the input file) and write to standard output (which is redirected to the output file)
    while ((n = read(STDIN_FILENO, buf, BUFSIZE)) > 0) {
        if (write(STDOUT_FILENO, buf, n) == -1) {
            perror("write");
            exit(1);
        }
    }

    // Close the file descriptors
    close(in_fd);
    close(out_fd);

    return 0;
}

