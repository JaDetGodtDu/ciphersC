#include <stdio.h>
#include "cipher.h"
#include "caesar.h"

void menu() {
    char choice;
    char text[255];
    int shiftvalue;

    printf("Choose (e)ncrypt or (d)ecrypt: ");
    scanf(" %c", &choice);
    getchar(); // Consume newline character

    printf("Enter shift value: ");
    scanf("%d", &shiftvalue);
    getchar(); // Consume newline character
    
    printf("Enter text: ");
    fgets(text, 255, stdin);
    // Remove newline character manually
    for (int i = 0; i < 255; i++) {
        if (text[i] == '\n') {
            text[i] = '\0';
            break;
        }
    }

    init();

    if (choice == 'e') {
        encrypt(text, shiftvalue);
        printf("Encrypted text: %s\n", text);
    } else if (choice == 'd') {
        decrypt(text, shiftvalue);
        printf("Decrypted text: %s\n", text);
    } else {
        printf("Invalid choice.\n");
    }
}

int main() {
    menu();
    return 0;
}