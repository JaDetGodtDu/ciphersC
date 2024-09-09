#include <stdio.h>
#include "cipher.h"
#include "caesar.h"

void menu() {
    char choice;
    int shiftvalue;
    char text[255];

    printf("Choose (e)ncrypt or (d)ecrypt: ");
    scanf(" %c", &choice);
    printf("Enter shift value: ");
    scanf("%d", &shiftvalue);
    getchar(); // Consume newline character left by scanf
    printf("Enter text: ");
    fgets(text, 255, stdin);

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
    init();
    menu();
    return 0;
}