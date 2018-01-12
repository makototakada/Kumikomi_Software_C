#include <stdio.h>

struct point {

	int eig;
	int koku;
	int math;
	int rika;
	int sya;

};

struct student {

	int no;
	char name[256];
	int nen;
	char cls[256];
	struct point ten;

};

void show(struct student *p);
void input(struct student *p);

int main() {

	int sw = 1;

	struct student school[256];

	struct student *p;
	p = school;

	printf("-------------���ѕ\-----------\n");

	while (sw != 0) {

		printf("�I�����Ă�������\n");
		printf("1:���ѕ\��\n2:�f�[�^����\n0:�I��\n>>");
		scanf_s("%d", &sw);

		switch (sw) {

		case 1:
			show(p);
			break;

		case 2:
			input(p);
			break;

		case 0:
			printf("���͂��I�����܂�\n");
			break;

		default:
			printf("�w�萔�ȊO�̓��͂ł�\n");
			break;

		}

	}

	return 0;
}

void show(struct student *p) {

	int i = 0;
	printf("\t\t\t\t    |\t\t   �_��\n");
	printf("\t\t\t\t    |------------------------------\n");
	printf("�w�Дԍ��@�@�@�@�����@�w�N�@�N���X�@|�@�p��@����@���w�@���ȁ@�Љ�\n");
	printf("-------------------------------------------------------------------\n");

	for (i = 0; (p + i)->no != 0; i++) {

		printf("%8d  %10s   %3d   %5c  |  %3d  %4d  %4d  %4d  %4d\n",
			(p + i)->no, (p + i)->name,
			(p + i)->nen, (p + i)->cls,
			(p + i)->ten.eig,
			(p + i)->ten.koku,
			(p + i)->ten.math,
			(p + i)->ten.rika,
			(p + i)->ten.sya
		);

	}

}

void input(struct student *p) {
	int i = 0;

	while (1) {

		printf("%d�l�ڂ̓���\n", i + 1);
		printf("�ݐДԍ� = ");
		scanf_s("%d", &(p + i)->no);

		if (((p + i)->no) == 0) {

			printf("���͂��I�����܂�\n");
			break;

		}

		printf("���� = ");
		scanf_s("%s", (p + i)->name);

		printf("�w�N = ");
		scanf_s("%d", &(p + i)->nen);

		printf("�N���X = ");
		scanf_s("%c", (p + i)->cls);

		printf("�_��\n\n");

		printf("�p��F");
		scanf_s("%d", &(p + i)->ten.eig);

		printf("����F");
		scanf_s("%d", &(p + i)->ten.koku);

		printf("���w�F");
		scanf_s("%d", &(p + i)->ten.math);

		printf("���ȁF");
		scanf_s("%d", &(p + i)->ten.rika);

		printf("�Љ�F");
		scanf_s("%d", &(p + i)->ten.sya);

		i++;
	}
}