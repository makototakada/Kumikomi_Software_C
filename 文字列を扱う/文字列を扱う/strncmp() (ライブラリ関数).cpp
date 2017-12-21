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
/*文字列が等しい場合には0をそれ以外の場合は非0(比較する文字列の異なる最初のペアの値の差)をそれぞれ返す。*/
/*文字ペアの値の差は先に書いたほうが辞書順で小さいときは負の値で、大きいときは正の値で返す。*/