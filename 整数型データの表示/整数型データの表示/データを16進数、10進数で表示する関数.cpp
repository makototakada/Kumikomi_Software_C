#include <stdio.h>

#define ERROR_RETURN   -1
#define FLAG_NONE       0
#define FLAG_ZERO       1
#define FLAG_SHARP      2
#define FLAG_BOTH       (FLAG_SHARP | FLAG_ZERO)
#define SIZE_1BYTE      1
#define SIZE_2BYTE      2
#define SIZE_4BYTE      4
#define HEX_LOWERCASE   0
#define HEX_UPPERCASE   1
#define DECIMAL         2

int printIntData(char, size_t, char, unsigned long int);
int printInt(char, size_t, char, unsigned long int);
int printHex(char, size_t, char, unsigned long int);
int myprintData(size_t, unsigned long int, const unsigned char *, int);

int main(void) {

	printIntData(FLAG_NONE, SIZE_4BYTE, DECIMAL, 258120);
	putchar('\n');
	printIntData(FLAG_SHARP, SIZE_4BYTE, DECIMAL, 258120);
	putchar('\n');
	printIntData(FLAG_NONE, SIZE_4BYTE, DECIMAL, 4294967295);
	putchar('\n');
	printIntData(FLAG_ZERO, SIZE_2BYTE, DECIMAL, 32767);
	putchar('\n');
	printIntData(FLAG_BOTH, SIZE_2BYTE, DECIMAL, 32768);
	putchar('\n');
	printIntData(FLAG_SHARP, SIZE_2BYTE, DECIMAL, 1);
	putchar('\n');
	printIntData(FLAG_NONE, SIZE_1BYTE, DECIMAL, 0);
	putchar('\n');

	printIntData(FLAG_NONE, SIZE_4BYTE, HEX_LOWERCASE, 258120);
	putchar('\n');
	printIntData(FLAG_BOTH, SIZE_4BYTE, HEX_UPPERCASE, 258120);
	putchar('\n');
	printIntData(FLAG_ZERO, SIZE_4BYTE, HEX_LOWERCASE, 258120);
	putchar('\n');
	printIntData(FLAG_SHARP, SIZE_4BYTE, HEX_UPPERCASE, 258120);
	putchar('\n');
	printIntData(FLAG_BOTH, SIZE_4BYTE, HEX_LOWERCASE, 10);
	putchar('\n');
	printIntData(FLAG_NONE, SIZE_4BYTE, HEX_UPPERCASE, 10);
	putchar('\n');

	printIntData(FLAG_ZERO, SIZE_2BYTE, HEX_UPPERCASE, 258120);
	putchar('\n');
	printIntData(FLAG_SHARP, SIZE_2BYTE, HEX_LOWERCASE, 258120);
	putchar('\n');
	printIntData(FLAG_BOTH, SIZE_2BYTE, HEX_LOWERCASE, 10);
	putchar('\n');
	printIntData(FLAG_NONE, SIZE_2BYTE, HEX_UPPERCASE, 10);
	putchar('\n');

	printIntData(FLAG_NONE, SIZE_1BYTE, HEX_UPPERCASE, 258120);
	putchar('\n');
	printIntData(FLAG_SHARP, SIZE_1BYTE, HEX_LOWERCASE, 258120);
	putchar('\n');
	printIntData(FLAG_ZERO, SIZE_1BYTE, HEX_LOWERCASE, 10);
	putchar('\n');
	printIntData(FLAG_SHARP, SIZE_1BYTE, HEX_UPPERCASE, 10);
	putchar('\n');

	return 0;
}

int printIntData(char flag, size_t n, char fmt, unsigned long int data) {

	if ((fmt == HEX_LOWERCASE) && (fmt == HEX_UPPERCASE)) {

		return(printHex(flag, n, fmt, data));

	}
	else if (fmt == DECIMAL) {

		return(printInt(flag, n, fmt, data));

	}
	else {

		return(ERROR_RETURN);

	}

}

#define MAX_DIGIT 10
#define BASE10    10

int printInt(char flag, size_t n, char fmt, unsigned long int data) {

	char digit[MAX_DIGIT];
	unsigned long int quot;
	int i;

	if ((flag == FLAG_SHARP) || (flag == FLAG_BOTH)) {

		putchar('-');

	}
	if (n == SIZE_2BYTE) {

		data &= 0xffff;

	}
	else if (n == SIZE_1BYTE) {

		data &= 0xff;

	}
	i = 0;
	while ((quot = data / BASE10) != 0) {

		digit[i++] = '0' + (data - quot * BASE10);
		data = quot;

	}
	putchar('0' + data);
	if (i != 0) {

		while (i) {

			i--;
			putchar(digit[i]);

		}

	}
	return (n);
}

