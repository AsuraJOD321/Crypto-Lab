//implementation of rail fence row and column transformation technique in c++
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to encrypt using Rail Fence (Row Transformation)
string railFenceEncrypt(string text, int key) {
    vector<string> rail(key);
    int row = 0, dir = 1;

    for (char c : text) {
        rail[row] += c;
        if (row == 0) dir = 1;
        else if (row == key - 1) dir = -1;
        row += dir;
    }

    string cipher = "";
    for (string line : rail) {
        cipher += line;
    }
    return cipher;
}

// Function to decrypt Rail Fence Cipher
string railFenceDecrypt(string cipher, int key) {
    vector<string> rail(key);
    vector<int> rowIndexes(cipher.length());
    int row = 0, dir = 1, index = 0;

    for (size_t i = 0; i < cipher.length(); i++) {
        rowIndexes[i] = row;
        if (row == 0) dir = 1;
        else if (row == key - 1) dir = -1;
        row += dir;
    }

    for (size_t i = 0; i < cipher.length(); i++) {
        rail[rowIndexes[i]] += '*';
    }

    int k = 0;
    for (int i = 0; i < key; i++) {
        for (char &c : rail[i]) {
            c = cipher[k++];
        }
    }

    string plainText = "";
    for (size_t i = 0; i < cipher.length(); i++) {
        plainText += rail[rowIndexes[i]][0];
        rail[rowIndexes[i]].erase(0, 1);
    }

    return plainText;
}

// Function to encrypt using Columnar Transposition
string columnEncrypt(string text, int key) {
    int len = text.length();
    int rows = (len + key - 1) / key;
    vector<vector<char>> grid(rows, vector<char>(key, 'X'));

    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < key; j++) {
            if (index < len) {
                grid[i][j] = text[index++];
            }
        }
    }

    string cipherText = "";
    for (int j = 0; j < key; j++) {
        for (int i = 0; i < rows; i++) {
            cipherText += grid[i][j];
        }
    }
    return cipherText;
}

// Function to decrypt Columnar Transposition
string columnDecrypt(string cipher, int key) {
    int len = cipher.length();
    int rows = (len + key - 1) / key;
    vector<vector<char>> grid(rows, vector<char>(key));

    int index = 0;
    for (int j = 0; j < key; j++) {
        for (int i = 0; i < rows; i++) {
            if (index < len) {
                grid[i][j] = cipher[index++];
            }
        }
    }

    string plainText = "";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < key; j++) {
            plainText += grid[i][j];
        }
    }
    return plainText;
}

int main() {
    string text, cipher, decrypted;
    int key, choice, method;

    cout << "Enter the text (without spaces): ";
    cin >> text;

    cout << "Choose encryption method:\n1. Rail Fence Cipher (Row-wise)\n2. Columnar Transposition\n";
    cin >> method;

    cout << "Enter key (integer value): ";
    cin >> key;

    cout << "Choose an option:\n1. Encrypt\n2. Decrypt\n";
    cin >> choice;

    if (method == 1) { // Rail Fence Cipher
        if (choice == 1) {
            cipher = railFenceEncrypt(text, key);
            cout << "Encrypted Text: " << cipher << endl;
        } else if (choice == 2) {
            decrypted = railFenceDecrypt(text, key);
            cout << "Decrypted Text: " << decrypted << endl;
        } else {
            cout << "Invalid choice!" << endl;
        }
    } else if (method == 2) { // Column Transformation
        if (choice == 1) {
            cipher = columnEncrypt(text, key);
            cout << "Encrypted Text: " << cipher << endl;
        } else if (choice == 2) {
            decrypted = columnDecrypt(text, key);
            cout << "Decrypted Text: " << decrypted << endl;
        } else {
            cout << "Invalid choice!" << endl;
        }
    } else {
        cout << "Invalid encryption method!" << endl;
    }

    return 0;
}
