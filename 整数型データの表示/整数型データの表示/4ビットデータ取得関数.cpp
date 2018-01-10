#include <stdio.h>

int myprintData(size_t, unsigned long);

int main(void) {

	myprintData(4, 258120);
	putchar('\n');
	myprintData(2, 258120);
	putchar('\n');
	myprintData(1, 258120);
	putchar('\n');

	return 0;

}

#define BASE 16

const char hexLowerCase[BASE] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };

#define MASK4BITS (BASE - 1)

int myprintData(size_t n, unsigned long data) {

	unsigned char c;

	if (n == 1) {

		c = (unsigned char)data;
		putchar(hexLowerCase[c >> 4]);
		putchar(hexLowerCase[c & MASK4BITS]);

	}
	else if (n == 2) {

		c = (unsigned char)(data >> 8);
		putchar(hexLowerCase[c >> 4]);
		putchar(hexLowerCase[c & MASK4BITS]);
		c = (unsigned char)data;
		putchar(hexLowerCase[c >> 4]);
		putchar(hexLowerCase[c & MASK4BITS]);

	}
	else if (n == 4) {

		c = (unsigned char)(data >> 24);
		putchar(hexLowerCase[c >> 4]);
		putchar(hexLowerCase[c & MASK4BITS]);
		c = (unsigned char)(data >> 16);
		putchar(hexLowerCase[c >> 4]);
		putchar(hexLowerCase[c & MASK4BITS]);
		c = (unsigned char)(data >> 8);
		putchar(hexLowerCase[c >> 4]);
		putchar(hexLowerCase[c & MASK4BITS]);
		c = (unsigned char)data;
		putchar(hexLowerCase[c >> 4]);
		putchar(hexLowerCase[c & MASK4BITS]);

	}
	else {

		return (-1);

	}

	return (n);
}