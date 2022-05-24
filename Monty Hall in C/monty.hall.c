#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// gcc monty.hall.c -o test.exe

int main() {
  srand(time(NULL));
  // stats for original
  int stayedWithOriginal = 0;
  int wonWithOrigianal = 0;
  // stats for switching
  int switched = 0;
  int wonWithSwitch = 0;
  // round counter;
  int roundCounter = 0;

  while (1) {
    // int rightDoor = 2;
    int rightDoor = rand() % 3 + 1;
    int choice = -1;
    int switchDoor = -1;

    printf("Which door, 1-3 will you choose? HINT ITS: %d\n", rightDoor);
    printf("Enter '0' to quit the game \n");
    int valideChoice = 1;
    while (valideChoice) {
      scanf("%d", &choice);
      switch (choice) {
        case 0:;
          goto quit;
          break;
        case 1:;
          switch (rightDoor) {
            case 1:;
              int arr[] = {2, 3};
              int openDoor = arr[rand() % 2];
              printf("It is not in door %d \n", openDoor);
              switchDoor = openDoor;
              break;
            case 2:;
              printf("It is not in door 3 \n");
              switchDoor = 2;
              break;
            case 3:;
              printf("It is not in door 2 \n");
              switchDoor = 3;
              break;
          }
          valideChoice = 0;
          break;
        case 2:;
          switch (rightDoor) {
            case 1:;
              printf("It is not in door 3 \n");
              switchDoor = 1;
              break;
            case 2:;
              int arr[] = {1, 3};
              int openDoor = arr[rand() % 2];
              printf("It is not in door %d \n", openDoor);
              switchDoor = openDoor;
              break;
            case 3:;
              printf("It is not in door 1 \n");
              switchDoor = 3;
              break;
          }
          valideChoice = 0;
          break;
        case 3:;
          switch (rightDoor) {
            case 1:;
              printf("It is not in door 2 \n");
              switchDoor = 1;
              break;
            case 2:;
              printf("It is not in door 1 \n");
              switchDoor = 2;
              break;
            case 3:;
              int arr[] = {1, 2};
              int openDoor = arr[rand() % 2];
              printf("It is not in door %d \n", openDoor);
              switchDoor = openDoor;
              break;
          }
          valideChoice = 0;
          break;
        default:
          printf("Invalid Option please try again!");
          break;
      }
    }

    char switchChar;
    printf("Would you like to switch to %d \n", switchDoor);
    valideChoice = 1;
    while (valideChoice) {
      scanf(" %c", &switchChar);
      switch (switchChar) {
        case 'y':
          choice = switchDoor;
          switched++;
          valideChoice = 0;
          break;
        case 'n':
          valideChoice = 0;
          stayedWithOriginal++;
          break;
        default:
          printf("Invalid Option please try again!");
          break;
      }
    }
    if (choice == rightDoor) {
      switch (switchChar) {
        case 'y':
          wonWithSwitch++;
          break;
        case 'n':
          wonWithOrigianal++;
          break;
      }
      printf("you did it \n");
    } else {
      printf("you failed :P \n");
    }
    roundCounter++;
  }

quit:
  printf("Final stats are: \n");
  printf("you stayed with original: %d \n", stayedWithOriginal);
  printf("you won with original: %d \n", wonWithOrigianal);
  printf("you winrate with original is : %0.2f \n",
         (float)wonWithOrigianal / (float)roundCounter);
  printf("you stayed with switched: %d \n", switched);
  printf("you won with switched: %d \n", wonWithSwitch);
  printf("you winrate with switched is : %0.2f \n",
         (float)wonWithSwitch / (float)roundCounter);
  return (0);
}
