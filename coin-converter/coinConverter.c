#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define _SET_ECHO_

const int addChangeChoice = 1;
const int makeChangeChoice = 2;
const int quitChoice = 3;

// multiplies two ints
int multiplyInt(int a, int b) {
  int result = 0;
  // multiplying is just adding a to itself b amount of times
  for (int i = 0; i < b; i++) {
    result += a;
  }
  return result;
}

// multiplies a double with an int
double multiplyDouble(double a, int b) {
  double result = 0;
  // multiplying is just adding a to itself b amount of times
  for (int i = 0; i < b; i++) {
    result += a;
  }
  return result;
}

// divides two ints and truncates the result
int divide(int a, int b) {
  int result = 0;
  // count how many times we can subtract the a from b
  while (a >= b) {
    a -= b;
    result++;
  }
  return result;
}

// gets the remainder
int mod(int a, int b) {
  // keep subtracting while a is bigger or equal to b
  while (a >= b) {
    a -= b;
  }
  // return what is left
  return a;
}

// Purpose: a function that returns the answer of a power
// Parameters: base - the base of the power
//             exponent - the exponent of the power
// Returns: the value of (base ^ exponent)
int power(int base, int exponent) {
  int answer = 1;
  int index;
  for (index = 0; index < exponent; index++) {
    answer = multiplyInt(answer, base);  // same as answer = answer * base
  }
  return answer;
}

void printChoices() {
  printf("(1) Add up change\n(2) Make change\n(3) Quit\n");
}

int getChoice() {
  int input;
  scanf("%d", &input);
  fgetc(stdin);
  return input;
}

double addChange() {
  // result that we keep adding to
  double result = 0;
  int input;
  // Pennies
  printf("Pennies: ");
  scanf("%d", &input);
  fgetc(stdin);
  result += multiplyDouble(0.01, input);
  // Nickels
  printf("Nickels: ");
  scanf("%d", &input);
  fgetc(stdin);
  result += multiplyDouble(0.05, input);
  // Dimes
  printf("Dimes: ");
  scanf("%d", &input);
  fgetc(stdin);
  result += multiplyDouble(0.10, input);
  // Quarters
  printf("Quarters: ");
  scanf("%d", &input);
  fgetc(stdin);
  result += multiplyDouble(0.25, input);
  // Loonies
  printf("Loonies: ");
  scanf("%d", &input);
  fgetc(stdin);
  result += multiplyDouble(1.00, input);
  // Toonies
  printf("Toonies: ");
  scanf("%d", &input);
  fgetc(stdin);
  result += multiplyDouble(2.00, input);

  return result;
}

double getDollarValue() {
  printf("Please enter the amount to make change for: $");
  double doubleValue = 0;
  scanf("%lf", &doubleValue);
  return doubleValue;
}

void makeChange(double centValue) {
  // cast to int so we can use our divide and mod functions
  int centsAsInt = (int)(centValue);
  // keep dividing and modding starting from the largest value
  int toonies = divide(centsAsInt, 200);
  centsAsInt = mod(centsAsInt, 200);
  int loonie = divide(centsAsInt, 100);
  centsAsInt = mod(centsAsInt, 100);
  int quarter = divide(centsAsInt, 25);
  centsAsInt = mod(centsAsInt, 25);
  int dime = divide(centsAsInt, 10);
  centsAsInt = mod(centsAsInt, 10);
  int nickel = divide(centsAsInt, 5);
  centsAsInt = mod(centsAsInt, 5);
  int penny = centsAsInt;

  // only print if it is not equal to zero
  printf("Your change is ");
  if (toonies != 0) {
    printf("%d toonie(s),", toonies);
  }
  if (loonie != 0) {
    printf("%d loonie(s),", loonie);
  }
  if (quarter != 0) {
    printf("%d quarter(s),", quarter);
  }
  if (dime != 0) {
    printf("%d dime(s),", dime);
  }
  if (nickel != 0) {
    printf("%d nickel(s),", nickel);
  }
  if (penny != 0) {
    printf("%d penny(s),", penny);
  }
  printf("\n");
}

int main() {
  int menuChoice;
  double dollarValue;

  /*  DO NOT MODIFY THE SOURCE AFTER THIS COMMENT WITHOUT APPROVAL.  */
  _SET_ECHO_
  printf("Welcome to the Changing Coins program!\n");

  printChoices();
  menuChoice = getChoice();
  while (menuChoice != quitChoice) {
    if (menuChoice == addChangeChoice) {
      dollarValue = addChange();
      printf("\nYou have a total of $%1.2lf.\n", dollarValue);
    } else if (menuChoice == makeChangeChoice) {
      dollarValue = getDollarValue();
      makeChange(dollarValue * 100);
    } else {
      printf("INTERNAL ERROR: Unknown choice %d.\n", menuChoice);
    }

    printf("\n");
    printChoices();
    menuChoice = getChoice();
  }

  printf("Thank-you for using the Changing Coins program!\n");
  return 0;
}
