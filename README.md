# Crypto-Lab


<h1>Cryptography Algorithms in C & C++</h1>
This repository contains implementations of various cryptographic algorithms in C and C++. These implementations serve as educational tools and provide a hands-on approach to understanding the basics of cryptography.

🚀 Algorithms Implemented
Caesar Cipher (Substitution Cipher)
Vigenère Cipher (Polyalphabetic Cipher)
Playfair Cipher (Digraph Substitution Cipher)
Hill Cipher (Matrix-based Cipher)
Rail Fence Cipher (Transposition Cipher - Row & Column Transformation)
Columnar Transposition Cipher (Column-based Transposition Cipher)
🛠️ Technologies Used
C Programming Language
C++ Programming Language
📚 Overview
This repository demonstrates different cryptographic techniques using the C and C++ languages. Each cipher is implemented with both encryption and decryption functionalities. The purpose is to help users understand how each algorithm works and provide code examples for educational and practical purposes.

🔑 How to Use
Prerequisites
To run the programs, you need to have a C or C++ compiler installed (such as GCC or Clang).

Steps to Run
Clone the repository to your local machine:

bash
Copy
Edit
git clone https://github.com/your-username/crypto-c-cpp.git
Navigate to the desired cipher program directory (e.g., caesar_cipher, rail_fence_cipher).

Compile the code:

For C:

gcc -o caesar_cipher caesar_cipher.c
For C++:

g++ -o caesar_cipher caesar_cipher.cpp
Run the program:

For C:
bash
Copy
Edit
./caesar_cipher
For C++:
bash
Copy
Edit
./caesar_cipher
✨ Features
Encryption/Decryption: Each cipher allows both encryption and decryption of text.
Interactive Input: Users can input their own text and keys.
Multiple Ciphers: Several classic cryptographic algorithms are implemented for comparison.
📝 Example
Here is an example for Caesar Cipher (Shift Cipher):

Encrypting the text "HELLO" with a key of 3 results in "KHOOR".
Decrypting "KHOOR" with the same key returns "HELLO".
🔍 Usage Examples
You can specify how each cipher works, for instance:

Caesar Cipher Example

Enter the text to encrypt: HELLO
Enter the key: 3
Encrypted Text: KHOOR
Vigenère Cipher Example
Enter the text to encrypt: HELLO
Enter the key: KEY
Encrypted Text: RIJVS
💡 Contributing
Feel free to fork this repository, make improvements, or submit issues and pull requests.

📄 License
This project is licensed under the MIT License - see the LICENSE file for details.

