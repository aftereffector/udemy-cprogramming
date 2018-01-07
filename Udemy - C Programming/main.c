#include <stdio.h>

char plaintext[] = "The quick brown fox jumps over the lazy dog.";

void encryptWithFor() {
	int i;
	char ciphertext[50];
	char c;

	//Encrypt string
	for (i = 0; i < 50; i++) {
		c = plaintext[i];
		if (c == ' ') {
			ciphertext[i] = c;
			continue;
		}
		if (c == '.') {
			ciphertext[i] = '\0';
			break;
		}
		ciphertext[i] = plaintext[i] + 1;
	}
	printf("Encrypted string is '%s'\n", ciphertext);

	//Decrypt string
	int n;
	char plaintext2[50];
	char d;
	for (n = 0; n < 50; n++) {
		d = ciphertext[n];
		if (d == ' ') {
			plaintext2[n] = d;
			continue;
		}
		if (d == '\0') {
			plaintext2[n] = '.';
			break;
		}
		plaintext2[n] = ciphertext[n] - 1;
	}
	printf("Decrypted string is '%s'\n", plaintext2);
}

int main(int argc, char **argv) {
	printf("Plaintext string is '%s'\n", plaintext);
	encryptWithFor();
	return 0;
}
