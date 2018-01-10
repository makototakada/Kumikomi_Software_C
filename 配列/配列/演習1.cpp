/*”z—ñ‚ÉŠi”[‚³‚ê‚½©‘R”‚ÌÅ‘å’l‚ğ‹‚ß‚é*/
#include <stdio.h>

#define ARY_SIZE (12)

int iary[ARY_SIZE] = { 5, 7, 10, 1, 25, 15, 30, 10, 31, 13, 22, 32 };

int findMax(int ary[], int n);

int main(void) {

	int max;

	max = findMax(iary, ARY_SIZE);
	printf("Max = %d\n", max);

	return 0;
}

int findMax(int ary[], int n) {

	int max;
	int i;

	max = -1;
	for (i = 0; i < n; i++) {

		if (ary[i] > max) {

			max = ary[i];

		}

	}
	return (max);
}