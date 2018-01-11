#include <stdio.h>

int main(void) {

	char name[] = "Wakaba-ku";
	char *p;

	for (p = name; *p != '\0'; p++) {

		printf("%c\n", *p);

	}

	return 0;
}