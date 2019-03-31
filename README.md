# Secure Hash Algorithm-256 Algorithm
## Introduction
Secure hash algorithms are used for computing a condensed representation of electronic data (message), and output a condensed representation called a message digest. The output message digest will be 256 bits long if it has been passed through a SHA-256 algorithm. The SHA-256 algorithm are used with other cryptographic algorithms, such as digital signature algorithms and keyed-hash message authentication codes, or in the generation of random numbers (bits). [1]

The algorithm can be split into two stages: message padding and the hash computation [1]. Message padding involves padding the message block with zeroes and details about the message block, where else the hash computation involves rotating and moving bits around using functions so that the final message digest can be computated. 

This report will describe the SHA-256 program that is able to compute the final hash value of a text file or a string input, its installation method and steps, and how to run the program.

## How I wrote the program
1. When the project was given to use, I started off with watching the videos about the SHA algorithm and concept behind SHA256. These videos were posted by Dr Ian McLoughlin, to be used as guides in the development of this software.[4]
2. Next, I started off by programming the Hash computation side of things, first by setting up the bit wise operations, and then the manipulation of the bits.
3. I then programmed the padding that will be used to add zeroes to the remaining bytes of the last message blocks
4. Lastly, I combined both programs, and tidied up the code by displaying menu options and setting up different methods of inputs (file input or string input).
5. I documented all the steps and processes and included them in this report.


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

AliceInWonderland.txt : ee896783 5362d4b3 f1b4f1dc 16b4a64f a34fa257 364a7225 a3cb77e7 bc80297b 
abc.txt               : c03d846f 81741707 355ee5d7 f345e523 1942e2f5 f7698700 6145502c a1d10630 

2. String test cases

| Test String           | Expected Result |
"abc"                 : c03d846f 81741707 355ee5d7 f345e523 1942e2f5 f7698700 6145502c a1d10630 |
"123"                 : c17d367d 4166b0fd e90b4845 bd881ac5 6e8ace09 272275dc 0a8d1af9 f7681262 |

## Program breakdown
1. File or string parsing
- The program starts of with a main() function with tells the executable which function to execute first. The main function handles aribitrary menu display instructions and scanf functions to get user inputs from the console.
- This section is responsible for parsing the file or string inputs into the pre-processor correctly. For the file parser, the program will check if the file that is to be parsed exists and is valid. This is done by a file_exist() function that checks the buffer of the file. For the string parser, the program will create or overwrite a file called temp.txt that temporarily holds the string that is to be parsed in, and then sends this file to the preprocessor to be handled later
- After the output hash value has been displayed, the menu will be shown again so that the user can run a different file input or string input until the user exits the program.

2. Preprocessing and Padding
- The program has to process and pad the input in a way which is according to the standards specified in the SHA official document [1]. This involves padding the end of the message blocks with zero and other info.
- When the hash computation (explained below) requests a message block, the preprocessor will loop over the file input and breakdown the file into 64 byte segments. From here, there are different scenarios that can take place. 
- The first is that the file will have more than 64 bytes left to be read, and the sha256() function will call the next message block. 
- The next scenario would be that the message block would have less than 56 bytes. This will pad the remaining bytes with zeroes. 
- The 3rd scenario would be the message block would have between 56 and 64 bytes. This will pad the remaining bytes with zeroes and flag it with PAD0. PAD0 is a flag that will tell the while loop to create the next message block that is padded only with zeroes. 
- Lastly, the fourth scenario is when the message block contains exactly 64 bytes. This will flag the it with PAD1, which has the same effect as PAD0, to set the next message blocks to be filled with zeroes, but change the first byte to a 1.

3. Hash Computation
- The sha256() function handles the actual computation of the final hash value, or the message digest. It starts with the defining constants, for example K numbers which are the first 64 prime numbers in Hex, and H values which are 8 initial hex values. 
- A while loop will then go through every 64 byte message block and update the H values by rotating and moving their bits, using vaious other functions.
- The rotr() and shr() function is the rotate right and shift right function, which will change the position of the bytes.
- SIG0, SIG1,sig0,sig1, ch and maj functions are used alongside the K values to update the H value.
- The output are all the H values, which is the message digest.

## Known Faults
1. Big vs Little Endian
- The SHA documentation specifies that the software is to be coded in Big endian. On most intel 64 bit and 32 bit machines, however, work in little endians[2]. This means that the program does not work correctly. For test case "abc", the correct big endian result should be "ba7816bf 8f01cfea 414140de 5dae2223 b00361a3 96177a9c b410ff61 f20015ad". I have attempted to change the message blocks to big endian but this proved to be harder than expected. 

## Sources
1. FEDERAL INFORMATION PROCESSING STANDARDS PUBLICATION
Secure Hash Standard (SHS)
CATEGORY: COMPUTER SECURITY SUBCATEGORY: CRYPTOGRAPHY
Information Technology Laboratory
National Institute of Standards and Technology
Gaithersburg, MD 20899-8900
March 2012 

2. The types of endians in different systems http://www.yolinux.com/TUTORIALS/Endian-Byte-Order.html

3. The test vectors used from this website https://www.di-mgt.com.au/sha_testvectors.html

4. The videos used for guides by Dr Ian McLoughlin
https://web.microsoftstream.com/video/db7c03be-5902-4575-9629-34d176ff1366?referrer=https://learnonline.gmit.ie/course/view.php?id=138
