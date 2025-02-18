//implementation of rail fence row and column transformation technique in c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Function to encrypt using Rail Fence (Row Transformation)
void railFenceEncrypt(char *text, int key, char *cipher) {
    char rail[key][MAX];
    int len = strlen(text), row = 0, dir = 1, index = 0;

    // Initialize rail matrix with '\n'
    for (int i = 0; i < key; i++)
        for (int j = 0; j < len; j++)
            rail[i][j] = '\n';

    // Fill matrix in zigzag pattern
    for (int i = 0; i < len; i++) {
        rail[row][i] = text[i];
        if (row == 0)
            dir = 1;
        else if (row == key - 1)
            dir = -1;
        row += dir;
    }

    // Read matrix row-wise
    for (int i = 0; i < key; i++)
        for (int j = 0; j < len; j++)
            if (rail[i][j] != '\n')
                cipher[index++] = rail[i][j];

    cipher[index] = '\0';
}

// Function to decrypt Rail Fence Cipher
void railFenceDecrypt(char *cipher, int key, char *plain) {
    char rail[key][MAX];
    int len = strlen(cipher), row = 0, dir = 1, index = 0;

    // Initialize rail matrix with '\n'
    for (int i = 0; i < key; i++)
        for (int j = 0; j < len; j++)
            rail[i][j] = '\n';

    // Mark the positions of characters
    for (int i = 0; i < len; i++) {
        rail[row][i] = '*';
        if (row == 0)
            dir = 1;
        else if (row == key - 1)
            dir = -1;
        row += dir;
    }

    // Fill rail matrix with cipher text
    for (int i = 0; i < key; i++)
        for (int j = 0; j < len; j++)
            if (rail[i][j] == '*')
                rail[i][j] = cipher[index++];

    // Read matrix in zigzag pattern
    row = 0, dir = 1, index = 0;
    for (int i = 0; i < len; i++) {
        plain[index++] = rail[row][i];
        if (row == 0)
            dir = 1;
        else if (row == key - 1)
            dir = -1;
        row += dir;
    }

    plain[index] = '\0';
}

// Function to encrypt using Column Transformation
void columnEncrypt(char *text, int key, char *cipher) {
    int len = strlen(text);
    int rows = (len + key - 1) / key; // Compute rows needed
    char grid[rows][key];

    // Fill the grid row-wise
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < key; j++) {
            if (index < len)
                grid[i][j] = text[index++];
            else
                grid[i][j] = 'X'; // Padding
        }
    }

    // Read grid column-wise
    index = 0;
    for (int j = 0; j < key; j++) {
        for (int i = 0; i < rows; i++) {
            cipher[index++] = grid[i][j];
        }
    }
    cipher[index] = '\0';
}

// Function to decrypt Column Transformation
void columnDecrypt(char *cipher, int key, char *plain) {
    int len = strlen(cipher);
    int rows = (len + key - 1) / key;
    char grid[rows][key];

    // Fill the grid column-wise
    int index = 0;
    for (int j = 0; j < key; j++) {
        for (int i = 0; i < rows; i++) {
            if (index < len)
                grid[i][j] = cipher[index++];
        }
    }

    // Read grid row-wise
    index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < key; j++) {
            plain[index++] = grid[i][j];
        }
    }
    plain[index] = '\0';
}

int main() {
    char text[MAX], cipher[MAX], decrypted[MAX];
    int key, choice, method;

    printf("Enter the text (without spaces): ");
    scanf("%s", text);

    printf("Choose encryption method:\n1. Rail Fence Cipher (Row-wise)\n2. Columnar Transposition\n");
    scanf("%d", &method);

    printf("Enter key (integer value): ");
    scanf("%d", &key);

    printf("Choose an option:\n1. Encrypt\n2. Decrypt\n");
    scanf("%d", &choice);

    if (method == 1) { // Rail Fence Cipher
        if (choice == 1) {
            railFenceEncrypt(text, key, cipher);
            printf("Encrypted Text: %s\n", cipher);
        } else if (choice == 2) {
            railFenceDecrypt(text, key, decrypted);
            printf("Decrypted Text: %s\n", decrypted);
        } else {
            printf("Invalid choice!\n");
        }
    } else if (method == 2) { // Column Transformation
        if (choice == 1) {
            columnEncrypt(text, key, cipher);
            printf("Encrypted Text: %s\n", cipher);
        } else if (choice == 2) {
            columnDecrypt(text, key, decrypted);
            printf("Decrypted Text: %s\n", decrypted);
        } else {
            printf("Invalid choice!\n");
        }
    } else {
        printf("Invalid encryption method!\n");
    }

    return 0;
}
