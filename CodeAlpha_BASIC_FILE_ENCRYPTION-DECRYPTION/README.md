# CodeAlpha_BASIC_FILE_ENCRYPTION-DECRYPTION

How the Code Works:
Encryption Function (encrypt):

The function takes a string and a shift value as input.

It shifts each alphabetic character by the specified shift value while leaving non-alphabetic characters unchanged.

The result is the encrypted text.

Decryption Function (decrypt):

Decryption is simply the reverse of encryption. It uses the same encrypt function but with the shift value adjusted to 26 - shift.

File Encryption (encryptFile):

The function reads the input file line by line, encrypts each line, and writes the encrypted text to the output file.

File Decryption (decryptFile):

Similar to encryptFile, but it decrypts the content instead.

Main Function:

The user is prompted to choose between encryption and decryption.

The user inputs the shift value, input file name, and output file name.

Depending on the user's choice, the program either encrypts or decrypts the file.

Example Usage:
Encrypting a File:

Input File: input.txt

Output File: encrypted.txt

Shift Value: 3

The program will read input.txt, encrypt its content using a shift of 3, and save the result in encrypted.txt.

Decrypting a File:

Input File: encrypted.txt

Output File: decrypted.txt

Shift Value: 3

The program will read encrypted.txt, decrypt its content using a shift of 3, and save the result in decrypted.txt.

