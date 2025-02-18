//implementatio of hill cipher in c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 3  // Matrix size (change as needed)

// Function to convert character to integer (A=0, B=1, ..., Z=25)
int charToNum(char c) {
    return c - 'A';
}

// Function to convert integer to character
char numToChar(int n) {
    return (n % 26) + 'A';
}

// Function to multiply matrices (Key * Text)
void multiplyMatrix(int key[SIZE][SIZE], int text[], int result[]) {
    for (int i = 0; i < SIZE; i++) {
        result[i] = 0;
        for (int j = 0; j < SIZE; j++) {
            result[i] += key[i][j] * text[j];
        }
        result[i] %= 26;  // Apply mod 26
    }
}

// Function to find the determinant of a 2x2 or 3x3 matrix
int determinant(int key[SIZE][SIZE]) {
    if (SIZE == 2)
        return (key[0][0] * key[1][1] - key[0][1] * key[1][0]) % 26;
    
    return (key[0][0] * (key[1][1] * key[2][2] - key[1][2] * key[2][1]) -
            key[0][1] * (key[1][0] * key[2][2] - key[1][2] * key[2][0]) +
            key[0][2] * (key[1][0] * key[2][1] - key[1][1] * key[2][0])) % 26;
}

// Function to find modular inverse of determinant (mod 26)
int modInverse(int det) {
    det = (det + 26) % 26;  // Ensure positive
    for (int i = 1; i < 26; i++) {
        if ((det * i) % 26 == 1)
            return i;
    }
    return -1;  // No inverse exists
}

// Function to find the inverse of a matrix (only for 2x2 and 3x3)
void inverseMatrix(int key[SIZE][SIZE], int inverse[SIZE][SIZE]) {
    int det = determinant(key);
    int detInv = modInverse(det);
    if (detInv == -1) {
        printf("Matrix is not invertible (mod 26)!\n");
        return;
    }

    // Compute the adjugate matrix (for 2x2 or 3x3)
    int adj[SIZE][SIZE];

    if (SIZE == 2) {
        adj[0][0] = key[1][1];
        adj[0][1] = -key[0][1];
        adj[1][0] = -key[1][0];
        adj[1][1] = key[0][0];
    } else {
        adj[0][0] = (key[1][1] * key[2][2] - key[1][2] * key[2][1]);
        adj[0][1] = -(key[0][1] * key[2][2] - key[0][2] * key[2][1]);
        adj[0][2] = (key[0][1] * key[1][2] - key[0][2] * key[1][1]);

        adj[1][0] = -(key[1][0] * key[2][2] - key[1][2] * key[2][0]);
        adj[1][1] = (key[0][0] * key[2][2] - key[0][2] * key[2][0]);
        adj[1][2] = -(key[0][0] * key[1][2] - key[0][2] * key[1][0]);

        adj[2][0] = (key[1][0] * key[2][1] - key[1][1] * key[2][0]);
        adj[2][1] = -(key[0][0] * key[2][1] - key[0][1] * key[2][0]);
        adj[2][2] = (key[0][0] * key[1][1] - key[0][1] * key[1][0]);
    }

    // Compute inverse matrix
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            inverse[i][j] = (adj[i][j] * detInv) % 26;
            if (inverse[i][j] < 0) inverse[i][j] += 26; // Ensure positive mod
        }
    }
}

// Function to encrypt text using Hill Cipher
void encryptText(int key[SIZE][SIZE], char text[]) {
    int textVector[SIZE], cipherVector[SIZE];
    int len = strlen(text);

    for (int i = 0; i < len; i += SIZE) {
        for (int j = 0; j < SIZE; j++) {
            textVector[j] = charToNum(text[i + j]);
        }
        multiplyMatrix(key, textVector, cipherVector);
        for (int j = 0; j < SIZE; j++) {
            text[i + j] = numToChar(cipherVector[j]);
        }
    }
}

// Function to decrypt text using Hill Cipher
void decryptText(int key[SIZE][SIZE], char text[]) {
    int inverseKey[SIZE][SIZE];
    inverseMatrix(key, inverseKey);

    int textVector[SIZE], plainVector[SIZE];
    int len = strlen(text);

    for (int i = 0; i < len; i += SIZE) {
        for (int j = 0; j < SIZE; j++) {
            textVector[j] = charToNum(text[i + j]);
        }
        multiplyMatrix(inverseKey, textVector, plainVector);
        for (int j = 0; j < SIZE; j++) {
            text[i + j] = numToChar(plainVector[j]);
        }
    }
}

int main() {
    int key[SIZE][SIZE];
    char text[100];
    int choice;

    // Input Key Matrix
    printf("Enter %dx%d key matrix:\n", SIZE, SIZE);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &key[i][j]);
        }
    }

    printf("Enter text (uppercase letters only): ");
    scanf("%s", text);

    // Ensure text length is a multiple of SIZE by padding 'X'
    int len = strlen(text);
    while (len % SIZE != 0) {
        text[len++] = 'X';
    }
    text[len] = '\0';

    printf("Choose an option:\n1. Encrypt\n2. Decrypt\n");
    scanf("%d", &choice);

    if (choice == 1) {
        encryptText(key, text);
        printf("Encrypted text: %s\n", text);
    } else if (choice == 2) {
        decryptText(key, text);
        printf("Decrypted text: %s\n", text);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}

