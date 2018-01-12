#include <stdio.h>
#include <string.h>
#include "mystringfunctions.h"

// read line from input and return length of string
int readln(char s[]) {
	char ch;
	int i;
	int chars_remaining;

	i = 0;
	chars_remaining = 1;
	while (chars_remaining) {
		ch = getchar();
		if ((ch == '\n') || (ch == EOF)) {
			chars_remaining = 0;
		} else if (i < (MAXSTRLEN - 1)) {
			s[i] = ch;
			i++;
		}
	}
	s[i] = '\0';
	return i;
}

// return index of first char of searchstring in sourcestring
// return -1 if searchstring not found
int searchstring(char searchstr[], char sourcestr[]) {
	char *ptrtostr;
	int foundat;
	foundat = -1;
	ptrtostr = strstr(sourcestr, searchstr);
	if (ptrtostr != NULL) {
		foundat = (int)((ptrtostr - sourcestr));
	} else {
		printf("ptrtostr equals NULL\nSee line 33 in mystringfunctions.c\n");
	}
	return foundat;
}