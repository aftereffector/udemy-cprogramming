#include <stdio.h>

int main(int argc, char **argv) {

	char str1[] = "Hello";
	char *str2 = "Hello";
	char str3[6];

	str3[0] = 'H';
	str3[1] = 'e';
	str3[2] = 'l';
	str3[3] = 'l';
	str3[4] = 'o';
	str3[5] = '\0';

	printf("%x %s\n", str1, str1);
	printf("%x %s\n", str2, str2);
	printf("%x %s\n", str3, str3);

	printf("%x, %x, %x, %x, %x, %x\n", &str3[0], &str3[1], &str3[2], &str3[3], &str3[4], &str3[5]);
	printf("%x, %x, %x, %x, %x, %x\n", str3, str3 + 1, str3 + 2, str3 + 3, str3 + 4, str3 + 5);

	str2 = "Goodbye";
	printf("str2 - %s\n", str2);
	
	return 0;
}
