//implementation of playfair cipher in c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

char keyTable[SIZE][SIZE];

// Function to remove duplicate characters from the key and prepare the key matrix
void generateKeyTable(char key[], char keyTable[SIZE][SIZE]) {
    int map[26] = {0};
    int i, j, k = 0, len = strlen(key);
    
    // Fill keyTable with the key
    for (i = 0; i < len; i++) {
        if (key[i] == 'J') key[i] = 'I';  // Replace 'J' with 'I'
        if (!map[key[i] - 'A']) {
            map[key[i] - 'A'] = 1;
            keyTable[k / SIZE][k % SIZE] = key[i];
            k++;
        }
    }

    // Fill the remaining spaces with unused letters
    for (i = 0; i < 26; i++) {
        if (i + 'A' == 'J') continue;  // Skip 'J'
        if (!map[i]) {
            keyTable[k / SIZE][k % SIZE] = i + 'A';
            k++;
        }
    }
}

// Function to find the position of a character in the keyTable
void findPosition(char ch, int *row, int *col) {
    if (ch == 'J') ch = 'I';  // Replace 'J' with 'I'
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (keyTable[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

// Function to encrypt text using Playfair cipher
void encrypt(char text[]) {
    int len = strlen(text);
    for (int i = 0; i < len; i += 2) {
        int row1, col1, row2, col2;
        findPosition(text[i], &row1, &col1);
        findPosition(text[i + 1], &row2, &col2);

        if (row1 == row2) {  // Same row: shift right
            text[i] = keyTable[row1][(col1 + 1) % SIZE];
            text[i + 1] = keyTable[row2][(col2 + 1) % SIZE];
        } else if (col1 == col2) {  // Same column: shift down
            text[i] = keyTable[(row1 + 1) % SIZE][col1];
            text[i + 1] = keyTable[(row2 + 1) % SIZE][col2];
        } else {  // Form rectangle
            text[i] = keyTable[row1][col2];
            text[i + 1] = keyTable[row2][col1];
        }
    }
}

// Function to decrypt text using Playfair cipher
void decrypt(char text[]) {
    int len = strlen(text);
    for (int i = 0; i < len; i += 2) {
        int row1, col1, row2, col2;
        findPosition(text[i], &row1, &col1);
        findPosition(text[i + 1], &row2, &col2);

        if (row1 == row2) {  // Same row: shift left
            text[i] = keyTable[row1][(col1 - 1 + SIZE) % SIZE];
            text[i + 1] = keyTable[row2][(col2 - 1 + SIZE) % SIZE];
        } else if (col1 == col2) {  // Same column: shift up
            text[i] = keyTable[(row1 - 1 + SIZE) % SIZE][col1];
            text[i + 1] = keyTable[(row2 - 1 + SIZE) % SIZE][col2];
        } else {  // Form rectangle
            text[i] = keyTable[row1][col2];
            text[i + 1] = keyTable[row2][col1];
        }
    }
}

// Function to prepare the text for encryption by ensuring pairs of letters
void prepareText(char text[]) {
    char newText[100];
    int len = strlen(text), j = 0;

    for (int i = 0; i < len; i++) {
        if (!isalpha(text[i])) continue;  // Ignore non-alphabetic characters

        text[i] = toupper(text[i]);
        if (text[i] == 'J') text[i] = 'I';  // Replace 'J' with 'I'

        if (j > 0 && newText[j - 1] == text[i]) {  
            newText[j++] = 'X';  // Insert 'X' if two same letters are together
        }
        newText[j++] = text[i];
    }

    if (j % 2 != 0) newText[j++] = 'X';  // If odd length, add 'X' at the end

    newText[j] = '\0';
    strcpy(text, newText);
}

int main() {
    char key[30], text[100];
    int choice;

    printf("Enter the key: ");
    scanf("%s", key);
    getchar();  // Consume the newline

    generateKeyTable(key, keyTable);

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';  // Remove newline

    prepareText(text);

    printf("Choose an option:\n1. Encrypt\n2. Decrypt\n");
    scanf("%d", &choice);

    if (choice == 1) {
        encrypt(text);
        printf("Encrypted text: %s\n", text);
    } else if (choice == 2) {
        decrypt(text);
        printf("Decrypted text: %s\n", text);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}
