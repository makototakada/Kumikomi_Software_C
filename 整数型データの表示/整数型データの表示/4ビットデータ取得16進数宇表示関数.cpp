/*#include <stdio.h>

#define ERROR_RETURN  -1
#define SIZE_1BYTE     1
#define SIZE_2BYTE     2
#define SIZE_4BYTE     4
#define HEX_LOWERCASE  0
#define HEX_UPPERCASE  1

int myprint0xData(size_t, unsigned long, char);
int myprintData(size_t, unsigned long, const char *);

int main(void) {

	myprint0xData(SIZE_4BYTE, 258120, HEX_LOWERCASE);
	putchar('\n');
	myprint0xData(SIZE_4BYTE, 258120, HEX_UPPERCASE);
	putchar('\n');
	myprint0xData(SIZE_2BYTE, 258120, HEX_LOWERCASE);
	putchar('\n');
	myprint0xData(SIZE_2BYTE, 258120, HEX_UPPERCASE);
	putchar('\n');
	myprint0xData(SIZE_1BYTE, 258120, HEX_LOWERCASE);
	putchar('\n');
	myprint0xData(SIZE_1BYTE, 258120, HEX_UPPERCASE);
	putchar('\n');

	return 0;
}

#define BASE 16

const char hexUpperCase[BASE] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

const char hexLowerCase[BASE] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };

#define MASK4BITES (16 - 1)

int myprint0xData(size_t n, unsigned long data, char fmt) {

	if (fmt == HEX_LOWERCASE) {

		putchar('0');
		putchar('x');
		return(myprintData(n, data, hexLowerCase));

	}
	else if (fmt == HEX_UPPERCASE) {

		putchar('0');
		putchar('x');
		return(myprintData(n, data, hexUpperCase));

	}
	else {

		return(ERROR_RETURN);

	}

}

int myprintData(size_t n, unsigned long data, const char tbl[]) {

	unsigned char c;

	if (n == SIZE_1BYTE) {

		c = (unsigned char)data;
		putchar(tbl[c >> 4]);
		putchar(tbl[c & MASK4BITES]);

	}
	else if (n == SIZE_2BYTE) {

		c = (unsigned char)(data >> 8);
		putchar(tbl[c >> 4]);
		putchar(tbl[c & MASK4BITES]);
		c = (unsigned char)data;
		putchar(tbl[c >> 4]);
		putchar(tbl[c & MASK4BITES]);

	}
	else if (n == SIZE_4BYTE) {

		c = (unsigned char)(data >> 24);
		putchar(tbl[c >> 4]);
		putchar(tbl[c & MASK4BITES]);
		c = (unsigned char)(data >> 16);
		putchar(tbl[c >> 4]);
		putchar(tbl[c & MASK4BITES]);
		c = (unsigned char)(data >> 8);
		putchar(tbl[c >> 4]);
		putchar(tbl[c & MASK4BITES]);
		c = (unsigned char)data;
		putchar(tbl[c >> 4]);
		putchar(tbl[c & MASK4BITES]);

	}
	else {

		return (ERROR_RETURN);

	}

	return (n);

}*/