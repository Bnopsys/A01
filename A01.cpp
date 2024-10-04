// Name: Roderick Stones
// SSID: *******
// Assignment #: 1
// Submission Date: 9/29/2024
//
// Description: A program to encrypt and decrypt a message using a shift cipher
// The plaintext message must only contain lowercase alpha and digits 0-9
//
// command line arguments
// -p theplaintextmessage1 - the plaintext (p) message to be encrypted
// -c PDALH7EJPATPIAOO7CA@ - the cipher (c) text to be decrypted
// -k 9                    - the key (k) shift value
// -e                      - the option to encrypt (e)
// -d                      - the option to decrypt (d)
//

#include <iostream> //std::cout, std::cin, etc.
#include <cstdlib>  //C++ version of stdlib.h
#include <cstring>  //C++ version of string.h
#include <string>   //C++ string library
//todo: add other includes you may need

//Command line args reference:
//https://docs.microsoft.com/en-us/cpp/cpp/main-function-command-line-args
int main(int argc, char* argv[])
{
	// Insufficient arguments, exit program
	if (argc < 6) {
		std::cerr << "Error: Insufficient arguments.\n";
		return -1;
	}

	char codebook[] = {'z', 'Z', 'y', 'Y', 'x', 'X', 'w', 'W', 'v', 'V', 'u', 'U', 't', 'T', 's', 'S', 'r', 'R', 'q', 'Q', 'p', 'P', 'o', 'O', 
    'n', 'N', 'm', 'M', 'l', 'L', 'k', 'K', 'j', 'J', 'i', 'I', 'h', 'H', 'g', 'G', 'f', 'F', 'e', 'E', 'd', 'D', 'c', 'C', 'b', 'B', 'a', 'A', '0', 
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '@', ']'};

	// Example variable declaration
	std::string msg;      // string to store argv[msg_index]
	int k = 0; 			  // shift amount
	bool encrypt = false; // perform encryption set to true
	bool decrypt = false; // perform decryption set to true
	int shift_value = 0;
	
	// Example command line argument processing using a loop
	for (int i = 1; i < argc; i++) {
		if ((std::strcmp(argv[i], "-p") == 0) || (std::strcmp(argv[i], "-c") == 0)){
			msg = argv[++i]; //store the text in string msg
			}
		else if (std::strcmp(argv[i], "-e") == 0){
			encrypt = true;
		}
		else if (std::strcmp(argv[i], "-d") == 0){
			decrypt = true;
		}
		else if (std::strcmp(argv[i], "-k") == 0){
			std::string str_shift_val = argv[++i];
			shift_value = stoi(str_shift_val);
		}
	}
	int CBL = 64;
	
	// A1 todo: -e encrypt the plaintext with key value k
	if (encrypt) {
		for (int i = 0; i < msg.length(); i++){
			for (int CB_index = 0; CB_index < CBL; CB_index++){
				if (msg[i] == codebook[CB_index]){
					int shifted_index = (CB_index + shift_value) % CBL;
					msg[i] = codebook[shifted_index];
					break;
					
				}
			}
		}
	}

	// A1 todo: -d decrypt the ciphertext -c with key value k
	if (decrypt) {
		for (int i = 0; i < msg.length(); i++){
			for (int CB_index = 0; CB_index < CBL; CB_index++){
				if (msg[i] == codebook[CB_index]){
					int shifted_index = (CB_index - shift_value + CBL) % CBL;
					msg[i] = codebook[shifted_index];
					break;
				}
			}
		}
	}

	// print out the ciphertext or plaintext using standard-out
	std::cout << msg << std::endl;

	return 0;
}//main