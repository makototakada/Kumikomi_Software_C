#include <stdio.h>

int main(void) {

	// �r�b�g�_���� (&) �����̃r�b�g���P�̂Ƃ��̂݌��ʂ��P�ɂȂ�
	unsigned char a = 0xaa;           //     10101010
	printf("%#x\n", a & 0xf0);        // and 11110000

									  // �r�b�g�_���a (|) �����ꂩ�̃r�b�g���P�Ȃ猋�ʂ�1�ɂȂ�
	unsigned char b = 0xaa;           //    10101010
	printf("%#x\n", b | 0xf0);        // or 11110000

									  // �r�b�g�r���I�_���a (^) �����̃r�b�g���قȂ�Ƃ��Ɍ��ʂ��P�ɂ���
	unsigned char c = 0xaa;           //     10101010
	printf("%#x\n", c ^ 0x0f);        // xor 00001111

									  // �r�b�g���] (~) �S�r�b�g�̖��������]���s��
	unsigned char d = 0xaa;           // 10101010 
	printf("%#x\n", ~d);              // �␔

	return 0;
}