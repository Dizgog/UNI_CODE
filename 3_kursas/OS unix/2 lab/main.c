#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 256
#define MAX_ARGS 64

void execute_command(char *command) {
    char *args[MAX_ARGS];
    char *token;
    int i = 0;

    // Skaidome komandą į argumentus
    token = strtok(command, " ");
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;

    pid_t pid = fork();

    if (pid == 0) {
        // Vaiko procesas
        execvp(args[0], args);
        perror("Execvp failed");
        exit(1);
    } else if (pid > 0) {
        // Tėvo procesas
        int status;
        waitpid(pid, &status, 0);
    } else {
        perror("Fork failed");
        exit(1);
    }
}

int main() {
    char command[MAX_COMMAND_LENGTH];
    int background = 0;

    while (1) {
        printf("Įveskite komandą: ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        // Patikriname, ar komanda yra "exit" arba EOF
        if (strcmp(command, "exit\n") == 0 || feof(stdin)) {
            printf("Programa baigta.\n");
            break;
        }

        // Tikriname, ar komanda vykdoma fone
        if (command[strlen(command) - 2] == '&') {
            background = 1;
            command[strlen(command) - 2] = '\0';
        } else {
            background = 0;
        }

        // Tikriname, ar komanda turi konvejerio simbolį "|"
        char *pipe_symbol = strstr(command, "|");
        if (pipe_symbol) {
            int pipefd[2];
            if (pipe(pipefd) == -1) {
                perror("Pipe failed");
                exit(1);
            }

            char *command1 = strtok(command, "|");
            char *command2 = strtok(NULL, "|");

            pid_t pid1, pid2;

            pid1 = fork();
            if (pid1 == 0) {
                close(pipefd[0]);
                dup2(pipefd[1], STDOUT_FILENO);
                close(pipefd[1]);
                execute_command(command1);
                exit(0);
            } else if (pid1 < 0) {
                perror("Fork failed");
                exit(1);
            }

            pid2 = fork();
            if (pid2 == 0) {
                close(pipefd[1]);
                dup2(pipefd[0], STDIN_FILENO);
                close(pipefd[0]);
                execute_command(command2);
                exit(0);
            } else if (pid2 < 0) {
                perror("Fork failed");
                exit(1);
            }

            close(pipefd[0]);
            close(pipefd[1]);
            waitpid(pid1, NULL, 0);
            waitpid(pid2, NULL, 0);
        } else {
            // Jei nėra konvejerio, tiesiog vykdome komandą
            execute_command(command);
        }

        if (background) {
            // Jei komanda vykdoma fone, nesustabdome pagrindinio proceso
            background = 0;
        }
    }

    return 0;
}
