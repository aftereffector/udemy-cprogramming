#pragma once

typedef char Str50[50];

typedef struct episode {
	Str50 show_title;
	Str50 episode_title;
	Str50 directed_by;
	int season;
	int episode;
	double viewers;
} EPISODE;

EPISODE *tv_show;
EPISODE temp_episode;

void create_episode();
void display_episode();
void add_episode(char*);
void modify_episode(char*);
void save_episode(char*);
int number_of_records_in_db(char*);
int episode_arraylen;