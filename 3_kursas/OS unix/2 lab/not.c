#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

char* getInput(){
  printf(">>> ");

  char *input;
  size_t bufsize = 256;

  input = (char *)malloc(bufsize * sizeof(char));
  if( input == NULL)
  {
      printf("Unable to allocate buffer");
      exit(1);
  }

  getline(&input,&bufsize,stdin);
  return input;
}

// Returns a list of commands. Last command is NULL. No pipes
char** depipe(char* input){
  char** commands = (char**)malloc(256*256);
  for(int i = 0; i < 256; i++){
    commands[i] = (char*)malloc(256);
  }
  int k = 0;
  int index = 0;
  for(int i = 0; i < strlen(input); i++){
    if(input[i] == '\n'){
      break;
    }
    if(input[i] == '|' || input[i] == '\0'){
      if(commands[index][k-1]==' '){
        commands[index][k-1] = '\0';
      }
      else{
        commands[index][k] = '\0';
      }
      index++;
      k = 0;
    }
    else{
      if(input[i] == ' ' && k == 0)continue;
      commands[index][k] = input[i];
      k++;
    }
  }
  if(commands[index][k-1]==' '){
    commands[index][k-1] = '\0';
  }
  else{
    commands[index][k] = '\0';
  }
  index++;
  commands[index] = NULL;
  return commands;
}

// Returns a list of command arguments. First argument is the command itself, last is NULL. No spaces
char** separateArgs(char * commandLine){
  char** args = (char**)malloc(256*256);
  for(int i = 0; i < 256; i++){
    args[i] = (char*)malloc(256);
  }
  int k = 0;
  int index = 0;
  bool openQuotes = false;
  for(int i = 0; i < strlen(commandLine); i++){
    if(commandLine[i] == '"' || commandLine[i] == '\''){
      openQuotes = !openQuotes;
      continue;
    }
    if((!openQuotes && commandLine[i] == ' ') || commandLine[i] == '\0'){
      args[index][k] = '\0';
      index++;
      k = 0;
    }
    else{
      args[index][k] = commandLine[i];
      k++;
    }
  }
  args[index][k] = '\0';
  index++;
  args[index] = NULL;
  return args;
}


char* excecuteCommand(char* command, char* args[], int inputfd, int outputfd){
  pid_t pid = fork();
printf("%s, %s, %s\n", args[0], args[1], args[2]);
  if(pid == 0){
    if (inputfd != STDIN_FILENO) {
        dup2(inputfd, STDIN_FILENO); // Redirect stdin to the input file descriptor
        close(inputfd);
    }

    if (outputfd != STDOUT_FILENO) {
        dup2(outputfd, STDOUT_FILENO); // Redirect stdout to the output file descriptor
        close(outputfd);
    }
    execvp(command, args);
    printf("Command not found");
    exit(1);
  }
  else{
    wait(NULL);
  }
}

void handleCommands(char* input){
  //1. Separate pipes
  //2. Chain commands
  //3. Give result
  char** commands = depipe(input);
  //printf("\n %s\n", commands[1]);
  int pipefd[2];
  int inputfd = STDIN_FILENO;

  for(int i = 0; i < sizeof(commands); i++){
    if(commands[i] == NULL)break;

    // Initialize pipe
    if(pipe(pipefd) == -1){
      printf("Pipe failed");
      return;
    }

    char** args = separateArgs(commands[i]);
    excecuteCommand(args[0], args, inputfd, pipefd[1]);

    // Free args
    for(int i = 0; i < 256; i++)
      free(args[i]);
    free(args);

    //Close pipe
    close(pipefd[1]);
    if (inputfd != STDIN_FILENO) {
        close(inputfd);
    }
    inputfd = pipefd[0];
  }

  // Print output
  char * buf;
  while (read(inputfd, &buf, 1) > 0)
      write(STDOUT_FILENO, &buf, 1);
  close(inputfd);  // Close read

  // Free commands
  for(int i = 0; i < 256; i++)
    free(commands[i]);
  free(commands);
}

int main(int argc, char** argv){
  char* input;
  while(1){
    input = getInput();
    // if input is empty, continue
    if(input[0] == '\n')continue;
    
    // If command is exit or we get EOF, terminate
    if(strcmp(input, "exit\n") == 0 || feof(stdin)){
      printf("Exiting shell");
      break;
    }

    handleCommands(input);
    //Clean up input for next loop
    memset(input, 0, 256);
    free(input);
  }
  
  return 0;
}