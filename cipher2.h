#include <wchar.h>
#ifndef CIPHER_H
#define CIPHER_H

void init();
int letterToNumber(wchar_t letter);
wchar_t numberToLetter(int number);
int shift(int number, int shiftvalue);
void encrypt(wchar_t *text, int shift);
void decrypt(wchar_t *text, int shift);

#endif