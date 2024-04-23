//FIFOs: Full duplex communication between two independent processes. First process accepts
// sentences and writes on one pipe to be read by second process and second process counts
// number of characters, number of words and number of lines in accepted sentences, writes this
// output in a text file and writes the contents of the file on second pipe to be read by first process
// and displays on standard output.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define FIFO_FILE "communication_fifo"

void count_characters_words_lines(char *text, int *char_count, int *word_count, int *line_count) {
    *char_count = strlen(text);
    *word_count = 0;
    *line_count = 0;

    char *token = strtok(text, " \n");
    while (token != NULL) {
        (*word_count)++;
        token = strtok(NULL, " \n");
    }

    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == '\n')
            (*line_count)++;
    }
    (*line_count)++;
}

int main() {
    mkfifo(FIFO_FILE, 0666);

    pid_t pid;
    char sentence[BUFFER_SIZE];
    char output[BUFFER_SIZE];
    int char_count, word_count, line_count;

    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // Child process
        int fd = open(FIFO_FILE, O_RDONLY);
        if (fd == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }

        read(fd, sentence, BUFFER_SIZE);
        close(fd);

        count_characters_words_lines(sentence, &char_count, &word_count, &line_count);
        sprintf(output, "Character count: %d\nWord count: %d\nLine count: %d\n", char_count, word_count, line_count);

        fd = open(FIFO_FILE, O_WRONLY);
        if (fd == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }

        write(fd, output, strlen(output) + 1);
        close(fd);
        exit(EXIT_SUCCESS);
    } else { // Parent process
        int fd = open(FIFO_FILE, O_WRONLY);
        if (fd == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }

        printf("Enter a sentence: ");
        fgets(sentence, BUFFER_SIZE, stdin);

        write(fd, sentence, strlen(sentence) + 1);
        close(fd);

        fd = open(FIFO_FILE, O_RDONLY);
        if (fd == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }

        read(fd, output, BUFFER_SIZE);
        printf("Output from child process:\n%s\n", output);
        close(fd);

        unlink(FIFO_FILE);
    }

    return 0;
}
