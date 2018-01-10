#include <stdio.h>
#include <string.h>

#define NUMBER_OF_CDS 2

enum score {
	Terrible, Bad, Average, Good, Excellent
};

typedef struct cd {
	char name[50];
	char artist[50];
	int trackcount;
	enum score rating;
} CD;

struct cd my_cd_collection[NUMBER_OF_CDS];

void create_cdcollection() {
	strcpy_s(my_cd_collection[0].name, 50, "Wonder What's Next");
	strcpy_s(my_cd_collection[0].artist, 50, "Chevelle");
	my_cd_collection[0].trackcount = 9;
	my_cd_collection[0].rating = Excellent;

	strcpy_s(my_cd_collection[1].name, 50, "Koi No Yokan");
	strcpy_s(my_cd_collection[1].artist, 50, "Deftones");
	my_cd_collection[1].trackcount = 13;
	my_cd_collection[1].rating = Good;
}

void display_cdcollection() {
	int i = 0;
	struct cd thiscd;
	while (i < NUMBER_OF_CDS) {
		thiscd = my_cd_collection[i];
		printf("CD #%d: '%s' by %s has %d tracks.  My rating is %d/5.\n", i+1, thiscd.name, thiscd.artist, thiscd.trackcount, thiscd.rating);
		i++;
	}
}

int main(int argc, char **argv) {
	create_cdcollection();
	display_cdcollection();
	return 0;
}
