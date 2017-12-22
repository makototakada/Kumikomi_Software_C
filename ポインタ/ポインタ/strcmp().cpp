#include <stdio.h>
#include <string.h>

#define EOS ('\0')

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

	n = strcmp(str1, str2);
	printf("strcmp(str1, str2) returns %d\n", n);

	n = strcmp(str3, str4);
	printf("strcmp(str3, str4) returns %d\n", n);

	n = strcmp(str5, str6);
	printf("strcmp(str5, str6) returns %d\n", n);

	n = strcmp(str7, str8);
	printf("strcmp(str7, str8) returns %d\n", n);

	n = strcmp(str9, str10);
	printf("strcmp(str9, str10) returns %d\n", n);

	return 0;
}