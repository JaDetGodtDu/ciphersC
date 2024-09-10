#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include "cipher2.h"
#include "caesar2.h"

void menu()
{
    wchar_t choice;
    wchar_t text[255];
    int shiftvalue;

    setlocale(LC_ALL, "da_DK.UTF-8"); // Set locale to Danish UTF-8

    wprintf(L"Choose (e)ncrypt or (d)ecrypt: ");
    wscanf(L" %lc", &choice);
    getchar(); // Consume newline character

    wprintf(L"Enter shift value: ");
    wscanf(L"%d", &shiftvalue);
    getchar(); // Consume newline character

    wprintf(L"Enter text: ");
    fgetws(text, 255, stdin);
    // Remove newline character manually
    for (int i = 0; i < 255; i++)
    {
        if (text[i] == L'\n')
        {
            text[i] = L'\0';
            break;
        }
    }

    init();

    wprintf(L"Text before encryption/decryption: %ls\n", text); // DEBUGGING

    if (choice == L'e')
    {
        encrypt(text, shiftvalue);
        wprintf(L"Encrypted text: %ls\n", text);
    }
    else if (choice == L'd')
    {
        decrypt(text, shiftvalue);
        wprintf(L"Decrypted text: %ls\n", text);
    }
    else
    {
        wprintf(L"Invalid choice.\n");
    }
}

int main()
{
    menu();
    return 0;
}