//implementation of caeser cipher in c
#include <stdio.h>
#include <ctype.h>

void encrypt(char text[], int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];

        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            text[i] = (ch - base + shift) % 26 + base;
        }
    }
}

void decrypt(char text[], int shift) {
    encrypt(text, 26 - shift);  // Decryption is just shifting in the opposite direction
}

int main() {
    char text[100];
    int shift, choice;

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter shift key: ");
    scanf("%d", &shift);

    printf("Choose an option: \n1. Encrypt\n2. Decrypt\n");
    scanf("%d", &choice);

    if (choice == 1) {
        encrypt(text, shift);
        printf("Encrypted text: %s\n", text);
    } else if (choice == 2) {
        decrypt(text, shift);
        printf("Decrypted text: %s\n", text);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}
