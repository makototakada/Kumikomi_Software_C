#include <stdio.h>

int main(void) {

	int i;
	char name[] = "Tokyo Joho University";
	char *p;

	p = name;

	printf("*** �P�[�X1 ***\n");
	printf("�A�h���X�Fname = %X, p = %X\n", name, p);
	printf("   �l   �Fname = %s, p = %s\n\n", name, p);

	printf("*** �P�[�X2 ***\n");
	putchar(*p);
	putchar(*(p + 1));
	putchar(*(p + 2));
	putchar(*(p + 3));
	putchar(*(p + 4));
	putchar(*(p + 5));
	putchar(*(p + 6));
	printf("\n\n");

	printf("*** �P�[�X3 ***\n");
	i = 0;
	while (name[i]) {

		name[i] = name[i] + 1;
		i++;

	}

	printf("   �l   �Fname = %s\n\n", name);

	printf("*** �P�[�X4 ***\n");
	while (*p) {

		*p = *p - 1;
		p++;

	}

	printf("   �l   �Fname = %s\n\n", name);

	return 0;
}