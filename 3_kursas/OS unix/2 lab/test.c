#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 256

// Function to trim leading and trailing whitespace from a string
char* trim_whitespace(char* str) {
    char* end;

    while (isspace((unsigned char)*str)) {
        str++;
    }

    if (*str == 0) {
        return str; // All whitespace
    }

    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) {
        end--;
    }

    end[1] = '\0';

    return str;
}

// Function to split input into commands separated by pipes
char** depipe(char* input) {
    char** commands = (char**)malloc(256 * sizeof(char*));
    for (int i = 0; i < 256; i++) {
        commands[i] = (char*)malloc(256);
    }

    int index = 0;
    char* token = strtok(input, "|\n");
    while (token != NULL) {
        char* trimmed_token = trim_whitespace(token);
        strcpy(commands[index], trimmed_token);
        index++;
        token = strtok(NULL, "|\n");
    }
    commands[index] = NULL;

    return commands;
}

// Function to execute a command with arguments and handle input/output redirection
void executeCommand(char* command, char* args[], int inputfd, int outputfd) {
    pid_t pid = fork();
    if (pid == 0) {
        if (inputfd != STDIN_FILENO) {
            dup2(inputfd, STDIN_FILENO); // Redirect stdin to the input file descriptor
            close(inputfd);
        }

        if (outputfd != STDOUT_FILENO) {
            dup2(outputfd, STDOUT_FILENO); // Redirect stdout to the output file descriptor
            close(outputfd);
        }

        execvp(command, args);
        printf("Command not found\n");
        exit(1);
    }
}

// Function to split command line into arguments
char** separateArgs(char *commandLine) {
    char** args = (char**)malloc(256 * sizeof(char*));
    for (int i = 0; i < 256; i++) {
        args[i] = (char*)malloc(256);
    }

    char* token = strtok(commandLine, " \n");
    int index = 0;

    while (token != NULL) {
        strcpy(args[index], token);
        index++;
        token = strtok(NULL, " \n");
    }

    args[index] = NULL;
    return args;
}

// Function to handle the command, including pipes and I/O redirection
void handleCommand(char* input) {
    char** commands = depipe(input);

    int pipefd[2];
    int inputfd = STDIN_FILENO;
    int last_pipefd = -1;

    for (int i = 0; commands[i] != NULL; i++) {
        if (pipe(pipefd) == -1) {
            printf("Pipe failed");
            return;
        }

        char** args = separateArgs(commands[i]);
        executeCommand(args[0], args, inputfd, pipefd[1]);

        // Close the previous pipe
        if (last_pipefd != -1) {
            close(last_pipefd);
        }
        
        // Free args
        for (int j = 0; j < 256; j++)
            free(args[j]);
        free(args);

        last_pipefd = pipefd[0];
        inputfd = pipefd[0];

        // Wait for the child process to complete
        int status;
        wait(&status);
    }

    // Print output
    char buf;
    while (read(inputfd, &buf, 1) > 0)
        write(STDOUT_FILENO, &buf, 1);
    close(inputfd);

    // Free commands
    for(int i = 0; i < 256; i++)
        free(commands[i]);
    free(commands);
}

int main() {
    char* command;
    command = (char *)malloc(256 * sizeof(char));
    if (command == NULL) {
        printf("Unable to allocate buffer");
        exit(1);
    }

    while (1) {
        printf("# ");
        if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL) {
            break;
        }

        // Check if the command is "exit"
        if (strcmp(command, "exit\n") == 0) {
            printf("Programa baigta.\n");
            break;
        }

        // Remove the newline character if it's present
        size_t command_length = strlen(command);
        if (command_length > 0 && command[command_length - 1] == '\n') {
            command[command_length - 1] = '\0'; // Remove the newline
        }

        handleCommand(command);
    }

    free(command); // Don't forget to free the command buffer
    return 0;
}

