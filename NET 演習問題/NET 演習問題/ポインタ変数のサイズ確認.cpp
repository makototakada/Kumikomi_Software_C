#include <stdio.h>

int main(void) {

	char   a, *pa;
	int    b, *pb;
	float  c, *pc;
	double d, *pd;

	// sizeof() : メモリで占めるバイト数を知るための演算子

	printf("size of a  = %d byte\n", sizeof(a));
	printf("size of pa = %d byte\n", sizeof(pa));

	printf("size of b  = %d byte\n", sizeof(b));
	printf("size of pb = %d byte\n", sizeof(pb));

	printf("size of c  = %d byte\n", sizeof(c));
	printf("size of pc = %d byte\n", sizeof(pc));

	printf("size of d  = %d byte\n", sizeof(d));
	printf("size of pd = %d byte\n", sizeof(pd));

	return 0;
}