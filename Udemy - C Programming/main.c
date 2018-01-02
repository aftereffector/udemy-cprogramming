#include <stdio.h>

int array1[5];

int main(int argc, char **argv) {
	int i;

	array1[0] = 11;
	array1[1] = 22;
	array1[2] = 33;
	array1[3] = 44;
	array1[4] = 55;

	for (i = 0; i < 5; i++) {
		printf("%d\n", array1[i]);
	}
	printf("Input array position to display value:\n");
	printf("The value of the array at position %d is %d.\n", 3, array1[3]);
	return 0;
}
