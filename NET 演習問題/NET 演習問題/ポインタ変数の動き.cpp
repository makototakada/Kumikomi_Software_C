#include <stdio.h>

int main(void) {

	int a, b;
	int *p;

	a = 100;
	p = &a;
	b = *p;

	printf("���݃|�C���^ p �͕ϐ� a �̃A�h���X�������Ă���\n");
	printf("�A�h���X�F&a = %X, &b = %X, p = %X\n", &a, &b, p);
	printf("   �l   �Fa = %d,   b = %d, *p = %d\n\n", a, b, *p);

	a = 200;
	b = 300;

	printf("���݃|�C���^ p �͕ϐ� a �̃A�h���X�������Ă���\n");
	printf("�A�h���X�F&a = %X, &b = %X, p = %X\n", &a, &b, p);
	printf("   �l   �Fa = %d,   b = %d, *p = %d\n\n", a, b, *p);

	p = &b;

	printf("���݃|�C���^ p �͕ϐ� b �̃A�h���X�������Ă���\n");
	printf("�A�h���X�F&a = %X, &b = %X, p = %X\n", &a, &b, p);
	printf("   �l   �Fa = %d,   b = %d, *p = %d\n\n", a, b, *p);

	return 0;
}