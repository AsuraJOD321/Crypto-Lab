//implementation of playfair cipher in c++
#include <iostream>
#include <vector>
#include <map>
#include <cctype>

using namespace std;

#define SIZE 5

char keyTable[SIZE][SIZE];
map<char, pair<int, int>> letterPos;

// Function to generate the key table (5x5 matrix)
void generateKeyTable(string key) {
    bool used[26] = {false};
    key += "ABCDEFGHIKLMNOPQRSTUVWXYZ"; // Append alphabet, skipping 'J'
    int k = 0;

    for (char &ch : key) {
        if (ch == 'J') ch = 'I'; // Replace 'J' with 'I'
        if (!used[ch - 'A']) {
            used[ch - 'A'] = true;
            keyTable[k / SIZE][k % SIZE] = ch;
            letterPos[ch] = {k / SIZE, k % SIZE};
            k++;
        }
    }
}

// Function to prepare text (pairing letters and handling duplicates)
string prepareText(string text) {
    string newText = "";
    for (char ch : text) {
        if (isalpha(ch)) {
            ch = toupper(ch);
            if (ch == 'J') ch = 'I'; // Replace 'J' with 'I'
            newText += ch;
        }
    }

    string prepared = "";
    for (size_t i = 0; i < newText.length(); i++) {
        prepared += newText[i];
        if (i + 1 < newText.length() && newText[i] == newText[i + 1]) {
            prepared += 'X'; // Insert 'X' between repeating letters
        }
    }
    if (prepared.length() % 2 != 0) prepared += 'X'; // Ensure even length
    return prepared;
}

// Function to encrypt text using Playfair cipher
string encrypt(string text) {
    text = prepareText(text);
    string cipherText = "";

    for (size_t i = 0; i < text.length(); i += 2) {
        int row1, col1, row2, col2;
        tie(row1, col1) = letterPos[text[i]];
        tie(row2, col2) = letterPos[text[i + 1]];

        if (row1 == row2) { // Same row: shift right
            cipherText += keyTable[row1][(col1 + 1) % SIZE];
            cipherText += keyTable[row2][(col2 + 1) % SIZE];
        } else if (col1 == col2) { // Same column: shift down
            cipherText += keyTable[(row1 + 1) % SIZE][col1];
            cipherText += keyTable[(row2 + 1) % SIZE][col2];
        } else { // Form rectangle
            cipherText += keyTable[row1][col2];
            cipherText += keyTable[row2][col1];
        }
    }
    return cipherText;
}

// Function to decrypt text using Playfair cipher
string decrypt(string text) {
    string plainText = "";

    for (size_t i = 0; i < text.length(); i += 2) {
        int row1, col1, row2, col2;
        tie(row1, col1) = letterPos[text[i]];
        tie(row2, col2) = letterPos[text[i + 1]];

        if (row1 == row2) { // Same row: shift left
            plainText += keyTable[row1][(col1 - 1 + SIZE) % SIZE];
            plainText += keyTable[row2][(col2 - 1 + SIZE) % SIZE];
        } else if (col1 == col2) { // Same column: shift up
            plainText += keyTable[(row1 - 1 + SIZE) % SIZE][col1];
            plainText += keyTable[(row2 - 1 + SIZE) % SIZE][col2];
        } else { // Form rectangle
            plainText += keyTable[row1][col2];
            plainText += keyTable[row2][col1];
        }
    }
    return plainText;
}

int main() {
    string key, text;
    int choice;

    cout << "Enter the key: ";
    cin >> key;
    cin.ignore(); // Ignore newline

    generateKeyTable(key);

    cout << "Enter text: ";
    getline(cin, text);

    cout << "Choose an option:\n1. Encrypt\n2. Decrypt\n";
    cin >> choice;

    if (choice == 1) {
        cout << "Encrypted text: " << encrypt(text) << endl;
    } else if (choice == 2) {
        cout << "Decrypted text: " << decrypt(text) << endl;
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
