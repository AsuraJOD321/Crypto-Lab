//implementatio of hill cipher in c++

#include <iostream>
#include <vector>

using namespace std;

#define SIZE 3 // Matrix size (change as needed)

// Function to convert character to integer (A=0, B=1, ..., Z=25)
int charToNum(char c) {
    return c - 'A';
}

// Function to convert integer to character
char numToChar(int n) {
    return (n % 26) + 'A';
}

// Function to multiply matrices (Key * Text)
vector<int> multiplyMatrix(vector<vector<int>> key, vector<int> text) {
    vector<int> result(SIZE, 0);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i] += key[i][j] * text[j];
        }
        result[i] %= 26; // Apply mod 26
    }
    return result;
}

// Function to find determinant of a 3x3 matrix
int determinant(vector<vector<int>> key) {
    return (key[0][0] * (key[1][1] * key[2][2] - key[1][2] * key[2][1]) -
            key[0][1] * (key[1][0] * key[2][2] - key[1][2] * key[2][0]) +
            key[0][2] * (key[1][0] * key[2][1] - key[1][1] * key[2][0])) % 26;
}

// Function to find modular inverse of determinant (mod 26)
int modInverse(int det) {
    det = (det + 26) % 26; // Ensure positive
    for (int i = 1; i < 26; i++) {
        if ((det * i) % 26 == 1)
            return i;
    }
    return -1; // No inverse exists
}

// Function to compute inverse of a 3x3 matrix (mod 26)
vector<vector<int>> inverseMatrix(vector<vector<int>> key) {
    vector<vector<int>> inverse(SIZE, vector<int>(SIZE, 0));
    int det = determinant(key);
    int detInv = modInverse(det);
    if (detInv == -1) {
        cout << "Matrix is not invertible (mod 26)!" << endl;
        exit(1);
    }

    vector<vector<int>> adj(SIZE, vector<int>(SIZE));

    // Compute adjugate matrix
    adj[0][0] = (key[1][1] * key[2][2] - key[1][2] * key[2][1]);
    adj[0][1] = -(key[0][1] * key[2][2] - key[0][2] * key[2][1]);
    adj[0][2] = (key[0][1] * key[1][2] - key[0][2] * key[1][1]);

    adj[1][0] = -(key[1][0] * key[2][2] - key[1][2] * key[2][0]);
    adj[1][1] = (key[0][0] * key[2][2] - key[0][2] * key[2][0]);
    adj[1][2] = -(key[0][0] * key[1][2] - key[0][2] * key[1][0]);

    adj[2][0] = (key[1][0] * key[2][1] - key[1][1] * key[2][0]);
    adj[2][1] = -(key[0][0] * key[2][1] - key[0][1] * key[2][0]);
    adj[2][2] = (key[0][0] * key[1][1] - key[0][1] * key[1][0]);

    // Compute inverse matrix (mod 26)
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            inverse[i][j] = (adj[i][j] * detInv) % 26;
            if (inverse[i][j] < 0) inverse[i][j] += 26; // Ensure positive mod
        }
    }

    return inverse;
}

// Function to encrypt text using Hill Cipher
void encryptText(vector<vector<int>> key, string &text) {
    int len = text.length();
    for (int i = 0; i < len; i += SIZE) {
        vector<int> textVector(SIZE);
        for (int j = 0; j < SIZE; j++) {
            textVector[j] = charToNum(text[i + j]);
        }
        vector<int> cipherVector = multiplyMatrix(key, textVector);
        for (int j = 0; j < SIZE; j++) {
            text[i + j] = numToChar(cipherVector[j]);
        }
    }
}

// Function to decrypt text using Hill Cipher
void decryptText(vector<vector<int>> key, string &text) {
    vector<vector<int>> inverseKey = inverseMatrix(key);
    int len = text.length();
    for (int i = 0; i < len; i += SIZE) {
        vector<int> textVector(SIZE);
        for (int j = 0; j < SIZE; j++) {
            textVector[j] = charToNum(text[i + j]);
        }
        vector<int> plainVector = multiplyMatrix(inverseKey, textVector);
        for (int j = 0; j < SIZE; j++) {
            text[i + j] = numToChar(plainVector[j]);
        }
    }
}

int main() {
    vector<vector<int>> key(SIZE, vector<int>(SIZE));
    string text;
    int choice;

    // Input Key Matrix
    cout << "Enter " << SIZE << "x" << SIZE << " key matrix:\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cin >> key[i][j];
        }
    }

    cout << "Enter text (uppercase letters only): ";
    cin >> text;

    // Ensure text length is a multiple of SIZE by padding 'X'
    while (text.length() % SIZE != 0) {
        text += 'X';
    }

    cout << "Choose an option:\n1. Encrypt\n2. Decrypt\n";
    cin >> choice;

    if (choice == 1) {
        encryptText(key, text);
        cout << "Encrypted text: " << text << endl;
    } else if (choice == 2) {
        decryptText(key, text);
        cout << "Decrypted text: " << text << endl;
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
