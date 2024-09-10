#include "cipher.h"
#include <ctype.h>
#include <stdio.h>
#include <locale.h>

// char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZÆØÅ";
char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ\xC3\x86\xC3\x98\xC3\x85";
int alphabet_length;

void init()
{
    setlocale(LC_ALL, "da_DK.UTF-8");
    printf("Initializing cipher\n");
    printf("Alphabet: %s\n", alphabet);
    alphabet_length = sizeof(alphabet) / sizeof(alphabet[0]) - 1;
    // alphabet_length = 29;
}

int letterToNumber(char letter)
{
    letter = toupper(letter);
    for (int i = 0; i < alphabet_length; i++)
    {
        if (alphabet[i] == letter)
        {
            return i + 1;
        }
    }
    return 0;
}

char numberToLetter(int number)
{
    if (number < 1 || number > alphabet_length)
    {
        return ' '; // Return space for out-of-bound numbers
    }
    return alphabet[number - 1];
}

int shift(int number, int shiftvalue)
{
    int shifted = (number + shiftvalue) % alphabet_length;
    if (shifted <= 0)
    {
        shifted += alphabet_length;
    }
    return shifted;
}

void encrypt(char *text, int shiftvalue)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        int number = letterToNumber(text[i]);
        if (number != 0)
        {
            text[i] = numberToLetter(shift(number, shiftvalue));
        }
    }
}

void decrypt(char *text, int shiftvalue)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        int number = letterToNumber(text[i]);
        if (number != 0)
        {
            text[i] = numberToLetter(shift(number, -shiftvalue));
        }
    }
}