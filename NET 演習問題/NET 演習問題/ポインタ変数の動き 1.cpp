#include <stdio.h>

int main(void) {

	int a, b;
	int *p;

	a = 100;
	p = &a;
	b = *p;

	printf("現在のポインタ p は変数 a のアドレスを示している\n");
	printf("アドレス：&a = %X, &b = %X, p = %X\n", &a, &b, p);
	printf("   値   ： a = %6d,  b = %6d, *p = %5d\n\n", a, b, *p);

	a = 200;
	b = 300;

	printf("現在のポインタ p は変数 a のアドレスを示している\n");
	printf("アドレス：&a = %X, &b = %X, p = %X\n", &a, &b, p);
	printf("   値   ： a = %6d,  b = %6d, *p = %5d\n\n", a, b, *p);

	p = &b;

	printf("現在のポインタ p は変数 a のアドレスを示している\n");
	printf("アドレス：&a = %X, &b = %X, p = %X\n", &a, &b, p);
	printf("   値   ： a = %6d,  b = %6d, *p = %5d\n\n", a, b, *p);

	return 0;
}