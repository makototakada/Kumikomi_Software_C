/*ó◊ê⁄Ç∑ÇÈãÊâÊÇå©Ç¬ÇØÅAï]âøílÇó^Ç¶ÇÈä÷êî*/
#include <stdio.h>

#define COLUMN_SIZE 5
#define ROW_SIZE 6
#define YET_EVALUATED 0
#define DONT_ENTER -1

int  boxes5x6[COLUMN_SIZE][ROW_SIZE] = {

	{            1, 2,             3,    DONT_ENTER, YET_EVALUATED, YET_EVALUATED},
	{            2, 3,    DONT_ENTER, YET_EVALUATED, YET_EVALUATED, YET_EVALUATED},
	{   DONT_ENTER, 4,             5,             6,    DONT_ENTER, YET_EVALUATED},
	{            6, 5,    DONT_ENTER,    DONT_ENTER, YET_EVALUATED, YET_EVALUATED},
	{YET_EVALUATED, 6, YET_EVALUATED, YET_EVALUATED,    DONT_ENTER, YET_EVALUATED}

};

int nextBox(int boxes[][ROW_SIZE], int eVal);

int main(void) {

	int i, j, n;

	n = nextBox(boxes5x6, 6);
	printf("%d boxes found.\n", n);
	printf("Current evaluated resultÅF\n");
	for (i = 0; i < COLUMN_SIZE; i++) {

		printf("\t");
		for (j = 0; j < ROW_SIZE; j++) {

			printf("%2d ", boxes5x6[i][j]);

		}
		printf("\n");

	}

	return 0;
}

int nextBox(int boxes[][ROW_SIZE], int eVal) {

	int num = 0;
	int i, j;

	for (i = 0; i < COLUMN_SIZE; i++) {

		for (j = 0; j < ROW_SIZE; j++) {

			if (boxes[i][j] == eVal) {
				if (i > 0) {

					if ((boxes[i - 1][j] != DONT_ENTER) && (boxes[i - 1][j] == YET_EVALUATED)) {

						boxes[i - 1][j] = eVal + 1;
						num++;

					}
				}
				if (i < COLUMN_SIZE - 1) {

					if ((boxes[i + 1][j] != DONT_ENTER) && (boxes[i + 1][j] == YET_EVALUATED)) {

						boxes[i + 1][j] = eVal + 1;
						num++;

					}

				}
				if (j > 0) {

					if ((boxes[i][j - 1] != DONT_ENTER) && (boxes[i][j - 1] == YET_EVALUATED)) {

						boxes[i][j - 1] = eVal + 1;
						num++;

					}

				}
				if (j < ROW_SIZE - 1) {

					if ((boxes[i][j + 1] != DONT_ENTER) && (boxes[i][j + 1] == YET_EVALUATED)) {

						boxes[i][j + 1] = eVal + 1;
						num++;

					}

				}

			}

		}

		return (num);

	}

}