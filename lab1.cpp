//implementation of caeser cipher in c++

#include <iostream>
#include <string>
using namespace std;

// Function to encrypt the text
string encrypt(string text, int shift) {
    for (char &ch : text) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            ch = (ch - base + shift) % 26 + base;
        }
    }
    return text;
}

// Function to decrypt the text
string decrypt(string text, int shift) {
    return encrypt(text, 26 - shift);  // Decryption is just shifting in the opposite direction
}

int main() {
    string text;
    int shift, choice;

    cout << "Enter text: ";
    getline(cin, text);

    cout << "Enter shift key: ";
    cin >> shift;

    cout << "Choose an option: \n1. Encrypt\n2. Decrypt\n";
    cin >> choice;

    if (choice == 1) {
        cout << "Encrypted text: " << encrypt(text, shift) << endl;
    } else if (choice == 2) {
        cout << "Decrypted text: " << decrypt(text, shift) << endl;
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
