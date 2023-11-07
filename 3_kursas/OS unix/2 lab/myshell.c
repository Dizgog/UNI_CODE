#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 256

// Function to trim leading and trailing whitespace from a string
char* trim_whitespace(char* str) {
    char* end;

    // Trim leading whitespace
    while (isspace((unsigned char)*str)) {
        str++;
    }

    if (*str == 0) {
        return str; // All whitespace
    }

    // Trim trailing whitespace
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) {
        end--;
    }

    // Null-terminate the trimmed string
    end[1] = '\0';

    return str;
}

// Function to split input into commands separated by pipes
char** depipe(char* input) {
    char** commands = (char**)malloc(256 * sizeof(char*));

    for (int i = 0; i < 256; i++) {
        commands[i] = (char*)malloc(256);
    }
    printf("hello?2\n");
    int index = 0;
    char* token = strtok(input, "|\n");
    printf("hello?3\n");
    while (token != NULL) {
      printf("hello?4\n");
        char* trimmed_token = trim_whitespace(token);
        strcpy(commands[index], trimmed_token);
        //strcpy(commands[index], token);
        index++;
        printf("%s\n", commands[index]);
        token = strtok(NULL, "|\n");
    }
    commands[index] = NULL;

    return commands;
}

// Function to execute a command with arguments and handle input/output redirection
char* excecuteCommand(char* command, char* args[], int inputfd, int outputfd) {
    pid_t pid = fork();
    if (pid == 0) {
        if (inputfd != STDIN_FILENO) {
          printf("input");
            dup2(inputfd, STDIN_FILENO); // Redirect stdin to the input file descriptor
            close(inputfd);
        }

        if (outputfd != STDOUT_FILENO) {
            dup2(, STDOUT_FILENO); // Redirect stdout to the output file descriptor
            close(outputfd);
            printf("output");
        }

        execvp(command, args);
        printf("Command not found\n");
        exit(1);
    } else {
        wait(NULL);
    }
    return 0;
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
void handle_command(char* input) {
  printf("hello1\n");
    char** commands = depipe(input);

    int pipefd[2];
    int inputfd = STDIN_FILENO;

    // for (int i = 0; i < sizeof(commands); i++) {
    //     if (commands[i] == NULL) break;

    //     if (pipe(pipefd) == -1) {
    //         printf("Pipe failed");
    //         return;
    //     }
    for (int i = 0; commands[i] != NULL; i++) {
    if (pipe(pipefd) == -1) {
        printf("Pipe failed");
        return;
    }
        printf("%s\n", commands[i]);
        char** args = separateArgs(commands[i]);
        excecuteCommand(args[0], args, inputfd, pipefd[1]);

        // Free args
        for (int i = 0; i < MAX_COMMAND_LENGTH; i++)
            free(args[i]);
        free(args);

        // Close pipe
        close(pipefd[1]);
        if (inputfd != STDIN_FILENO) {
            close(inputfd);
        }
        inputfd = pipefd[0];
    }

    // Print output
    char buf;
    while (read(inputfd, &buf, 1) > 0)
        write(STDOUT_FILENO, &buf, 1);
    close(inputfd);  // Close read

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
        
        // Handle the command
        handle_command(command);
         //       for(int i = 0; i < 256; i++)
       //     free(command[i]);
        //free(command);
    }

    return 0;
}
