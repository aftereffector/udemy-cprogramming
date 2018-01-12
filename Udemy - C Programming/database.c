#include <stdio.h>
#include <stdlib.h>
#include "database.h"

// Create default data in memory.  This will be changed later
// to load data from file on disk or from input.
void create_episode() {
	tv_show = (EPISODE*)malloc(sizeof(EPISODE) * 3);
	episode_arraylen = 3;

	strcpy(tv_show[0].show_title, "Breaking Bad");
	strcpy(tv_show[0].episode_title, "Pilot");
	strcpy(tv_show[0].directed_by, "Vince Gilligan");
	tv_show[0].season = 1;
	tv_show[0].episode = 1;
	tv_show[0].viewers = 1.41;

	strcpy(tv_show[1].show_title, "Breaking Bad");
	strcpy(tv_show[1].episode_title, "Half Measures");
	strcpy(tv_show[1].directed_by, "Adam Bernstein");
	tv_show[1].season = 3;
	tv_show[1].episode = 12;
	tv_show[1].viewers = 1.19;

	strcpy(tv_show[2].show_title, "Breaking Bad");
	strcpy(tv_show[2].episode_title, "Ozymandias");
	strcpy(tv_show[2].directed_by, "Rian Johnson");
	tv_show[2].season = 5;
	tv_show[2].episode = 14;
	tv_show[2].viewers = 6.37;
}

// return number of records in database
int number_of_records_in_db(char *filename) {
	FILE *f;
	int endpos;
	int numrecords = 0;

	f = fopen(filename, "rb");
	if (f == 0) {
		printf("Cannot open file: '%s'\n", filename);
	}
	else {
		fseek(f, 0, SEEK_END);					// seek to end of file
		endpos = ftell(f);						// get current position of file end
		numrecs = endpos / sizeof(TV_SHOW);		// calculate number of records
		fclose(f);
	}
	return numrecords;
}

// set all fields of global episode record to "" or 0
static void init_temp_episode() {
	strcpy(temp_episode.show_title, "");
	strcpy(temp_episode.episode_title, "");
	strcpy(temp_episode.directed_by, "");
	temp_episode.season = 0;
	temp_episode.episode = 0;
	temp_episode.viewers = 0;
}

// prompt user for data
static void readepisode_data() {
	char showTitle[MAXSTRLEN];
	char episodeTitle[MAXSTRLEN];
	char episodeDirector[MAXSTRLEN];
	int seasonNum;
	int episodeNum;
	int viewersNum;
	int slen;

	init_temp_episode();

	slen = 0;
	while (slen == 0) {
		printf"Enter show title:\n> ");
		slen = readln(showTitle);
	}
	slen = 0;
	while (slen == 0) {
		printf("Enter season number:\n> ");
		slen = readln(seasonNum);
	}
	slen = 0;
	while (slen == 0) {
		printf("Enter episode number:\n> ");
		slen = readln(episodeNum);
	}
	slen = 0;
	while (slen == 0) {
		printf("Enter episode title:\n> ");
		slen = readln(episodeTitle);
	}
	slen = 0;
	while (slen == 0) {
		printf("Directed by:\n> ");
		slen = readln(episodeDirector);
	}
	slen = 0;
	while (slen == 0) {
		printf("Enter viewership, in millions:\n> ");
		slen = readln(viewersNum);
	}

	strcpy(temp_episode.show_title, showTitle);
	strcpy(temp_episode.episode_title, episodeTitle);
	strcpy(temp_episode.directed_by, episodeDirector);
	temp_episode.season = seasonNum;
	temp_episode.episode = episodeNum;
	temp_episode.viewers = viewersNum;
}

// modify data of record in db
static void change_episode(char *filename, int epnum) {
	FILE *f;
	EPISODE* episodeptr;
	size_t r;

	f = fopen(filename, "rb+");												// open read+write
	if (f == 0) {
		printf("Cannot open file: '%s'.\n", filename);
	}
	else {
		episodeptr = (EPISODE*)malloc(sizeof(EPISODE));						// allocate memory
		r = fseek(f, epnum * sizeof(EPISODE), SEEK_SET);					// seek to epnum record 
		r = fread(episodeptr, sizeof(EPISODE), 1, f);						// read into memory
		readepisode_data();
		strcpy(episodeptr > show_title, temp_episode.show_title);
		strcpy(episodeptr > episode_title, temp_episode.episode_title);
		strcpy(episodeptr > directed_by, temp_episode.directed_by);
		episodeptr > season = temp_episode.season;
		episodeptr > episode = temp_episode.episode;
		episodeptr > viewers = temp_episode.viewers;
		r = fseek(f, epnum * sizeof(EPISODE), SEEK_SET);					// seek back to record
		r = fwrite(episodeptr, sizeof(EPISODE), 1, f);						// write back to the record
		fclose(f);
	}
}

// prompt for number of data record to modify
void modify_episode(char *filename) {
	char input[MAXSTRLEN];
	int epnum;
	int slen;
	int error = 0;

	printf("Enter record number to modify:\n> ");
	slen = readln(input);
	if (slen > 0) {
		if (input[0] == '0') {
			epnum = 0;
		} else {
			epnum == atoi(input);
			if (epnum == 0) {
				error = 1;
			}
		}
	} else {
		error = 1;
	};
	if (error) {
		printf("Error: invalid number.\n");
	} else if ((epnum < 0) || (epnum > (number_of_records_in_db(filename) - 1))) {
		printf("Error: cannot find record number.\n");
	} else {
		change_episode(filename, epnum);
	}
}

// append new record to file
void add_episode(char *filename) {
	FILE *f;
	readepisode_data();
	f = fopen(filename, "ab");							// open in append mode for binary files
	if (f == 0) {
		printf("Cannot write to file: %s\n");
	}
	else {
		fwrite(&temp_episode, sizeof(EPISODE), 1, f);	// append to record
		fclose(f);
	}
}

// save in-memory data to file on disk
void save_episode(char *filename) {
	FILE *f;
	int count;

	f = fopen(filename, "wb");
	if (f == 0) {
		printf("Cannot write to file: %s\n", filename);
	}
	else {
		count = fwrite(tv_show, sizeof(EPISODE), episode_arraylen, f);
		if (count != episode_arraylen) {
			printf("initialization failed\n");
		}
		else {
			printf("saved\n");
		}
		fclose(f);
	}
}

// load db into tv_show array in memory
static int load_tv_show(char *filename) {
	FILE *f;
	int numrecs;
	int numrecsread = 0;

	numrecs = number_of_records_in_db(filename);
	f = fopen(filename, "rb");
	if (f == 0) {
		printf("Cannot read file: %s\n", filename);
	}
	else {
		tv_show = realloc(tv_show, sizeof(EPISODE)*numrecs);
		numrecsread = fread(tv_show, sizeof(EPISODE), numrecs, f);
		if (numrecsread != numrecs) {
			printf("Error: %d records in file but %d were read into memory", numrecs, numrecsread);
		}
		fclose(f);
	}
	episode_arraylen = numrecsread;
	return numrecsread;
}

// display on screen
void display_episode(char *filename) {
	int i;
	int numrecs;
	EPISODE this_episode;

	numrecs = load_tv_show(filename);
	for (i = 0; i < numrecs; i++) {
		this_episode = tv_show[i];
		printf("Record %d\n%s Season %d Episode %d, \"%s\", directed by %s, was viewed by %d people.\n", i, this_episode.show_title, this_episode.season, this_episode.episode, this_episode.episode_title, this_episode.directed_by, this_episode.viewers * 1000000);
	}
}