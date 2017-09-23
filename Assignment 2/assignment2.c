#include <stdio.h>
#include <stdlib.h>

#define printError printf("Check Number of Rows and Columns\n")

typedef struct {

	int rows, columns;
	int **array;

} Matrix;

int **allocate(int rows, int columns) {

	int **array;
	int i;
	array = (int **) malloc(sizeof(int *) * rows);

	for (i = 0;i < rows;i++)
		*(array + i) = (int *) malloc(sizeof(int) * columns);

	return array;

}

Matrix acceptMatrix() {

	Matrix a;
	int i, j;

	printf("Enter the Number of Rows, followed by the Number of Columns\n");
	scanf("%d%d", &a.rows, &a.columns);

	a.array = allocate(a.rows, a.columns);

	printf("Enter the Elements of the Matrix now\n");

	for (i = 0;i < a.rows;i++)
		for (j = 0;j < a.columns;j++)
			scanf("%d", (*(a.array + i) + j));

	return a;

}

void displayMatrix(Matrix a) {

	int i, j;

	for (i = 0;i < a.rows;i++) {

		for (j = 0;j < a.columns;j++) {

			printf("%d\t", *(*(a.array + i) + j));

		}

		printf("\n");

	}

}

Matrix addMatrices(Matrix a, Matrix b) {

	Matrix c;
	int i, j;

	c.rows = a.rows;
	c.columns = a.columns;
	c.array = allocate(a.rows, a.columns);

	for (i = 0;i < a.rows;i++)
		for (j = 0;j < a.columns;j++)
			*(*(c.array + i) + j) = *(*(a.array + i) + j) + *(*(b.array + i) + j);


	return c;

}

Matrix multiplyMatrix(Matrix a, Matrix b) {

	Matrix c;
	int i, j, k;

	c.rows = a.rows;
	c.columns = a.columns;

	c.array = allocate(c.rows, c.columns);

	for (i = 0;i < c.rows;i++)
		for (j = 0;j < c.columns;j++) {

			*(*(c.array + i) + j) = 0;

			for (k = 0;k < b.columns;k++)
				*(*(c.array + i) + j) +=
						*(*(a.array + i) + k) + *(*(b.array + k) + j);

		}

	return c;

}


Matrix transpose(Matrix a) {

	Matrix c;
	int i, j;
	c.rows = a.columns;
	c.columns = a.rows;

	c.array = allocate(c.rows, c.columns);

	for (i = 0;i < c.columns;i++)
		for (j = 0;j < c.rows;j++)
			*(*(c.array + i) + j) = *(*(a.array + j) + i);

	return c;

}

int saddlePoint(Matrix a) {

	int *rmin;
	int rmax;
	int i, j;

	rmin = (int *) malloc(sizeof(int) * a.rows);

	for (i = 0;i < a.rows;i++) {

		*(rmin + i) = *(*(a.array + i));

		for (j = 0;j < a.columns;j++) {

			if (*(rmin + i) > *(*(a.array + i) + j)) {

				*(rmin + i) = *(*(a.array + i) + j);

			}

		}

	}

	rmax = *rmin;

	for (i = 0;i < a.rows;i++)
		if (*(rmin + i) > rmax) {

			rmax = *(rmin + i);

		}

	return rmax;

}


int main(int argc, char **argv) {

	Matrix a, b;
	int option;

	do {

		printf("1. Accept the First Matrix\n"
				"2. Accept the Second Matrix\n"
				"3. Add the Two Matrices\n"
				"4. Multiply Two Matrices\n"
				"5. Transpose of First Matrix\n"
				"6. Transpose of Second Matrix\n"
				"7. Saddle Point of First Matrix\n"
				"8. Saddle Point of Second Matrix\n"
				"9. Exit\n");

		scanf("%d", &option);

		switch(option) {

		case 1 : {

			a = acceptMatrix();
			break;

		}

		case 2 : {

			b = acceptMatrix();
			break;

		}

		case 3 : {

			displayMatrix(addMatrices(a, b));
			break;

		}

		case 4 : {

			displayMatrix(multiplyMatrix(a, b));
			break;

		}

		case 5 : {

			displayMatrix(transpose(a));
			break;

		}

		case 6 : {

			displayMatrix(transpose(b));
			break;

		}

		case 7 : {

			printf("Saddle point of the Matrix A is %d\n", saddlePoint(a));
			break;

		}

		case 8 : {

			printf("Saddle point of the Matrix B is %d\n", saddlePoint(b));
			break;

		}

		case 9 : {

			exit(0);

		}

		}

	} while (1);

	return 0;

}
