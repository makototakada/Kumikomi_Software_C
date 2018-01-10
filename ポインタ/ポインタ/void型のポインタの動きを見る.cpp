#include <stdio.h>
#include <string.h>

struct what {

	int i;
	double f;

};

#define WHAT_SIZE 10
struct what ary1[WHAT_SIZE] = {

	{ 1, 1.0 },{ 2, 4.0 },{ 3, 9.0 },{ 4, 16.0 },{ 5, 25.0 },
{ 6, 36.0 },{ 7, 49.0 },{ 8, 64.0 },{ 9, 81.0 },{ 10, 100.0 }

};
struct what ary2[WHAT_SIZE];

int main(void) {

	memcpy(ary2, ary1, sizeof(struct what)*WHAT_SIZE);

	printf("%d %f , %d %f\n", ary2[5].i, ary2[5].f, ary2[WHAT_SIZE - 1].i, ary2[WHAT_SIZE - 1].f);


	return 0;
}