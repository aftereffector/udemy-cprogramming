#include <stdio.h>

char plaintext[] = "The quick brown fox jumps over the lazy dog.";

void encryptWithWhile() {
	int i = 0;
	char ciphertext[50];
	char c;

	//Encrypt string
	while (i >= 0) {
		c = plaintext[i];
		// Continue does not work with while() loops
		/*
		if (c == ' ') {
			ciphertext[i] = c;
			continue;
		}
		*/
		if (c == '.') {
			ciphertext[i] = '\0';
			break;
		}
		ciphertext[i] = plaintext[i] + 1;
		i++;
	}
	printf("Encrypted string is '%s'\n", ciphertext);

	//Decrypt string
	int n = 0;
	char plaintext2[50];
	char d;
	while (n >= 0) {
		d = ciphertext[n];
		// Continue does not work with while() loops
		/*
		if (d == ' ') {
			plaintext2[n] = d;
			continue;
		}
		*/
		if (d == '\0') {
			plaintext2[n] = '.';
			break;
		}
		plaintext2[n] = ciphertext[n] - 1;
		n++;
	}
	printf("Decrypted string is '%s'\n", plaintext2);
}

int main(int argc, char **argv) {
	printf("Plaintext string is '%s'\n", plaintext);
	encryptWithWhile();
	return 0;
}
