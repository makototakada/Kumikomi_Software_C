#include <stdio.h>

/*���p�̂̌^�g�̐錾*/

union smpl {

	long l;
	int i;
	char c;

};

int main(void) {

	/*���p�̂̐錾�Ə�����*/

	/*(long�^�����o1�ւ̏�����)*/
	union smpl dt = { 0x11111111 };

	/*���p�̂̎Q��*/
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