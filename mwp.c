#include <stdio.h>
#include <stdlib.h>
int **allocate(int row,int column) {
	int **a,i;
	a = (int **)malloc(sizeof(int *)*row);
	for(i=0;i<row;i++) {
		*(a+i) = (int *)malloc(sizeof(int)*column);
	}
	return a;
}
void accept(int **a,int row,int column) {
	int i,j;
	for(i=0;i<row;i++) {
		for(j=0;j<column;j++) {
			scanf("%d",(*(a+i)+j));
		}
	}
}
void display(int **a,int row,int column) {
	int i,j;
	for(i=0;i<row;i++) {
		for(j=0;j<column;j++) {
			printf("%d\t",*(*(a+i)+j));
		}
		printf("\n");
	}
}
void add(int **a,int **b,int row,int column) {
	int **c,i,j;
	c = allocate(row,column);
	for(i=0;i<row;i++) {
		for(j=0;j<column;j++) {
			*(*(c+i)+j) = *(*(a+i)+j) + *(*(b+i)+j);
		}
	}
	display(c,row,column);
	free(c);
}
void multiply(int **a,int **b,int row,int column,int column1) {
	int **c,i,j,k;
	c = allocate(row,column);
	for(i=0;i<row;i++) {
		for(j=0;j<column;j++) {
			*(*(c+i)+j) = 0;
			for(k=0;k<column1;k++) {
				*(*(c+i)+j) += *(*(a+i)+j) * *(*(a+i)+j);
			}
		}
	}
	display(c,row,column);
	free(c);
}
void transpose(int **a,int row,int column) {
	int **c,i,j;
	c = allocate(row,column);
	for(i=0;i<row;i++) {
		for(j=0;j<column;j++) {
			*(*(c+i)+j) = *(*(a+j)+i);
		}
	}
	display(c,row,column);
	free(c);
}
void saddlePoint(int **a,int row,int column) {
	int *rmin,max,i,j;
	rmin = (int *)malloc(sizeof(int)*row);
	for(i=0;i<row;i++) {
		*(rmin + i) = *(*(a+i));
		for(j=0;j<column;j++) {
			if(*(rmin + i) > *(*(a+i)+j)) {
				*(rmin+i) = *(*(a+i)+j);
			}
		}
	}
	max = *rmin;
	for(i=0;i<row;i++) {
		if(*(rmin+i) > max) {
			max = *(rmin+i);
		}
	}
	printf("Saddle Point of Matrix is %d\n",max);
	free(rmin);
}
int main(int argc, char **argv) {
	int **a,**b,row,col,row1,col1,option;
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
		scanf("%d",&option);
		switch(option) {
		case 1 : {
			printf("Enter the Number of Rows and Columns of First Matrix\n");
			scanf("%d%d",&row,&col);
			a = allocate(row,col);
			accept(a,row,col);
			display(a,row,col);
			break;
		}
		case 2 : {
			printf("Enter the Number of Rows and Columns of Second Matrix\n");
			scanf("%d%d",&row1,&col1);
			b = allocate(row1,col1);
			accept(b,row1,col1);
			display(b,row1,col1);
			break;
		}
		case 3 : {
			if(row!=row1 || col!=col1) {
				printf("Values of Row and Column should be the Same\n");
			}
			else {
				add(a,b,row,col);
			}
			break;
		}
		case 4 : {
			if(row==row1) {
				multiply(a,b,row,col,col1);
			}
			else {
				printf("Values of Row must be same for both Matrices\n");
			}
			break;
		}
		case 5 : {
			transpose(a,row,col);
			break;
		}
		case 6 : {
			transpose(b,row1,col1);
			break;
		}
		case 7 : {
			saddlePoint(a,row,col);
			break;
		}
		case 8 : {
			saddlePoint(b,row1,col1);
			break;
		}
		case 9 : {
			return 0;
		}
		}
	}while(1);
}
