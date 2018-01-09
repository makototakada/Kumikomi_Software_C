#include <stdio.h>

int print1(const char *, unsigned long);
int printIntData(char, size_t, char, unsigned long);
int printInt(char, size_t, char, unsigned long);
int printHex(char, size_t, char, unsigned long);
int myprintData(size_t, unsigned long, const unsigned char *, int);
int outputConversion(char *, unsigned long, char **);

int main(void) {

	print1("Hello,world\n", 0);

	print1("\"\\\" is breaklash\n", 0);

	print1("Today:\t%d\n", 2008);

	print1("'data\' = %#x\n", 2008);

	print1("data = (%d, %x)\n", 2008);

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
	int num;
	char *p;
	int c;
	int numConversion;

	num = 0;
	numConversion = 0;
	p = (char *)format;

	while ((c = *p++) != EOS) {

		switch (c) {

			case '%':
				if (numConversion != 0) {

					return(ERROR_RETURN);

				}
				ret = outputConversion(p, data, &p);
				numConversion++;
				if (ret < 0) {

					return(ERROR_RETURN);

				}
				num += ret;
				break;
			default:
				putchar(c);
				num++;
				break;

		}

	}

	return(num);

}

int outputConversion(char *format, unsigned long data, char **next) {

	int ret;
	char flag;
	size_t n;
	char fmt;
	char *p;
	int c;

	ret = ERROR_RETURN;
	flag = FLAG_NONE;
	n = SIZE_4BYTE;
	p = format;

#if 0
	if ((c = *p++) != '%') {

		return(ret);

	}
#endif

	// ƒtƒ‰ƒO
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

	// length
	if (c == 'l') {

		n = SIZE_4BYTE;
		c = *p++;

	}
	else if (c == 'h') {

		if ((c = *p++) == 'h') {

			n = SIZE_1BYTE;
			c = *p++;

		}
		else {

			n = SIZE_2BYTE;

		}

	}



	// format
	if (c != EOS) {

		long sdata;

		switch (c) {

		case 'x':
			ret = printIntData(flag, n, HEX_LOWERCASE, data);
			break;
		case 'X':
			ret = printIntData(flag, n, HEX_UPPERCASE, data);
			break;
		case 'u':
			ret = printIntData(FLAG_NONE, n, DECIMAL, data);
			break;
		case 'd':
			sdata = (long)data;
			if (sdata >= 0) {

				ret = printIntData(FLAG_NONE, n, DECIMAL, data);

			}
			else {

				sdata = -sdata;
				ret = printIntData(FLAG_SHARP, n, DECIMAL, (unsigned long)sdata);

			}
			break;
		default:
			break;

		}

	}
	else {

		// error: format not specified

	}
	*next = p; //ãˆÊŠÖ”‚ÉŽŸ‚Éˆ—‚·‚×‚«êŠ‚ð“`‚¦‚é
	return(ret);

}

int printIntData(char flag, size_t n, char fmt, unsigned long data) {

	if ((fmt == HEX_LOWERCASE) || (fmt == HEX_UPPERCASE)) {

		return(printHex(flag, n, fmt, data));

	}
	else if (fmt == DECIMAL) {

		return(printInt(flag, n, fmt, data));

	}
	else {

		return(ERROR_RETURN);

	}

}

// 32-bit integer‚ÌÅ‘å‚Í4294967295,‚Â‚Ü‚è,10Œ…

#define MAX_DIGIT 10
#define BASE10 10

