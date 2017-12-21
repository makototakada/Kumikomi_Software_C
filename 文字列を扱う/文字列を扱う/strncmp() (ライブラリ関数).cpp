#include <stdio.h>
#include <string.h>

int main(void) {

	char str1[] = "XYZabc";
	char str2[] = "XYZ";
	char str3[] = "XYZabc";
	char str4[] = "XYZc";
	char str5[] = "XYZ5";
	char str6[] = "XYZ123";
	size_t len;

	len = strncmp(str1, str2, 2);
	printf("strncmp(str1, str2, 2) returns %2d\n", len);

	len = strncmp(str1, str2, 3);
	printf("strncmp(str1, str2, 3) returns %2d\n", len);

	len = strncmp(str1, str2, 5);
	printf("strncmp(str1, str2, 5) returns %2d\n", len);
	printf(" 'a' = %d\n", 'a');

	len = strncmp(str3, str4, 4);
	printf("strncmp(str3, str4, 4) returns %2d\n", len);

	len = strncmp(str5, str6, 4);
	printf("strncmp(str5, str6, 4) returns %2d\n", len);

	return 0;
}
/*�����񂪓������ꍇ�ɂ�0������ȊO�̏ꍇ�͔�0(��r���镶����̈قȂ�ŏ��̃y�A�̒l�̍�)�����ꂼ��Ԃ��B*/
/*�����y�A�̒l�̍��͐�ɏ������ق����������ŏ������Ƃ��͕��̒l�ŁA�傫���Ƃ��͐��̒l�ŕԂ��B*/