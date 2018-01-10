/*Å¬‚Ì”z—ñ‚Ì“Yš‚ğ–ß‚è’l‚Æ‚µ‚Ä•Ô‚·ŠÖ”*/
#include <stdio.h>


#define ARY_SIZE 10

int iary[ARY_SIZE] = { 5, 30, 10, 1, 25, 15, 7, 10, 31, 13 };

int findMin(int ary[], int n, int start);

int main(void) {

	int i;

	i = findMin(iary, ARY_SIZE, 0);
	printf("Min = %d [index %d]\n", iary[i], i);

	i = findMin(iary, ARY_SIZE, 4);
	printf("Min = %d [index %d]\n", iary[i], i);

	return 0;
}

int findMin(int ary[], int n, int start) {

	int min;
	int i;

	min = start;
	for (i = start + 1; i < n; i++) {

		if (ary[i] < ary[min]) {

			min = i;

		}

	}

	return (min);
}