int printInt(char flag, size_t n, char fmr, unsigned long data) {

	char digit[MAX_DIGIT];
	unsigned long quot;
	int i;
	int num;

	num = 0;
	if ((flag == FLAG_SHARP) || (flag == FLAG_BOTH)) {

		putchar('-');
		num++;

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
	num++;
	if (i != 0) {

		while (i) {

			i--;
			putchar(digit[i]);
			num++;

		}

	}

	return(num);

}

#define BASE16 16

const unsigned char hexUpperCase[BASE16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

const unsigned char hexLowerCase[BASE16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };

#define MASK4BITS (16-1)

int printHex(char flag, size_t n, char fmt, unsigned long data) {

	int suppress0;
	int add0x;
	int num, ret;

	suppress0 = 1;
	add0x = 0;
	num = 0;
	ret = ERROR_RETURN;

	if ((flag >= FLAG_NONE) && (flag <= FLAG_BOTH)) {

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

		// ignore; use default value

	}
	if (fmt == HEX_LOWERCASE) {

		if (add0x) {

			putchar('0');
			putchar('x');
			num += 2;

		}
		ret = myprintData(n, data, hexUpperCase, suppress0);

	}
	else if (fmt == HEX_UPPERCASE) {

		if (add0x) {

			putchar('0');
			putchar('X');
			num += 2;

		}
		ret = myprintData(n, data, hexUpperCase, suppress0);

	}
	else {

		// error: not support

	}
	if (ret < 0) {

		return(ret);

	}
	else {

		return(ret + num);

	}

}

int myprintData(size_t n, unsigned long data, const unsigned char tbl[], int suppress0) {

	unsigned char c, b4;
	int non0;
	int num;

	non0 = 0;
	num = 0;

	if (n == SIZE_1BYTE) {

		c = (unsigned char)data;
		b4 = c >> 4;

		if ((suppress0 == 1) && (b4 == 0)) {



		}
		else {

			putchar(tbl[b4]);
			num++;

		}
		putchar(tbl[c &MASK4BITS]);
		num++;

	}
	else if (n == SIZE_2BYTE) {

		c = (unsigned char)(data >> 8);
		b4 = c >> 4;
		if ((suppress0 == 1) && (!non0) && (b4 == 0)) {



		}
		else {

			non0 = 1;
			putchar(tbl[b4]);
			num++;

		}
		b4 = c & MASK4BITS;
		if ((suppress0 == 1) && (!non0) && (b4 == 0)) {



		}
		else {

			non0 = 1;
			putchar(tbl[b4]);
			num++;

		}
		c = (unsigned char)data;
		b4 = c >> 4;
		if ((suppress0 == 1) && (!non0) && (b4 == 0)) {



		}
		else {

			putchar(tbl[b4]);
			num++;

		}
		putchar(tbl[c & MASK4BITS]);
		num++;

	}
	else if (n == SIZE_4BYTE) {

		c = (unsigned char)(data >> 24);
		b4 = c >> 4;
		if ((suppress0 == 1) && (!non0) && (b4 == 0)) {



		}
		else {

			non0;
			putchar(tbl[b4]);
			num++;

		}
		b4 = c & MASK4BITS;
		if ((suppress0 == 1) && (!non0) && (b4 == 0)) {



		}
		else {

			non0 = 1;
			putchar(tbl[b4]);
			num++;

		}
		c = (unsigned char)(data >> 16);
		b4 = c >> 4;
		if ((suppress0 == 1) && (!non0) && (b4 == 0)) {



		}
		else {

			non0 = 1;
			putchar(tbl[b4]);
			num++;

		}
		b4 = c & MASK4BITS;
		if ((suppress0 == 1) && (!non0) && (b4 == 0)) {



		}
		else {

			non0 = 1;
			putchar(tbl[b4]);
			num++;

		}
		c = (unsigned char)(data >> 8);
		b4 = c >> 4;
		if ((suppress0 == 1) && (!non0) && (b4 == 0)) {



		}
		else {

			non0 = 1;
			putchar(tbl[b4]);
			num++;

		}
		b4 = c & MASK4BITS;
		if ((suppress0 == 1) && (!non0) && (b4 == 0)) {



		}
		else {

			non0 = 1;
			putchar(tbl[b4]);
			num++;

		}
		c = (unsigned char)data;
		b4 = c >> 4;
		if ((suppress0 == 1) && (!non0) && (b4 == 0)) {



		}
		else {

			putchar(tbl[c & MASK4BITS]);
			num++;

		}
		putchar(tbl[c & MASK4BITS]);
		num++;

	}
	else {

		return(ERROR_RETURN);

	}

	return(num);

}