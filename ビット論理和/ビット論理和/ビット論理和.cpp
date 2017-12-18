#include <stdio.h>

void orTest(int a, int b);

int main(void) {

	orTest(0x0f, 0x01);
	orTest(0x0f, 0x0f);
	orTest(0x0f, 0x00);
	orTest(0x0f, 0x07);
	orTest(0x0f, 0xaa);

	return 0;
}

void orTest(int a, int b) {
	
	printf("0x%02x | 0x%02x => 0x%02x\n", a, b, (a | b));
}