#include <stdio.h>

#define COLUMN_SIZE 5
#define ROW_SIZE 6
#define YET_EVALUATED 0
#define DONT_ENTER -1

int  boxes5x6[COLUMN_SIZE][ROW_SIZE] = {

	{ YET_EVALUATED, YET_EVALUATED, YET_EVALUATED,    DONT_ENTER, YET_EVALUATED, YET_EVALUATED },
{ YET_EVALUATED, YET_EVALUATED,    DONT_ENTER, YET_EVALUATED, YET_EVALUATED, YET_EVALUATED },
{ DONT_ENTER, YET_EVALUATED, YET_EVALUATED, YET_EVALUATED,    DONT_ENTER, YET_EVALUATED },
{ YET_EVALUATED, YET_EVALUATED,    DONT_ENTER,    DONT_ENTER, YET_EVALUATED, YET_EVALUATED },
{ YET_EVALUATED, YET_EVALUATED, YET_EVALUATED, YET_EVALUATED,    DONT_ENTER, YET_EVALUATED }

};

#define START_COL 0
#define START_ROW 0
#define DESTINATION_COL (COLUMN_SIZE - 1)
#define DESTINATION_ROW (ROW_SIZE - 1)
#define START_EVAL 1

int searchRoute(int boxes[][ROW_SIZE]);

int nextBox(int boxes[][ROW_SIZE], int eVal);

int main(void) {

	int i, j, n;

	if (searchRoute(boxes5x6) == 0) {

		printf("No routes found.\n");
		return 1;

	}
	printf("Current evaluated resultF\n");
	for (i = 0; i < COLUMN_SIZE; i++) {

		printf("\t");
		for (j = 0; j < ROW_SIZE; j++) {

			printf("%2d ", boxes5x6[i][j]);

		}
		printf("\n");

	}

	return 0;
}

int searchRoute(int boxes[][ROW_SIZE]) {

	int n;
	int eval;

	boxes[START_COL][START_ROW] = START_EVAL;

	for (eval = START_EVAL; eval < (COLUMN_SIZE * ROW_SIZE); eval++) {

		n = nextBox(boxes, eval);
		printf("eval = %d, n = %d\n", eval + 1, n);
		if (n == 0) {

			return 0;

		}
		if (boxes[DESTINATION_COL][DESTINATION_ROW] == (eval + 1)) {

			return 1;

		}

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

	}

	return (num);

}