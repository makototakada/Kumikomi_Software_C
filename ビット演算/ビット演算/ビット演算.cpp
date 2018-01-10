#include <stdio.h>

int main(void) {

	// ビット論理積 (&) 両方のビットが１のときのみ結果が１になる
	unsigned char a = 0xaa;           //     10101010
	printf("%#x\n", a & 0xf0);        // and 11110000

									  // ビット論理和 (|) いずれかのビットが１なら結果が1になる
	unsigned char b = 0xaa;           //    10101010
	printf("%#x\n", b | 0xf0);        // or 11110000

									  // ビット排他的論理和 (^) 両方のビットが異なるときに結果を１にする
	unsigned char c = 0xaa;           //     10101010
	printf("%#x\n", c ^ 0x0f);        // xor 00001111

									  // ビット反転 (~) 全ビットの無条件反転を行う
	unsigned char d = 0xaa;           // 10101010 
	printf("%#x\n", ~d);              // 補数

	return 0;
}