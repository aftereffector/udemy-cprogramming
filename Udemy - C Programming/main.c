#include <stdio.h>
#include "mystringfunctions.h"
#include "database.h"

#define filename "tv_show_database.bin"
#define backupfilename "tv_show_database.bak"

char getcommand() {
	char command[MAXSTRLEN];
	int commandlen;
	char c;

	commandlen = readln(command);
	if (commandlen != 1) {
		c = 'x';
	}
	else {
		c = command[0];
	}
	return c;
}

int main(int argc, char **argv) {
	int keepgoing = 1;

	create_episode();
	while (keepgoing) {
		printf("\nCommands: 'a'=add record, 'd'=display records, 'm'=modify record");
		printf("\n          'n'=number of records, 's'=save backup (from memory)\n> ");
		switch (getcommand()) {
		case 'a':
			printf("Add record\n");
			add_episode(filename);
			break;
		case 'd':
			printf("Display records\n");
			display_episode(filename);
			break;
		case 'm':
			printf("Modify records\n");
			modify_episode(filename);
			break;
		case 'n':
			printf("Show number of records\n");
			printf("Database contains %d records\n", number_of_records_in_db);
			break;
		case 's':
			printf("Save backup\n");
			save_episode(backupfilename);
			break;
		case 'q':
			printf("Ending...\n");
			keepgoing = 0;
			break;
		default:
			printf("Invalid command.\n");
			break;
		}
	}
	return 0;
}
