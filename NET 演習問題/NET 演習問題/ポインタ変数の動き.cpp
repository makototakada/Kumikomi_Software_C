#include <stdio.h>

int main(void) {

	int a, b;
	int *p;

	a = 100;
	p = &a;
	b = *p;

	printf("現在ポインタ p は変数 a のアドレスを示している\n");
	printf("アドレス：&a = %X, &b = %X, p = %X\n", &a, &b, p);
	printf("   値   ：a = %d,   b = %d, *p = %d\n\n", a, b, *p);

	a = 200;
	b = 300;

	printf("現在ポインタ p は変数 a のアドレスを示している\n");
	printf("アドレス：&a = %X, &b = %X, p = %X\n", &a, &b, p);
	printf("   値   ：a = %d,   b = %d, *p = %d\n\n", a, b, *p);

	p = &b;

	printf("現在ポインタ p は変数 b のアドレスを示している\n");
	printf("アドレス：&a = %X, &b = %X, p = %X\n", &a, &b, p);
	printf("   値   ：a = %d,   b = %d, *p = %d\n\n", a, b, *p);

	return 0;
}