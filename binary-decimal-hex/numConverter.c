/*
 * C Program to Convert Binary to Hexadecimal
 */
#include <stdio.h>
#include <stdlib.h>
// gcc numConverter.c -o a.exe

void binaryToHex() {
  long int binaryval, hexadecimalval = 0, i = 1, remainder;

  printf("Enter the binary number: ");
  scanf("%ld", &binaryval);
  while (binaryval != 0) {
    remainder = binaryval % 10;
    hexadecimalval = hexadecimalval + remainder * i;
    i = i * 2;
    binaryval = binaryval / 10;
  }
  printf("Equivalent hexadecimal value: %lX", hexadecimalval);
  return;
}

void readFromTerminal() {
  int c; /* int */
  int count;
  char arr[50];
  c = getchar();
  count = 0;
  while (c != '\n' && count < 50) { /* don't go over the array size! */
    arr[count] = c;
    ++count;
    c = getchar(); /* get *another* character */
  }
  for (int i = 0; i < count; ++i) {
    printf("%c, ", arr[i]);
  }
  return;
}

int main() {
  readFromTerminal();
  readFromTerminal();
  // binaryToHex();
  return 0;
}