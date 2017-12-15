#include <stdio.h>
#include <limits.h>

int main(void)
{
	unsigned int x, y, z;

	printf("0�`%u�̐������Q����\n", UINT_MAX);
	scanf_s("%u%u", &x, &y);

	z = x & y;
	printf("%u(%#x) AND %u(%#x) = %#x\n", x, x, y, y, z);

	z = x | y;
	printf("%u(%#x) OR  %u(%#x) = %#x\n", x, x, y, y, z);

	z = x ^ y;
	printf("%u(%#x) XOR %u(%#x) = %#x\n", x, x, y, y, z);

	return 0;
}
//  %u �́Aunsigned�^�ɑ΂��鏑���w�蕶����B
//  UINT_MAX �� limits.h �̒��Ń}�N����`����Aunsigned int�^�̍ő�l��\���B