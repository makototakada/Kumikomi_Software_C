#include <stdio.h>

#define EOS ('\0')

int mystrncmp(const char s1[], const char s2[], size_t n);

int main(void) {

	char str1[] = "XYZabc";
	char str2[] = "XYZ";
	char str3[] = "XYZabc";
	char str4[] = "XYZc";
	char str5[] = "XYZ5";
	char str6[] = "XYZ123";
	size_t len;

	len = mystrncmp(str1, str2, 2);
	printf("mystrncmp(str1, str2, 2) returns %2d\n", len);

	len = mystrncmp(str1, str2, 3);
	printf("mystrncmp(str1, str2, 3) returns %2d\n", len);

	len = mystrncmp(str1, str2, 5);
	printf("mystrncmp(str1, str2, 5) returns %2d\n", len);
	printf(" 'a' = %d\n", 'a');

	len = mystrncmp(str3, str4, 4);
	printf("mystrncmp(str3, str4, 4) returns %2d\n", len);

	len = mystrncmp(str5, str6, 4);
	printf("mystrncmp(str5, str6, 4) returns %2d\n", len);

	len = mystrncmp(str5, str6, 0);
	printf("mystrncmp(str5, str6, 0) returns %2d\n", len);

	return 0;
}

int mystrncmp(const char s1[], const char s2[], size_t n) {

	unsigned char c1 = EOS;
	unsigned char c2 = EOS;
	int i;

	for (i = 0; i < (int)n; i++) {

		c1 = (unsigned char)s1[i];
		c2 = (unsigned char)s2[i];

		if ((c1 == EOS) || (c1 != c2)) {

			return (c1 - c2);

		}

	}

	return (c1 - c2);

}