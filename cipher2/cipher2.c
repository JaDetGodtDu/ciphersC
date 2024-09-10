#include "cipher2.h"
#include <wctype.h>
#include <wchar.h>
#include <locale.h>
#include <stdio.h>

wchar_t alphabet[] = L"ABCDEFGHIJKLMNOPQRSTUVWXYZÆØÅ";
int alphabet_length;

void init()
{
    setlocale(LC_ALL, "da_DK.UTF-8"); // Set locale to Danish UTF-8
    wprintf(L"Initializing cipher\n");
    wprintf(L"Alphabet: %ls\n", alphabet);
    alphabet_length = wcslen(alphabet);
    wprintf(L"Alphabet length: %d\n", alphabet_length);
}

int letterToNumber(wchar_t letter)
{
    for (int i = 0; i < alphabet_length; i++)
    {
        if (alphabet[i] == letter)
        {
            return i + 1;
        }
    }
    // Handle specific cases for Æ, Ø, Å, æ, ø, å
    switch (letter)
    {
    case L'Æ':
        return 27;
    case L'Ø':
        return 28;
    case L'Å':
        return 29;
    case L'æ':
        return 27;
    case L'ø':
        return 28;
    case L'å':
        return 29;
    default:
        return 0;
    }
}

wchar_t numberToLetter(int number)
{
    if (number < 1 || number > alphabet_length)
    {
        return L' '; // Return space for out-of-bound numbers
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

void encrypt(wchar_t *text, int shiftvalue)
{
    for (int i = 0; text[i] != L'\0'; i++)
    {
        int number = letterToNumber(text[i]);
        wprintf(L"Original letter: %lc, number: %d\n", text[i], number); // DEBUGGING
        if (number != 0)
        {
            text[i] = numberToLetter(shift(number, shiftvalue));
            wprintf(L"Encrypted letter: %lc, number: %d\n", text[i], shift(number, shiftvalue)); // DEBUGGING
        }
    }
}

void decrypt(wchar_t *text, int shiftvalue)
{
    for (int i = 0; text[i] != L'\0'; i++)
    {
        int number = letterToNumber(text[i]);
        wprintf(L"Encrypted letter: %lc, number: %d\n", text[i], number); // DEBUGGING
        if (number != 0)
        {
            text[i] = numberToLetter(shift(number, -shiftvalue));
            wprintf(L"Decrypted letter: %lc, number: %d\n", text[i], shift(number, -shiftvalue)); // DEBUGGING
        }
    }
}