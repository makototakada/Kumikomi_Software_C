#include <stdio.h>

void andTest(int a, int b);

int main(void) {

	andTest(0x0f, 0x01);
	andTest(0x0f, 0x0f);
	andTest(0x0f, 0x00);
	andTest(0x0f, 0x07);


	return 0;
}

void andTest(int a, int b) {

	printf("0x%02x & 0x%02x => 0x%02x\n", a, b, (a & b));
}