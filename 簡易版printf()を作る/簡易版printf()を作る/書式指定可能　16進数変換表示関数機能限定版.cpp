#include <stdio.h>

int print1(const char *, unsigned long);
int printIntData(char, size_t, char, unsigned long);

// fmt：未使用(将来への拡張のために引数として入れておく)
int printInt(char, size_t, char, unsigned long);
int printHex(char, size_t, char, unsigned long);
int myprintData(size_t, unsigned long, const unsigned char *, int);

int main(void) {

	// printHex(FLAG_NONE, SIZE_4BYTE, HEX_LOWRCASE, 258120);
	print1("%lx", 258120);
	putchar('\n');
	// printHex(FLAG_ZERO, SIZE_4BYTE, HEX_UPPERCASE, 258120);
	print1("%0lX", 258120);
	putchar('\n');
	// printHex(FLAG_SHARP, SIZE_4BYTE, HEX_LOWRCASE, 258120);
	print1("%#lx", 258120);
	putchar('\n');
	// printHex(FLAG_BOTH, SIZE_4BYTE, HEX_UPPERCASE, 258120);
	print1("%0#lX", 258120);
	putchar('\n');


	// printHex(FLAG_BOTH, SIZE_1BYTE, HEX_LOWRCASE, 258120);
	print1("%#0hhx", 258120);
	putchar('\n');
	// printHex(FLAG_BOTH, SIZE_1BYTE, HEX_LOWRCASE, 10);
	print1("%0#hhx", 10);
	putchar('\n');
	// printHex(FLAG_SHARP, SIZE_4BYTE, HEX_UPPERCASE, 0);
	print1("%#lX", 0);
	putchar('\n');
	// printHex(FLAG_SHARP, SIZE_2BYTE, HEX_UPPERCASE, 0);
	print1("%#hX", 0);
	putchar('\n');

	return 0;
}


#define EOS           ('\0')
#define ERROR_RETURN  (-1)
#define FLAG_NONE     (0)
#define FLAG_ZERO     (1)
#define FLAG_SHARP    (2)
#define FLAG_BOTH     (FLAG_SHARP | FLAG_ZERO)
#define SIZE_1BYTE    (1)
#define SIZE_2BYTE    (2)
#define SIZE_4BYTE    (4)
#define HEX_LOWERCASE (0)
#define HEX_UPPERCASE (1)
#define DECIMAL       (2)

int print1(const char *format, unsigned long data) {

	int ret;
	char flag;
	size_t n;
	char *p;
	int c;

	ret = ERROR_RETURN;
	flag = FLAG_NONE;
	n = SIZE_4BYTE;
	p = (char *)format;

	if ((c = *p++) != '%') {

		return(ret);

	}

	//フラグ
	while ((c = *p++) != EOS) {

		if (c == '#') {

			flag |= FLAG_SHARP;

		}
		else if (c == '0') {

			flag |= FLAG_ZERO;

		}
		else {

			break;

		}

	}
	if (c == EOS) {

		return(ret);

	}

	//length
	if (c == 'l') {

		n = SIZE_4BYTE;
		c = *p++;

	}
	else if (c == 'h') {

		if ((c == *p++) == 'h') {

			n = SIZE_1BYTE;
			c = *p++;

		}
		else {

			n = SIZE_2BYTE;

		}

	}

	//format
	if (c != EOS) {

		switch (c) {

			case 'x':
				printIntData(flag, n, HEX_LOWERCASE, data);
				ret = 1;
				break;
			case 'X':
				printIntData(flag, n, HEX_UPPERCASE, data);
				ret = 1;
				break;
			default:
				break;

		}

	}
	else {

		// error: format not specified

	}

	return(ret);
}

int printIntData(char flag, size_t n, char fmt, unsigned long data) {

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

int printInt(char flag, size_t n, char fmt, unsigned long data) {

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

int printHex(char flag, size_t n, char fmt, unsigned long data) {

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

int myprintData(size_t n, unsigned long data, const unsigned char tbl[], int suppress0) {

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