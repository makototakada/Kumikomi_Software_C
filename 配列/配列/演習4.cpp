/*配列の要素を昇順にソートする関数*/
#include <stdio.h>

#define ARY_SIZE 10

int iary[ARY_SIZE] = { 5, 30, 10, 1, 25, 15, 7, 10, 31, 13 };

int findMin(int ary[], int n, int start);

void swap(int ary[], int i, int j);

int main(void) {

	int i, j;

	for (i = 0; i < ARY_SIZE - 1; i++) {

		j = findMin(iary, ARY_SIZE, i);
		swap(iary, i, j);
	}

	for (i = 0; i < ARY_SIZE; i++) {

		printf("%d, ", iary[i]);

	}
	printf("\n");

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

void swap(int ary[], int i, int j) {

	int tmp;

	tmp = ary[i];
	ary[i] = ary[j];
	ary[j] = tmp;

	return;
}