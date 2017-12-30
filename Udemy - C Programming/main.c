#include <stdio.h>

int main(int argc, char **argv)
{
	double pettycash;
	double grandtotal;
	// or double pettycash, grandtotal
	// or assign default value: double grandtotal = 500.50;

	grandtotal = 500.50;
	pettycash = 10.5;
	printf("pettycash=%.2f\n", pettycash);
	pettycash = 100.25;
	printf("pettycash=%.2f\n", pettycash);
	printf("grandtotal=%.2f\n", grandtotal);
	return 0;
}
