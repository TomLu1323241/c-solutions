

/*
Author: Priyanka Jain
Purpose: Output a user friendly program that converts 3 different number systems
Status: In Progress
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Purpose: a function that returns the answer of a power
// Parameters: base - the base of the power
//             exponent - the exponent of the power
// Returns: the value of (base ^ exponent)
int power(int base, int exponent) {
  int answer = 1;
  int index;
  for (index = 0; index < exponent; index++) {
    answer *= base;  // same as answer = answer * base
  }
  return answer;
}

int main() {
  bool playing = true;

  char initialValue[33];
  int inputLength = 0;
  bool isBinary = false;
  bool isDecimal = false;
  bool isHexaDecimal = false;
  char convertion;

  // welcome statement
  printf("Welcome to the World's Greatest Bihex Converter! ");

  while (playing) {
    // reset variables
    int c;
    inputLength = 0;
    isBinary = false;
    isDecimal = false;
    isHexaDecimal = false;
    bool allCorrect = true;
    // asking user to input number
    printf("\nPlease input a binary, decimal or hexadecimal value: ");
    scanf("%[^\n]s", initialValue);
    fgetc(stdin);
    // get length
    int temp = 0;
    while (initialValue[temp] != 0) {
      temp++;
    }
    inputLength = temp;

    // check if start with 0x as that is a hex
    if (initialValue[0] == '0' && initialValue[1] == 'x') {
      isHexaDecimal = true;
      for (int i = 2; i < inputLength; i++) {
        initialValue[i - 2] = initialValue[i];
      }
      inputLength -= 2;
    }

    // check if all chars are 0 and 1, if so, it is binary
    if (!isDecimal && !isHexaDecimal) {
      for (int i = 0; i < inputLength; i++) {
        if (!(initialValue[i] == '0' || initialValue[i] == '1')) {
          allCorrect = false;
        }
      }
      isBinary = allCorrect;
    }

    // check if all chars are 0-9, if so, it is decimal
    if (!isBinary && !isHexaDecimal) {
      allCorrect = true;
      for (int i = 0; i < inputLength; i++) {
        if (!(initialValue[i] == '0' || initialValue[i] == '1' ||
              initialValue[i] == '2' || initialValue[i] == '3' ||
              initialValue[i] == '4' || initialValue[i] == '5' ||
              initialValue[i] == '6' || initialValue[i] == '7' ||
              initialValue[i] == '8' || initialValue[i] == '9')) {
          allCorrect = false;
        }
      }
      isDecimal = allCorrect;
    }

    // check if all chars are 0-9 and a-f, if so, it is hex
    if (!isBinary && !isDecimal) {
      allCorrect = true;
      for (int i = 0; i < inputLength; i++) {
        if (!(initialValue[i] == '0' || initialValue[i] == '1' ||
              initialValue[i] == '2' || initialValue[i] == '3' ||
              initialValue[i] == '4' || initialValue[i] == '5' ||
              initialValue[i] == '6' || initialValue[i] == '7' ||
              initialValue[i] == '8' || initialValue[i] == '9' ||
              initialValue[i] == 'A' || initialValue[i] == 'a' ||
              initialValue[i] == 'B' || initialValue[i] == 'b' ||
              initialValue[i] == 'C' || initialValue[i] == 'c' ||
              initialValue[i] == 'D' || initialValue[i] == 'd' ||
              initialValue[i] == 'E' || initialValue[i] == 'e' ||
              initialValue[i] == 'F' || initialValue[i] == 'f')) {
          allCorrect = false;
        }
      }
      isHexaDecimal = allCorrect;
    }

    // leave the game if they enter 0
    if (initialValue[0] == '0' && inputLength == 1) {
      break;
    }

    // try again on number input if not any type of number
    if (!isBinary && !isDecimal && !isHexaDecimal) {
      printf("\nYou did not enter a valid number");
      continue;
    }
    bool validOption = false;

    // check if they entered b,h or d
    while (!validOption) {
      printf(
          "\nWhat format do you want to convert to? ('b' = binary, 'h' = "
          "hexadecimal, 'd' = decimal): ");
      scanf("%c", &convertion);
      fgetc(stdin);
      if (convertion == 'b' || convertion == 'h' || convertion == 'd' ||
          convertion == 'B' || convertion == 'H' || convertion == 'D') {
        validOption = true;
      }
    }

    // binary convertion
    if (isBinary) {
      if (convertion == 'b' || convertion == 'B') {
        // print out what we got
        for (int i = 0; i < inputLength; i++) {
          printf("%c", initialValue[i]);
        }
        printf("\n");
      } else if (convertion == 'd' || convertion == 'D') {
        // convert binary to decimal
        int result = 0;
        int exp;
        for (int i = 0; i < inputLength; i++) {
          // if its is 1, then add 2^(position in the number)
          if (initialValue[i] == '1') {
            exp = inputLength - 1 - i;
            result = result + power(2, exp);
          }
        }
        printf("The convertion results is %d", result);
      } else if (convertion == 'h' || convertion == 'H') {
        // convert binary to hex

        // shift things until they are in group of 4
        if (inputLength % 4 != 0) {
          int shift = 4 - inputLength % 4;
          for (int i = inputLength - 1; i >= 0; i--) {
            initialValue[i + shift] = initialValue[i];
          }
          for (int i = 0; i < shift; i++) {
            initialValue[i] = '0';
          }
        }

        char result[10];
        int hexCounter = 0;
        // check in group of 4 and convert them to 0-f
        for (int i = 0; i < inputLength; i = i + 4) {
          if (initialValue[i] == '0' && initialValue[i + 1] == '0' &&
              initialValue[i + 2] == '0' && initialValue[i + 3] == '0') {
            result[hexCounter] = '0';
          } else if (initialValue[i] == '0' && initialValue[i + 1] == '0' &&
                     initialValue[i + 2] == '0' && initialValue[i + 3] == '1') {
            result[hexCounter] = '1';
          } else if (initialValue[i] == '0' && initialValue[i + 1] == '0' &&
                     initialValue[i + 2] == '1' && initialValue[i + 3] == '0') {
            result[hexCounter] = '2';
          } else if (initialValue[i] == '0' && initialValue[i + 1] == '0' &&
                     initialValue[i + 2] == '1' && initialValue[i + 3] == '1') {
            result[hexCounter] = '3';
          } else if (initialValue[i] == '0' && initialValue[i + 1] == '1' &&
                     initialValue[i + 2] == '0' && initialValue[i + 3] == '0') {
            result[hexCounter] = '4';
          } else if (initialValue[i] == '0' && initialValue[i + 1] == '1' &&
                     initialValue[i + 2] == '0' && initialValue[i + 3] == '1') {
            result[hexCounter] = '5';
          } else if (initialValue[i] == '0' && initialValue[i + 1] == '1' &&
                     initialValue[i + 2] == '1' && initialValue[i + 3] == '0') {
            result[hexCounter] = '6';
          } else if (initialValue[i] == '0' && initialValue[i + 1] == '1' &&
                     initialValue[i + 2] == '1' && initialValue[i + 3] == '1') {
            result[hexCounter] = '7';
          } else if (initialValue[i] == '1' && initialValue[i + 1] == '0' &&
                     initialValue[i + 2] == '0' && initialValue[i + 3] == '0') {
            result[hexCounter] = '8';
          } else if (initialValue[i] == '1' && initialValue[i + 1] == '0' &&
                     initialValue[i + 2] == '0' && initialValue[i + 3] == '1') {
            result[hexCounter] = '9';
          } else if (initialValue[i] == '1' && initialValue[i + 1] == '0' &&
                     initialValue[i + 2] == '1' && initialValue[i + 3] == '0') {
            result[hexCounter] = 'a';
          } else if (initialValue[i] == '1' && initialValue[i + 1] == '0' &&
                     initialValue[i + 2] == '1' && initialValue[i + 3] == '1') {
            result[hexCounter] = 'b';
          } else if (initialValue[i] == '1' && initialValue[i + 1] == '1' &&
                     initialValue[i + 2] == '0' && initialValue[i + 3] == '0') {
            result[hexCounter] = 'c';
          } else if (initialValue[i] == '1' && initialValue[i + 1] == '1' &&
                     initialValue[i + 2] == '0' && initialValue[i + 3] == '1') {
            result[hexCounter] = 'd';
          } else if (initialValue[i] == '1' && initialValue[i + 1] == '1' &&
                     initialValue[i + 2] == '1' && initialValue[i + 3] == '0') {
            result[hexCounter] = 'e';
          } else if (initialValue[i] == '1' && initialValue[i + 1] == '1' &&
                     initialValue[i + 2] == '1' && initialValue[i + 3] == '1') {
            result[hexCounter] = 'f';
          }
          hexCounter++;
        }
        printf("The convertion results is ");
        for (int i = 0; i < hexCounter; i++) {
          printf("%c", result[i]);
        }
      }
    } else if (isDecimal) {
      if (convertion == 'b' || convertion == 'B') {
        // decimal to binary
        // get char array into actual int
        int intValue = 0;
        for (int i = 0; i < inputLength; i++) {
          intValue += (initialValue[i] - 48) * power(10, inputLength - 1 - i);
        }

        // figure out max power
        int maxPow2 = 0;
        for (int i = 0; i < 32; i++) {
          if (power(2, i) > intValue) {
            break;
          }
          maxPow2 = i;
        }
        char binaryResult[32];
        int pos = 0;
        // subtract 2^i until we reach 0
        for (int i = maxPow2; i >= 0; i--) {
          if (power(2, i) <= intValue) {
            binaryResult[pos] = '1';
            intValue -= power(2, i);  // intValue = intValue - power(2, i);
          } else {
            binaryResult[pos] = '0';
          }
          pos++;
        }
        for (int i = 0; i < pos; i++) {
          printf("%c", binaryResult[i]);
        }
      } else if (convertion == 'd' || convertion == 'D') {
        // print out what we got
        for (int i = 0; i < inputLength; i++) {
          printf("%c", initialValue[i]);
        }
        printf("\n");
      } else if (convertion == 'h' || convertion == 'H') {
        // convert decimal to hex
        // get char array into actual int
        int intValue = 0;
        for (int i = 0; i < inputLength; i++) {
          intValue += (initialValue[i] - 48) * power(10, inputLength - 1 - i);
        }

        // figure out max power
        int maxPow16 = 0;
        for (int i = 0; i < 32; i++) {
          if (power(16, i) > intValue) {
            break;
          }
          maxPow16 = i;
        }

        // divide 16^i until we reach 0
        char hexResult[32];
        int pos = 0;
        for (int i = maxPow16; i >= 0; i--) {
          if (power(16, i) <= intValue) {
            int toAdd = intValue / power(16, i);
            intValue = intValue % power(16, i);
            // convert num to char
            if (toAdd <= 9) {
              hexResult[pos] = toAdd + 48;
            } else {
              hexResult[pos] = toAdd + 55;
            }
          } else {
            hexResult[pos] = '0';
          }
          pos++;
        }
        for (int i = 0; i < pos; i++) {
          printf("%c", hexResult[i]);
        }
      }
    } else if (isHexaDecimal) {
      if (convertion == 'b' || convertion == 'B') {
        // convert hex to binary
        // depending on which 0-f, print sets of 4 of binary
        for (int i = 0; i < inputLength; i++) {
          if (initialValue[i] == '0') {
            printf("0000");
          } else if (initialValue[i] == '1') {
            printf("0001");
          } else if (initialValue[i] == '2') {
            printf("0010");
          } else if (initialValue[i] == '3') {
            printf("0011");
          } else if (initialValue[i] == '4') {
            printf("0100");
          } else if (initialValue[i] == '5') {
            printf("0101");
          } else if (initialValue[i] == '6') {
            printf("0110");
          } else if (initialValue[i] == '7') {
            printf("0111");
          } else if (initialValue[i] == '8') {
            printf("1000");
          } else if (initialValue[i] == '9') {
            printf("1001");
          } else if (initialValue[i] == 'a') {
            printf("1010");
          } else if (initialValue[i] == 'b') {
            printf("1011");
          } else if (initialValue[i] == 'c') {
            printf("1100");
          } else if (initialValue[i] == 'd') {
            printf("1101");
          } else if (initialValue[i] == 'e') {
            printf("1110");
          } else if (initialValue[i] == 'f') {
            printf("1111");
          }
        }
      } else if (convertion == 'd' || convertion == 'D') {
        // hex to decimal
        int result = 0;
        int exp;
        for (int i = 0; i < inputLength; i++) {
          // get base 10 of hex value
          int value = 0;
          if (48 <= initialValue[i] && initialValue[i] <= 57) {
            value = initialValue[i] - 48;
          } else if (65 <= initialValue[i] && initialValue[i] <= 70) {
            value = initialValue[i] - 55;
          } else if (97 <= initialValue[i] && initialValue[i] <= 102) {
            value = initialValue[i] - 87;
          }
          // calculate exponent at current position
          exp = inputLength - 1 - i;
          // add it to the result
          result += power(16, exp) * value;
        }
        printf("The convertion results is d to h %d", result);
      } else if (convertion == 'h' || convertion == 'H') {
        // print out what we got
        for (int i = 0; i < inputLength; i++) {
          printf("%c", initialValue[i]);
        }
        printf("\n");
      }
    }
  }

  // thank you statement
  printf("\nThank you for using the Bihex Converter! ");

  return 0;
}
