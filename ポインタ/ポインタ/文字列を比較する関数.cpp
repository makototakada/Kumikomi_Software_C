#include <stdio.h>

#define EOS ('\0')

int mystrcmp(const char *, const char *);

int main(void) {

	char str1[] = "XYZ";
	char str2[] = "XYZ";
	char str3[] = "";
	char str4[] = "";
	char str5[] = "XYZ";
	char str6[] = "XYZabc";
	char str7[] = "XYZ5";
	char str8[] = "XYZ123";
	char str9[] = "XYZ\0abc";
	char str10[] = "XYZ";
	int n;

	n = mystrcmp(str1, str2);
	printf("strcmp(str1, str2) returns %d\n", n);

	n = mystrcmp(str3, str4);
	printf("strcmp(str3, str4) returns %d\n", n);

	n = mystrcmp(str5, str6);
	printf("strcmp(str5, str6) returns %d\n", n);

	n = mystrcmp(str7, str8);
	printf("strcmp(str7, str8) returns %d\n", n);

	n = mystrcmp(str9, str10);
	printf("strcmp(str9, str10) returns %d\n", n);

	return 0;
}

int mystrcmp(const char *s1, const char *s2) {

	const unsigned char *p1 = (const unsigned char *)s1;
	const unsigned char *p2 = (const unsigned char *)s2;

	while (*p1 == *p2) {

		if (*p1 == EOS) {

			return (-(*p2));

		}
		p1++;
		p2++;

	}

	return((*p1) - (*p2));

}