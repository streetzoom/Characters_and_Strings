/*
A simple and very old method of sending secret messages is the substitution cipher.
You might have used this cipher with your friends when you were a kid.
Basically, each letter of the alphabet gets replaced by another letter of the alphabet.
For example, every 'a' get replaced with an 'X', and every 'b' gets replaced with a 'Z', etc.

Write a program that's ask a user to enter a secret message.

Encrypt this message using the substitution cipher and display the encrypted message.
Then decrypted the encrypted message back to the original message.

You may use the 2 strings below for  your substitution.
For example, to encrypt you can replace the character at position n in alphabet
with the character at position n in key.

To decrypt you can replace the character at position n in key
with the character at position n in alphabet.
*/
#include <iostream>
#include <string>

int main() {

    std::string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    std::string key  {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};

    std::string secret_message {};
    std::cout << "Enter your secret message: ";
    getline(std::cin, secret_message);

    std::string encrypted_message {};

    std::cout << "\nEncrypting message...." << std::endl;

    for (char c : secret_message) {
        size_t Position = alphabet.find(c);
        if (Position != std::string::npos) {
            char new_char {key.at(Position)};
            encrypted_message += new_char;
        } else {
            encrypted_message += c;
        }
    }
    std::cout << "\nEncrypted message: " << encrypted_message;


    std::string decrypted_message {};
    std::cout << "\nDecrypting message...........";

    for (char c : encrypted_message) {
        size_t position = key.find(c);
        if (position != std::string::npos) {
            char new_char {alphabet.at(position)};
            decrypted_message += new_char;
        } else {
            decrypted_message += c;
        }
    }
    std::cout << "\nDecrypted message: " << decrypted_message;

    std::cout << std::endl;

    return 0;
}
