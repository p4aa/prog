//Below is a C program demonstrating full-duplex communication between parent and child processes using pipes:
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    int pipefd1[2], pipefd2[2];
    pid_t pid;
    char pathname[BUFFER_SIZE];
    char file_contents[BUFFER_SIZE];

    if (pipe(pipefd1) == -1 || pipe(pipefd2) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // Child process
        close(pipefd1[1]); // Close write end of pipe 1
        close(pipefd2[0]); // Close read end of pipe 2

        read(pipefd1[0], pathname, BUFFER_SIZE);
        FILE *file = fopen(pathname, "r");
        if (file == NULL) {
            perror("fopen");
            exit(EXIT_FAILURE);
        }
        fread(file_contents, sizeof(char), BUFFER_SIZE, file);
        fclose(file);

        write(pipefd2[1], file_contents, strlen(file_contents) + 1);
        close(pipefd1[0]);
        close(pipefd2[1]);
        exit(EXIT_SUCCESS);
    } else { // Parent process
        close(pipefd1[0]); // Close read end of pipe 1
        close(pipefd2[1]); // Close write end of pipe 2

        printf("Enter the pathname of the file: ");
        scanf("%s", pathname);

        write(pipefd1[1], pathname, strlen(pathname) + 1);
        wait(NULL); // Wait for the child process to complete

        read(pipefd2[0], file_contents, BUFFER_SIZE);
        printf("Contents of the file received from child process:\n%s\n", file_contents);

        close(pipefd1[1]);
        close(pipefd2[0]);
    }

    return 0;
}
