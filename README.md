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

## Program breakdown



## Sources
1. FEDERAL INFORMATION PROCESSING STANDARDS PUBLICATION
Secure Hash Standard (SHS)
CATEGORY: COMPUTER SECURITY SUBCATEGORY: CRYPTOGRAPHY
Information Technology Laboratory
National Institute of Standards and Technology
Gaithersburg, MD 20899-8900
March 2012 