#include <stdio.h>

char *chartype;

void findchartype(int i) {
	switch(i){
		case 0:
			chartype = "NULL";
			break;
		case 7:
			chartype = "Bell";
			break;
		case 8:
			chartype = "Backspace";
			break;
		case 9:
			chartype = "Tab";
			break;
		case 10:
			chartype = "Linefeed";
			break;
		case 13:
			chartype = "Carriage Return";
			break;
		case 32:
			chartype = "Space";
			break;
		case 48 ... 57:
			chartype = "Number";
			break;
		default:
			chartype = "Character (default)";
			break;
	}
}

void showascii() {
	int i;
	char c;
	for (i = 0; i <= 127; i++) {
		findchartype(i);
		printf("%d = %c\t\t[%s]\n", i, i, chartype);
	}
}

int main(int argc, char **argv) {
	showascii();
	return 0;
}
