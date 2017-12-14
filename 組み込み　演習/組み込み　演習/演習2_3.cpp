#include <stdio.h>

int main(void) {

	int a;
	int b;

	printf("Please input (>0) : ");
	scanf_s("%d", &a);

	if (a < 1) {
		printf("Bad input\n");
	}
	else {
		b = a * 2;
		printf("Your input value is %d, new value is %d\n", a, b);
	}

	return 0;
}