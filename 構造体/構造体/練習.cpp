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

	printf("-------------成績表-----------\n");

	while (sw != 0) {

		printf("選択してください\n");
		printf("1:成績表示\n2:データ入力\n0:終了\n>>");
		scanf_s("%d", &sw);

		switch (sw) {

		case 1:
			show(p);
			break;

		case 2:
			input(p);
			break;

		case 0:
			printf("入力を終了します\n");
			break;

		default:
			printf("指定数以外の入力です\n");
			break;

		}

	}

	return 0;
}

void show(struct student *p) {

	int i = 0;
	printf("\t\t\t\t    |\t\t   点数\n");
	printf("\t\t\t\t    |------------------------------\n");
	printf("学籍番号　　　　氏名　学年　クラス　|　英語　国語　数学　理科　社会\n");
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

		printf("%d人目の入力\n", i + 1);
		printf("在籍番号 = ");
		scanf_s("%d", &(p + i)->no);

		if (((p + i)->no) == 0) {

			printf("入力を終了します\n");
			break;

		}

		printf("氏名 = ");
		scanf_s("%s", (p + i)->name);

		printf("学年 = ");
		scanf_s("%d", &(p + i)->nen);

		printf("クラス = ");
		scanf_s("%c", (p + i)->cls);

		printf("点数\n\n");

		printf("英語：");
		scanf_s("%d", &(p + i)->ten.eig);

		printf("国語：");
		scanf_s("%d", &(p + i)->ten.koku);

		printf("数学：");
		scanf_s("%d", &(p + i)->ten.math);

		printf("理科：");
		scanf_s("%d", &(p + i)->ten.rika);

		printf("社会：");
		scanf_s("%d", &(p + i)->ten.sya);

		i++;
	}
}