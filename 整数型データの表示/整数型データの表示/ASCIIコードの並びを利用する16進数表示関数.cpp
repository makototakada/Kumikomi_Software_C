#include <stdio.h>

#define BASE 16

const char hexLowerCase[BASE] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };

void printData(char);

int main(void) {

	printData(1);
	printData(3);
	printData(5);
	printData(7);
	printData(9);
	printData(11);
	printData(13);
	printData(15);
	printData(0);
	printData(2);
	printData(4);
	printData(6);
	printData(8);
	printData(10);
	printData(12);
	printData(14);
	printData(16);
	putchar('\n');

	return 0;
}

void printData(char data) {

	if ((data >= 0) && (data < BASE)) {

		putchar(hexLowerCase[data]);

	}
	else {

		putchar('!');

	}

	return;

}