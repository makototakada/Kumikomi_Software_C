#include <stdio.h>

void lShiftTest(unsigned int a, int b);
void rShiftTest(unsigned int a, int b);

int main(void) {

	lShiftTest(0x0f, 1);
	lShiftTest(0x0f, 4);
	lShiftTest(0x0f, 5);
	printf("\n");
	rShiftTest(0x0f, 1);
	rShiftTest(0x0f, 4);
	rShiftTest(0x0f, 0);

	return 0;
}

void lShiftTest(unsigned int a, int b) {

	printf("0x%02x << %d => 0x%02x\n", a, b, (a << b));
}
void rShiftTest(unsigned int a, int b) {

	printf("0x%02x >> %d => 0x%02x\n", a, b, (a >> b));
}