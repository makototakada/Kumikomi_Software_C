#include <stdio.h>

int main(void) {

	int i;
	char name[] = "Tokyo Joho University";
	char *p;

	p = name;

	printf("*** ケース1 ***\n");
	printf("アドレス：name = %X, p = %X\n", name, p);
	printf("   値   ：name = %s, p = %s\n\n", name, p);

	printf("*** ケース2 ***\n");
	putchar(*p);
	putchar(*(p + 1));
	putchar(*(p + 2));
	putchar(*(p + 3));
	putchar(*(p + 4));
	putchar(*(p + 5));
	putchar(*(p + 6));
	printf("\n\n");

	printf("*** ケース3 ***\n");
	i = 0;
	while (name[i]) {

		name[i] = name[i] + 1;
		i++;

	}

	printf("   値   ：name = %s\n\n", name);

	printf("*** ケース4 ***\n");
	while (*p) {

		*p = *p - 1;
		p++;

	}

	printf("   値   ：name = %s\n\n", name);

	return 0;
}