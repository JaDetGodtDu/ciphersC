#include <stdio.h>
#include "cipher.h"

void menu() {
    char choice;
    int shiftvalue;
    char text[100];

    // printf("Vælg (e)ncrypt or (d)ecrypt: ");
    printf("Vælg kryptering(e) eller dekryptering(d): ");
    scanf(" %c", &choice);
    printf("Vælg forskydningsværdi: ");
    scanf("%d", &shiftvalue);
    printf("Indtast tekst: ");
    scanf(" %[^\n]", text);

    if (choice == 'e') {
        encrypt(text, shiftvalue);
        printf("Krypteret tekst: %s\n", text);
    } else if (choice == 'd') {
        decrypt(text, shiftvalue);
        printf("Dekrypteret tekst: %s\n", text);
    } else {
        printf("Ugyldigt valg\n");
    }
}

int main() {
    init();
    menu();
    return 0;
}