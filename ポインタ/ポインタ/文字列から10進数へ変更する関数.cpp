#include <stdio.h>
#include <ctype.h>

long int myatoi(const char *);

int main(void) {

	char str1[] = "123";
	char str2[] = "+234";
	char str3[] = "   -234";
	char str4[] = "   -123abc";
	char str5[] = "   - 123";
	char str6[] = "   ";
	int n;

	n = myatoi(str1);
	printf("myatoi(str1) returns %d\n", n);

	n = myatoi(str2);
	printf("myatoi(str2) returns %d\n", n);

	n = myatoi(str3);
	printf("myatoi(str3) returns %d\n", n);

	n = myatoi(str4);
	printf("myatoi(str4) returns %d\n", n);

	n = myatoi(str5);
	printf("myatoi(str5) returns %d\n", n);

	n = myatoi(str6);
	printf("myatoi(str6) returns %d\n", n);

	return 0;
}

#define POSITIVE  0
#define NEGATIVE -1

long int myatoi(const char *str) {

	int flag;
	long int value;

	flag = POSITIVE;
	value = 0;

	while (isspace(*str)) {

		str++;

	}
	switch (*str) {

	case '+':
		str++;
		break;
	case '-':
		flag = NEGATIVE;
		str++;
		break;
	default:
		break;

	}
	while (isdigit(*str)) {

		value = value * 10 + (*str - '0');
		str++;

	}
	if (flag == POSITIVE) {

		return(value);

	}
	else {

		return(-value);

	}

}