#include <stdio.h>

#define EOS ('\0')

char *mystrcpy(char *, const char *);

int main(void) {

	char str1[] = "123456";
	char str2[] = "XYZ";
	char str3[] = "123456";
	char str4[] = "XYZ\0ab";
	char str5[] = "XYZ\0abc";
	char str6[] = "12345";

	mystrcpy(str1, str2);
	printf("%02x%02x%02x%02x%02x%02x%02x\n", str1[0], str1[1], str1[2], str1[3], str1[4], str1[5], str1[6]);

	mystrcpy(str3, str4);
	printf("%02x%02x%02x%02x%02x%02x%02x\n", str3[0], str3[1], str3[2], str3[3], str3[4], str3[5], str3[6]);

	mystrcpy(str5, str6);
	printf("%02x%02x%02x%02x%02x%02x%02x\n", str5[0], str5[1], str5[2], str5[3], str5[4], str5[5], str5[6]);

	return 0;
}

char *mystrcpy(char *s1, const char *s2) {

	char *src = (char *)s2;
	char *dst = s1;
	char c;

	while ((*dst++ = *src++) != EOS) {

		;

	}

	return (s1);

}