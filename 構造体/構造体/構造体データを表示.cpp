#include <stdio.h>

#define BIRDTHDAY_SIZE 3
#define BOOKSIZE 128

struct addressSheet {

	const char *name;
	int group;
	const char *phone;
	const char *address;
	int birthday[BIRDTHDAY_SIZE];

};

struct addressSheet addressBook[BOOKSIZE] = {

	{ "Mary", 1, "075-123-1232",  "Aneyakouji,shimogyo",{ 1983, 12, 1 } },
{ "John", 1, "075-123-2135",     "Rokkaku,Shimogyo",{ 1978, 5, 17 } },
{ "Tom", 2, "075-123-1234", "Takoyakushi,Shimogyo",{ 1980, 1, 15 } }

};

void printSheet(struct addressSheet *);

int main(void) {

	printSheet(&addressBook[0]);
	printSheet(&addressBook[1]);
	printSheet(&addressBook[2]);

	return 0;
}

void printSheet(struct addressSheet *sheet) {

	printf("NameF\t%s\n", sheet->name);
	printf("GroupF\t%d\n", sheet->group);
	printf("TelF\t%s\n", sheet->phone);
	printf("AddressF\t%s\n", sheet->address);
	printf("BirthdayF\t%d/%d/%d\n", sheet->birthday[0], sheet->birthday[1], sheet->birthday[2]);

	return;
}