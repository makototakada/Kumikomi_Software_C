#include <stdio.h>

void xorTest(int a, int b);

int main(void) {

	xorTest(0x0f, 0x01);
	xorTest(0x0f, 0x0f);
	xorTest(0x0f, 0x00);
	xorTest(0x0f, 0x07);
	xorTest(0x0f, 0xaa);

	return 0;
}

void xorTest(int a, int b) {

	printf("0x%2x ^ 0x%02x => 0x%02x\n", a, b, (a ^ b));
}