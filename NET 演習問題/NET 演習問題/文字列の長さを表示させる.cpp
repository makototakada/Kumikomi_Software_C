#include <stdio.h>

int main(void) {

	char name[] = "Wakaba-ku";
	char *p;
	int n = 0;

	for (p = name; *p != '\0'; p++) {

		n++;

	}

	printf("n = %d\n", n);

	return 0;
}