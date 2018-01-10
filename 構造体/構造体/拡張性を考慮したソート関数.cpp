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

	{ "Mary", 2, "075-123-1232", "Aneyakouji,Shimogyo",{ 1983, 12, 1 } },
{ "John", 1, "075-123-2135", "Rokkaku,Shimogyo",{ 1978, 5, 17 } },
{ "Tom", 3, "075-123-1234", "Takoyakushi,Shimogyo",{ 1980, 1, 15 } },
{ "Sam", 1, "075-321-2214", "Nishiki,Shimogyo",{ 1979, 6, 25 } },

};

struct addressSheet *sortTable[BOOKSIZE];

void sortAddressBook(struct addressSheet **, int, int(*)(struct addressSheet *, struct addressSheet *));
int findMin(struct addressSheet **, int, int, int(*)(struct addressSheet *, struct addressSheet *));
int compareName(struct addressSheet *, struct addressSheet *);
int compareGroup(struct addressSheet *, struct addressSheet *);
int compareBirthday(struct addressSheet *, struct addressSheet *);
void swap(struct addressSheet **, int, int);
void printSheet(struct addressSheet *);

int compareName(struct addressSheet *p, struct addressSheet *q) {

	return(strcmp(p->name, q->name));

}

int compareGroup(struct addressSheet *p, struct addressSheet *q) {

	return(p->group - q->group);

}

int compareBirthday(struct addressSheet *p, struct addressSheet *q) {

	int i;
	int diff;

	for (i = 0; i < BIRDTHDAY_SIZE; i++) {

		diff = p->birthday[i] - q->birthday[i];
		if (diff != 0) {

			return (diff);

		}

	}

	return 0;
}

int main(void) {

	int i;

	for (i = 0; i < NUM; i++) {

		sortTable[i] = &addressBook[i];

	}

	sortAddressBook(sortTable, NUM, compareName);

	for (i = 0; i < NUM; i++) {

		printSheet(sortTable[i]);

	}

	sortAddressBook(sortTable, NUM, compareBirthday);

	for (i = 0; i < NUM; i++) {

		printSheet(sortTable[i]);

	}

	return 0;
}

void sortAddressBook(struct addressSheet *sheet[], int n, int(*cmp)(struct addressSheet *, struct addressSheet *)) {

	int i, j;

	for (i = 0; i < n - 1; i++) {

		j = findMin(sheet, n, i, cmp);
		swap(sheet, i, j);

	}

	return;
}

int findMin(struct addressSheet *ary[], int n, int start, int(*cmp)(struct addressSheet *, struct addressSheet *)) {

	int min;
	int i;

	min = start;
	for (i = start + 1; i < n; i++) {

		if ((*cmp)(ary[i], ary[min]) < 0) {

			min = i;

		}

	}

	return (min);
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