#define BASE16 16

const unsigned char hexUpperCase[BASE16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

const unsigned char hexLowerCase[BASE16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };

#define MASK4BITS (16-1)

int printHex(char flag, size_t n, char fmt, unsigned long int data) {

	int suppress0;
	int add0x;

	suppress0 = 1;
	add0x = 0;

	if ((flag >= FLAG_NONE) || (flag == FLAG_BOTH)) {

		if ((flag == FLAG_NONE) || (flag == FLAG_SHARP)) {

			suppress0 = 1;

		}
		else {

			if (data == 0) {

				suppress0 = 1;

			}
			else {

				suppress0 = 0;

			}

		}
		if ((flag == FLAG_NONE) || (flag == FLAG_ZERO)) {

			add0x = 0;

		}
		else {

			add0x = 1;

		}

	}
	else {



	}
	if (fmt == HEX_LOWERCASE) {

		if (add0x) {

			putchar('0');
			putchar('x');

		}
		return (myprintData(n, data, hexLowerCase, suppress0));

	}
	else if (fmt == HEX_UPPERCASE) {

		if (add0x) {

			putchar('0');
			putchar('x');

		}
		return(myprintData(n, data, hexUpperCase, suppress0));

	}
	else {

		return(ERROR_RETURN);

	}

}

int myprintData(size_t n, unsigned long int data, const unsigned char tbl[], int suppress0) {

	unsigned char c, b4;
	int non0;

	non0 = 0;

	if (n == SIZE_1BYTE) {

		c = (unsigned char)data;
		b4 = c >> 4;
		if ((suppress0 == 1) && (b4 == 0)) {



		}
		else {

			putchar(tbl[b4]);

		}
		putchar(tbl[c & MASK4BITS]);

	}
	else if (n == SIZE_2BYTE) {

		c = (unsigned char)(data >> 8);
		b4 = c >> 4;
		if ((suppress0 == 1) && (!non0) && (b4 == 0)) {



		}
		else {

			non0 = 1;
			putchar(tbl[b4]);

		}
		b4 = c & MASK4BITS;
		if ((suppress0 == 1) && (!non0) && (b4 == 0)) {



		}
		else {

			non0 = 1;
			putchar(tbl[b4]);

		}
		c = (unsigned char)data;
		b4 = c >> 4;
		if ((suppress0 == 1) && (!non0) && (b4 == 0)) {



		}
		else {

			putchar(tbl[b4]);

		}
		putchar(tbl[c & MASK4BITS]);

	}
	else if (n == SIZE_4BYTE) {

		c = (unsigned char)(data >> 24);
		b4 = c >> 4;
		if ((suppress0 == 1) && (!non0) && (b4 == 0)) {



		}
		else {

			non0 = 1;
			putchar(tbl[b4]);

		}
		b4 = c & MASK4BITS;
		if ((suppress0 == 1) && (!non0) && (b4 == 0)) {



		}
		else {

			non0 = 1;
			putchar(tbl[b4]);

		}
		c = (unsigned char)(data >> 16);
		b4 = c >> 4;
		if ((suppress0 == 1) && (!non0) && (b4 == 0)) {



		}
		else {

			non0 = 1;
			putchar(tbl[b4]);

		}
		b4 = c & MASK4BITS;
		if ((suppress0 == 1) && (!non0) && (b4 == 0)) {



		}
		else {

			non0 = 1;
			putchar(tbl[b4]);

		}
		c = (unsigned char)(data >> 8);
		b4 = c >> 4;
		if ((suppress0 == 1) && (!non0) && (b4 == 0)) {



		}
		else {

			non0 = 1;
			putchar(tbl[b4]);

		}
		b4 = c & MASK4BITS;
		if ((suppress0 == 1) && (!non0) && (b4 == 0)) {



		}
		else {

			non0 = 1;
			putchar(tbl[b4]);

		}
		c = (unsigned char)data;
		b4 = c >> 4;
		if ((suppress0 == 1) && (!non0) && (b4 == 0)) {



		}
		else {

			putchar(tbl[b4]);

		}
		putchar(tbl[c & MASK4BITS]);
	}
	else {

		return(ERROR_RETURN);

	}

	return (n);

}