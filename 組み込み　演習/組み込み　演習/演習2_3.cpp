#include <stdio.h>
#include <limits.h>

int main(void)
{
	unsigned int x, y, z;

	printf("0～%uの整数を２つ入力\n", UINT_MAX);
	scanf_s("%u%u", &x, &y);

	z = x & y;
	printf("%u(%#x) AND %u(%#x) = %#x\n", x, x, y, y, z);

	z = x | y;
	printf("%u(%#x) OR  %u(%#x) = %#x\n", x, x, y, y, z);

	z = x ^ y;
	printf("%u(%#x) XOR %u(%#x) = %#x\n", x, x, y, y, z);

	return 0;
}
//  %u は、unsigned型に対する書式指定文字列。
//  UINT_MAX は limits.h の中でマクロ定義され、unsigned int型の最大値を表す。
//　unsigned 符号なし　0～255(格納範囲) ※符号ありだと -128～127
