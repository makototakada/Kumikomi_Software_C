#include <stdio.h>

void notTest(int a);

int main(void) {

	notTest(0x00);
	notTest(0x01);
	notTest(0x07);
	notTest(0xF0);
	notTest(0xFF);

	return 0;
}

void notTest(int a) {

	printf("~0x%08x => 0x%08x\n", a, ~a);
}