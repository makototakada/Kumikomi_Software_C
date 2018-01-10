/*2‚Â‚Ì“Yš‚Ì”z—ñ‚Ì—v‘f‚ğŒğŠ·‚·‚éŠÖ”*/
#include <stdio.h>

#define ARY_SIZE 10

int iary[ARY_SIZE] = { 5, 30, 10, 1, 25, 15, 7, 10, 31, 13 };

void swap(int ary[], int i, int j);

int main(void) {

	int i;

	swap(iary, 0, 7);
	swap(iary, 4, 3);
	swap(iary, 5, 5);

	for (i = 0; i < ARY_SIZE; i++) {

		printf("%d, ", iary[i]);

	}
	printf("\n");

	return 0;
}

void swap(int ary[], int i, int j) {

	int tmp;

	tmp = ary[i];
	ary[i] = ary[j];
	ary[j] = tmp;

	return;
}