#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// gcc testing.c -o testing.exe

int main() {
  int cond = 1;
  int userInput = -1;
  while (cond) {
    printf("you are in the loop, please input a number \n");
    scanf(" %d", &userInput);
    if (userInput == 1) {
      cond = 0;
    } else if (userInput == 2) {
      cond = 0;
    } else if (userInput == 3) {
      cond = 0;
    } else {
      printf("That is not a valid number. \n");
    }
  }
  printf("you got out of the loop. \n");
}