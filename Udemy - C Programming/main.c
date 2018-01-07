#include <stdio.h>

int array1[5] = { 1,2,3,4,5 };
double doublearray[] = { 1.0, 1.1, 1.2, 1.3 };
char chararray1[] = { 'h', 'e', 'l', 'l', 'o', '\0' };
char chararray2[] = "world";

int main(int argc, char **argv) {
	int i = 0;

	printf("--- do...while loop --- \n");
	do {
		printf("%d\n", array1[i]);
		i++;
	} while (i < 5);

	return 0;
}
