#include <stdio.h>
#include <stdbool.h>
FILE *fpt;
FILE *fptr;

void scoreboard(int score)
{
    int arr[11] = {0};

    fptr = fopen("leaderboard", "rb");

    arr[0] = score-1;

    printf("Your score is: %d\n", arr[0]);

    for(int i = 1; i<11; i++)
    {
        fscanf(fptr, "%d ", &arr[i]);
    }

    fclose(fptr);
    Sort(arr);
    print_board(arr);

    fpt = fopen("leaderboard","wb");

    for(int i = 10; i>0; i--)
    {
        fprintf(fpt,"%d\n", arr[i]);
    }
    fclose(fpt);
}

// Function to Sort
void Sort(int arr[])
{
    int temp = 0;
    int length = 11;
     for (int i = 0; i < length; i++) {
        for (int j = i+1; j < length; j++) {
           if(arr[i] > arr[j]) {
               temp = arr[i];
               arr[i] = arr[j];
               arr[j] = temp;
           }
        }
    }
}

void print_board(int arr[])
{
    printf("Scoreboard:\n");
    for(int i = 10; i>0; i--)
    printf("%d. %d\n", (i-11)*-1, arr[i]);
}
