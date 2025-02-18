//implementation of vigenere cipher in c
\#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to generate the key of the same length as text
void generateKey(char *text, char *key, char *newKey) {
    int textLen = strlen(text);
    int keyLen = strlen(key);
    int i, j;
    
    for (i = 0, j = 0; i < textLen; i++, j++) {
        if (j == keyLen) j = 0; // Repeat key
        newKey[i] = key[j];
    }
    newKey[i] = '\0'; // Null terminate newKey
}

// Function to encrypt text using Vigenère Cipher
void encryptText(char *text, char *key, char *cipherText) {
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        cipherText[i] = ((text[i] - 'A') + (key[i] - 'A')) % 26 + 'A';
    }
    cipherText[i] = '\0'; // Null terminate
}

// Function to decrypt text using Vigenère Cipher
void decryptText(char *cipherText, char *key, char *plainText) {
    int i;
    for (i = 0; cipherText[i] != '\0'; i++) {
        plainText[i] = ((cipherText[i] - 'A') - (key[i] - 'A') + 26) % 26 + 'A';
    }
    plainText[i] = '\0'; // Null terminate
}

int main() {
    char text[100], key[100], newKey[100], cipherText[100], decryptedText[100];
    int choice;

    // Input plaintext and key
    printf("Enter the text (uppercase only): ");
    scanf("%s", text);
    printf("Enter the key (uppercase only): ");
    scanf("%s", key);

    // Generate key of same length as text
    generateKey(text, key, newKey);

    printf("Choose an option:\n1. Encrypt\n2. Decrypt\n");
    scanf("%d", &choice);

    if (choice == 1) {
        encryptText(text, newKey, cipherText);
        printf("Encrypted Text: %s\n", cipherText);
    } else if (choice == 2) {
        decryptText(text, newKey, decryptedText);
        printf("Decrypted Text: %s\n", decryptedText);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}
