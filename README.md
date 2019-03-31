# Secure Hash Algorithm-256 Algorithm
## Introduction
Secure hash algorithms are used for computing a condensed representation of electronic data (message), and output a condensed representation called a message digest. The output message digest will be 256 bits long if it has been passed through a SHA-256 algorithm. The SHA-256 algorithm are used with other cryptographic algorithms, such as digital signature algorithms and keyed-hash message authentication codes, or in the generation of random numbers (bits). [1]

The algorithm can be split into two stages: message padding and the hash computation [1]. Message padding involves padding the message block with zeroes and details about the message block, where else the hash computation involves rotating and moving bits around using functions so that the final message digest can be computated. 

This report will describe the SHA-256 program that is able to compute the final hash value of a text file or a string input, its installation method and steps, and how to run the program.

## Prerequisites
1. GCC
    - on Unix/Linux from here https://gcc.gnu.org/install/
    - on Windows, download MinGW from here www.mingw.org

## Installing the program
1. Git Clone this repository to your local machine
``` 
git clone https://github.com/yonjeremy/sha256-algorithm
```
2. Change directory into the repository that you have just cloned
``` 
cd sha256-algorithm
```
3. Compile the C file
```
gcc -o sha256 .\sha.c
```
4. Run the executable file
```
.\sha256.exe
```
## Running the program
1. Main menu
- The user is greeted with the Main menu. There are two main options: "1" to parse in a file or "2" to parse in a string
2. File Parser
- If option "1" is selected, the user is prompted to enter in a file name.
3. String parser 
- if option "2" is selected, the user is prompted to enter a string.
4. Exit program
- If option "3" is selected, the user will exit the program.

## Testing the program
1. Files test cases

| Test File             | Expected Result |
| AliceInWonderland.txt | ee896783 5362d4b3 f1b4f1dc 16b4a64f a34fa257 364a7225 a3cb77e7 bc80297b |
| abc.txt               | c03d846f 81741707 355ee5d7 f345e523 1942e2f5 f7698700 6145502c a1d10630 |

2. String test cases

| Test String           | Expected Result |
| "abc"                 | c03d846f 81741707 355ee5d7 f345e523 1942e2f5 f7698700 6145502c a1d10630 |
| "123"                 | c17d367d 4166b0fd e90b4845 bd881ac5 6e8ace09 272275dc 0a8d1af9 f7681262 |

## Program breakdown
1. File or string parsing
- The program starts of with a main() function with tells the executable which function to execute first. The main function handles aribitrary menu display instructions and scanf functions to get user inputs from the console.
- This section is responsible for parsing the file or string inputs into the pre-processor correctly. For the file parser, the program will check if the file that is to be parsed exists and is valid. This is done by a file_exist() function that checks the buffer of the file. For the string parser, the program will create or overwrite a file called temp.txt that temporarily holds the string that is to be parsed in, and then sends this file to the preprocessor to be handled later
- After the output hash value has been displayed, the menu will be shown again so that the user can run a different file input or string input until the user exits the program.

2. Preprocessing and Padding
- The program has to process and pad the input in a way which is according to the standards specified in the SHA official document [1]. This involves padding the end of the message blocks with zero and other info.
- When the hash computation (explained below) requests a message block, the preprocessor will loop over the file input and breakdown the file into 64 byte segments. From here, there are different scenarios that can take place. The first



how your program works, and how you wrote it

## Sources
1. FEDERAL INFORMATION PROCESSING STANDARDS PUBLICATION
Secure Hash Standard (SHS)
CATEGORY: COMPUTER SECURITY SUBCATEGORY: CRYPTOGRAPHY
Information Technology Laboratory
National Institute of Standards and Technology
Gaithersburg, MD 20899-8900
March 2012 