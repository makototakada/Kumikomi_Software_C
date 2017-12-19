#include <stdio.h>

/*共用体の型枠の宣言*/

union smpl {

	long l;
	int i;
	char c;

};

int main(void) {

	/*共用体の宣言と初期化*/

	/*(long型メンバ1への初期化)*/
	union smpl dt = { 0x11111111 };

	/*共用体の参照*/
	printf("dt.l = 0x%lx\n", dt.l);
	printf("dt.i = 0x%x\n", dt.i);
	printf("dt.c = 0x%x\n", dt.c);

	dt.c = 0x22;
	printf("\ndt.l = 0x%lx\n", dt.l);
	printf("dt.i = 0x%x\n", dt.i);
	printf("dt.c = 0x%x\n", dt.c);

	dt.i = 0x3333;
	printf("\ndt.l = 0x%lx\n", dt.l);
	printf("dt.i = 0x%x\n", dt.i);
	printf("dt.c = 0x%x\n", dt.c);

	dt.l = 0x44444444;
	printf("\ndt.l = 0x%lx\n", dt.l);
	printf("dt.i = 0x%x\n", dt.i);
	printf("dt.c = 0x%x\n", dt.c);

	return 0;
}