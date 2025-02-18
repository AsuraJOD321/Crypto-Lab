
<h1>Cryptography Algorithms in C & C++</h1>
<p>This repository contains implementations of various cryptographic algorithms in C and C++. These implementations serve as educational tools and provide a hands-on approach to understanding the basics of cryptography.</p>

<h2>🚀 <strong>Algorithms Implemented</strong></h2>
<ul>
    <li>Caesar Cipher (Substitution Cipher)</li>
    <li>Vigenère Cipher (Polyalphabetic Cipher)</li>
    <li>Playfair Cipher (Digraph Substitution Cipher)</li>
    <li>Hill Cipher (Matrix-based Cipher)</li>
    <li>Rail Fence Cipher (Transposition Cipher - Row & Column Transformation)</li>
    <li>Columnar Transposition Cipher (Column-based Transposition Cipher)</li>
</ul>

<h2>🛠️ <strong>Technologies Used</strong></h2>
<ul>
    <li>C Programming Language</li>
    <li>C++ Programming Language</li>
</ul>

<h2>📚 <strong>Overview</strong></h2>
<p>This repository demonstrates different cryptographic techniques using the C and C++ languages. Each cipher is implemented with both <strong>encryption</strong> and <strong>decryption</strong> functionalities. The purpose is to help users understand how each algorithm works and provide code examples for educational and practical purposes.</p>

<h2>🔑 <strong>How to Use</strong></h2>

<h3>Prerequisites</h3>
<p>To run the programs, you need to have a C or C++ compiler installed (such as GCC or Clang).</p>

<h3>Steps to Run</h3>
<ol>
<li>Clone the repository to your local machine:</li>
<pre>git clone https://github.com/AsuraJOD321/Crypto-Lab.git</pre>

 <li>Navigate to the desired cipher program directory (e.g., <code>caesar_cipher</code>, <code>rail_fence_cipher</code>).</li>
 <li>Compile the code:
        <ul>
            <li>For C: <pre>gcc -o caesar_cipher caesar_cipher.c</pre></li>
            <li>For C++: <pre>g++ -o caesar_cipher caesar_cipher.cpp</pre></li>
        </ul>
    </li>

 <li>Run the program:
        <ul>
            <li>For C: <pre>./caesar_cipher</pre></li>
            <li>For C++: <pre>./caesar_cipher</pre></li>
        </ul>
    </li>
</ol>

<h2>✨ <strong>Features</strong></h2>
<ul>
    <li><strong>Encryption/Decryption:</strong> Each cipher allows both encryption and decryption of text.</li>
    <li><strong>Interactive Input:</strong> Users can input their own text and keys.</li>
    <li><strong>Multiple Ciphers:</strong> Several classic cryptographic algorithms are implemented for comparison.</li>
</ul>

<h2>📝 <strong>Example</strong></h2>
<p>Here is an example for <strong>Caesar Cipher</strong> (Shift Cipher):</p>
<ul>
    <li><strong>Encrypting</strong> the text "<code>HELLO</code>" with a key of <code>3</code> results in "<code>KHOOR</code>".</li>
    <li><strong>Decrypting</strong> "<code>KHOOR</code>" with the same key returns "<code>HELLO</code>".</li>
</ul>

<h2>🔍 <strong>Usage Examples</strong></h2>
<h3>Caesar Cipher Example</h3>
<pre>
Enter the text to encrypt: HELLO
Enter the key: 3
Encrypted Text: KHOOR
</pre>

<h3>Vigenère Cipher Example</h3>
<pre>
Enter the text to encrypt: HELLO
Enter the key: KEY
Encrypted Text: RIJVS
</pre>

<h2>💡 <strong>Contributing</strong></h2>
<p>Feel free to fork this repository, make improvements, or submit issues and pull requests.</p>

