#ifndef CIPHER_H
#define CIPHER_H

void init();
int letterToNumber(char letter);
char numberToLetter(int number);
int shift(int number, int shiftvalue);
void encrypt(char* text, int shift);
void decrypt(char* text, int shift);

#endif