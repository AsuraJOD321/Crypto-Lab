// implementation of vigenere cipher in c++

#include <iostream>
#include <string>

using namespace std;

// Function to generate a key of the same length as text
string generateKey(string text, string key) {
    int textLen = text.length();
    int keyLen = key.length();
    string newKey = key;
    
    for (int i = keyLen; i < textLen; i++) {
        newKey += key[i % keyLen]; // Repeat key
    }
    return newKey;
}

// Function to encrypt text using Vigenère Cipher
string encryptText(string text, string key) {
    string cipherText = "";
    for (size_t i = 0; i < text.length(); i++) {
        char encryptedChar = ((text[i] - 'A') + (key[i] - 'A')) % 26 + 'A';
        cipherText += encryptedChar;
    }
    return cipherText;
}

// Function to decrypt text using Vigenère Cipher
string decryptText(string cipherText, string key) {
    string plainText = "";
    for (size_t i = 0; i < cipherText.length(); i++) {
        char decryptedChar = ((cipherText[i] - 'A') - (key[i] - 'A') + 26) % 26 + 'A';
        plainText += decryptedChar;
    }
    return plainText;
}

int main() {
    string text, key, newKey, cipherText, decryptedText;
    int choice;

    // Input plaintext and key
    cout << "Enter the text (uppercase only): ";
    cin >> text;
    cout << "Enter the key (uppercase only): ";
    cin >> key;

    // Generate key of same length as text
    newKey = generateKey(text, key);

    cout << "Choose an option:\n1. Encrypt\n2. Decrypt\n";
    cin >> choice;

    if (choice == 1) {
        cipherText = encryptText(text, newKey);
        cout << "Encrypted Text: " << cipherText << endl;
    } else if (choice == 2) {
        decryptedText = decryptText(text, newKey);
        cout << "Decrypted Text: " << decryptedText << endl;
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}



