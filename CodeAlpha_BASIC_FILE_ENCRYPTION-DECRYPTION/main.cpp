#include <iostream>
#include <fstream>
#include <string>


//Function Prototype
std::string encrypt(const std::string& text, int shift);
std::string decrypt(const std::string& text, int shift);
void encryptFile(const std::string& inputFile, const std::string& outputFile, int shift);
void decryptFile(const std::string& inputFile, const std::string& outputFile, int shift);


int main() {
    int choice, shift; // Variables to store user choices
    std::string inputFile, outputFile; // Variables to store file names

    // Display menu options to the user
    std::cout << "1. Encrypt File\n2. Decrypt File\nEnter your choice: ";
    std::cin >> choice;

    // Prompt the user for the shift value (must be between 1 and 25)
    std::cout << "Enter the shift value (1-25): ";
    std::cin >> shift;

    // Prompt the user for the input and output file names
    std::cout << "Enter the input file name: ";
    std::cin >> inputFile;
    std::cout << "Enter the output file name: ";
    std::cin >> outputFile;

    // Perform encryption or decryption based on the user's choice
    if (choice == 1) {
        encryptFile(inputFile, outputFile, shift); // Encrypt the file
        std::cout << "File encrypted successfully!" << std::endl;
    } else if (choice == 2) {
        decryptFile(inputFile, outputFile, shift); // Decrypt the file
        std::cout << "File decrypted successfully!" << std::endl;
    } else {
        std::cerr << "Invalid choice!" << std::endl; // Handle invalid choices
    }

    return 0; // End of program
}

// Function to encrypt the text using Caesar Cipher
std::string encrypt(const std::string& text, int shift) {
    std::string result = ""; // Initialize an empty string to store the encrypted result

    // Loop through each character in the input text
    for (char ch : text) {
        if (isalpha(ch)) { // Check if the character is an alphabet letter
            char base = isupper(ch) ? 'A' : 'a'; // Determine the base value ('A' for uppercase, 'a' for lowercase)
            // Shift the character and wrap around using modulo 26 (for the 26 letters of the alphabet)
            result += static_cast<char>((ch - base + shift) % 26 + base);
        } else {
            result += ch; // Non-alphabetic characters (e.g., numbers, symbols) remain unchanged
        }
    }

    return result; // Return the encrypted string
}

// Function to decrypt the text using Caesar Cipher
std::string decrypt(const std::string& text, int shift) {
    // Decryption is the same as encryption but with the inverse shift (26 - shift)
    return encrypt(text, 26 - shift);
}

// Function to encrypt a file
void encryptFile(const std::string& inputFile, const std::string& outputFile, int shift) {
    std::ifstream inFile(inputFile); // Open the input file for reading
    std::ofstream outFile(outputFile); // Open the output file for writing

    // Check if the files were opened successfully
    if (!inFile || !outFile) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    std::string line; // Variable to store each line of the file
    // Read the input file line by line
    while (getline(inFile, line)) {
        // Encrypt the line and write it to the output file
        outFile << encrypt(line, shift) << std::endl;
    }

    // Close the files
    inFile.close();
    outFile.close();
}

// Function to decrypt a file
void decryptFile(const std::string& inputFile, const std::string& outputFile, int shift) {
    // Decryption is the same as encryption but with the inverse shift (26 - shift)
    encryptFile(inputFile, outputFile, 26 - shift);
}
