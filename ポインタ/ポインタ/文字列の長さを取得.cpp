/*#include <stdio.h>

#define EOS ('\0')
size_t mystrlen(const char *);

int main(void) {

	char str1[] = "12345";
	char str2[] = " ";
	char str3[] = "";
	int len;

	len = mystrlen(str1);
	printf("mystrlen(str1) returns %d\n", len);

	len = mystrlen(str2);
	printf("mystrlen(str2) returns %d\n", len);

	len = mystrlen(str3);
	printf("mystrlen(str3) returns %d\n", len);


	return 0;
}

size_t mystrlen(const char *s) {

	size_t len = 0;

	while (*s++ != EOS) {

		len++;

	}

	return (len);
}*/