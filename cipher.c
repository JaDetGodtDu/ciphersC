#include "cipher.h"
#include <ctype.h>
#include <string.h>

static char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZÆØÅ";
static int alphabetLength = 29;

int letterToNumber(char letter) {
    letter = toupper(letter);
    for (int i = 0; i < alphabetLength; i++) {
        if (alphabet[i] == letter) {
            return i + 1;
        }
    }
    return 0; // Return 0 for non-alphabet characters
}

char numberToLetter(int number) {
    if (number < 1 || number > alphabetLength) {
        return ' ';
    }
    return alphabet[number - 1];
}

int shift(int number, int shiftvalue) {
    int shifted = (number + shiftvalue) % alphabetLength;
    if (shifted <= 0) {
        shifted += alphabetLength;
    }
    return shifted;
}

void encrypt(char* text, int shiftvalue) {
    int length = strlen(text);
    for (int i = 0; i < length; i++) {
        int num = letterToNumber(text[i]);
        if (num != 0) {
            text[i] = numberToLetter(shift(num, shiftvalue));
        }
    }
}

void decrypt(char* text, int shiftvalue) {
    int length = strlen(text);
    for (int i = 0; i < length; i++) {
        int num = letterToNumber(text[i]);
        if (num != 0) {
            text[i] = numberToLetter(shift(num, -shiftvalue));
        }
    }
}

void init() {
    // Alphabet is already initialized statically
}