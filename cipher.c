#include <stdio.h>
#include <string.h>
#include "cipher.h"

char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZÆØÅ";
int alphabet_length = 29;


int letterToNumber(char letter){
    for (int i = 0; i < alphabet_length; i++) {
        if (alphabet[i] == letter) {
            return i + 1;
        }
    }
    return 0;
}
char numberToLetter(int number){
    if (number < 1 || number > alphabet_length) {
        return ' ';
    }
    return alphabet[number - 1];
}
int shift(int number, int shiftvalue){
    int shifted = (number + shiftvalue) % alphabet_length;
    if (shifted <= 0) {
        shifted += alphabet_length;
    }
    return shifted;
}
void encrypt(char* text, int shiftvalue){
    int length = strlen(text);
    for (int i = 0; i < length; i++) {
        int number = letterToNumber(text[i]);
        if (number != 0) {
            text[i] = numberToLetter(shift(number, shiftvalue));
        }
    }
}
void decrypt(char* text, int shiftvalue){
    encrypt(text, -shiftvalue);
}
void init(){
    printf("Cipher initialized\n");
}