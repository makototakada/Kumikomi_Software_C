#include <stdio.h>
#include <string.h>

#define BIRDTHDAY_SIZE 3
#define BOOKSIZE 128

struct addressSheet {

	const char *name;
	int group;
	const char *phone;
	const char *address;
	int birthday[BIRDTHDAY_SIZE];

};

#define NUM 4

struct addressSheet addressBook[BOOKSIZE] = {

	{ "Mary", 2, "075-123-1232",  "Aneyakouji,Shimogyo",{ 1983, 12,  1 } },
{ "John", 1, "075-123-2135",     "Rokkaku,Shimogyo",{ 1978,  5, 17 } },
{ "Tom", 3, "075-123-1234", "Takoyakushi,Shimogyo",{ 1980,  1, 15 } },
{ "Sam", 1, "075-321-2214",     "Nishiki,Shimogyo",{ 1979,  6, 15 } },

};

struct addressSheet *sortTable[BOOKSIZE];

void sortByName(struct addressSheet **, int);
int findMin(struct addressSheet **, int, int);
void swap(struct addressSheet **, int, int);
int compare(struct addressSheet *, struct addressSheet *);
void printSheet(struct addressSheet *);

int main(void) {

	int i;

	for (i = 0; i < NUM; i++) {

		sortTable[i] = &addressBook[i];

	}

	sortByName(sortTable, NUM);

	for (i = 0; i < NUM; i++) {

		printSheet(sortTable[i]);

	}

	return 0;
}

void sortByName(struct addressSheet *sheet[], int n) {

	int i, j;

	for (i = 0; i < n - 1; i++) {

		j = findMin(sheet, n, i);
		swap(sheet, i, j);

	}

	return;

}

int findMin(struct addressSheet *ary[], int n, int start) {

	int min;
	int i;

	min = start;
	for (i = start + 1; i < n; i++) {

		if (compare(ary[i], ary[min]) < 0) {

			min = i;
			printf("min update\n");
		}

	}

	return (min);

}

int compare(struct addressSheet *p, struct addressSheet *q) {

	return(strcmp(p->name, q->name));

}

void swap(struct addressSheet *ary[], int i, int j) {

	struct addressSheet *tmp;

	tmp = ary[i];
	ary[i] = ary[j];
	ary[j] = tmp;

	return;

}

void printSheet(struct addressSheet *sheet) {

	printf("NameF\t%s\n", sheet->name);
	printf("GroupF\t%d\n", sheet->group);
	printf("TelF\t%s\n", sheet->phone);
	printf("AddressF\t%s\n", sheet->address);
	printf("BirthdayF\t%d/%d/%d\n", sheet->birthday[0], sheet->birthday[1], sheet->birthday[2]);

	return;
}