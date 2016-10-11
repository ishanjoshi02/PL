#include <stdio.h>
#define MAX 10
void accept(int a[][MAX],int row,int column) {
	int i,j;
	printf("Enter the Elements now\n");
	for(i=0;i<row;i++) {
		for(j=0;j<column;j++) {
			scanf("%d",&a[i][j]);
		}
	}
}
void display(int a[][MAX],int row,int column) {
	int i,j;
	for(i=0;i<row;i++) {
		for(j=0;j<column;j++) {
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
void addMatrix(int a[][MAX],int b[][MAX],int row,int col) {
	int c[row][col],i,j;
	for(i=0;i<row;i++) {
		for(j=0;j<col;j++) {
			c[i][j] = a[i][j] + b[i][j];
		}
	}
	printf("The Resultant Matrix is \n");
	display(c,row,col);
}
void multiplyMatrix(int a[][MAX],int b[][MAX],int row,int col) {
	int c[row][col],i,j,k;
	for(i=0;i<row;i++) {
		for(j=0;j<col;j++) {
			c[i][j] = 0;
			for(k=0;k<row;k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	printf("The Resultant Matrix is \n");
	display(c,row,col);
}
void transpose(int a[][MAX],int row,int col) {
	int c[col][row],i,j;
	for(i=0;i<row;i++) {
		for(j=0;j<col;j++) {
			c[j][i] = a[i][j];
		}
	}
	printf("Displaying the Transpose\n");
	display(c,col,row);
}
int saddlePoint(int a[][MAX],int row,int col) {
	int i,j,min[row],max;
	for(i=0;i<row;i++) {
		min[i] = a[i][0];
		for(j=0;j<col;j++) {
			if(min[i]>a[i][j]) {
				min[i] = a[i][j];
			}
		}
	}
	for(i=0,max=min[0];i<row;i++) {
		if(min[i]>max) {
			max = min[i];
		}
	}
	return max;
}
int main(int argc, char **argv) {
	int a[MAX][MAX],b[MAX][MAX],row,row1,col,col1,option;
	do {
		printf("1. Accept the Matrices\n"
				"2. Display the Matrices\n"
				"3. Add the Two Matrices\n"
				"4. Multiply the Two Matrices\n"
				"5. Transpose of First Matrix\n"
				"6. Transpose of Second Matrix\n"
				"7. Saddle Point of First Matrix\n"
				"8. Saddle Point of Second Matrix\n"
				"9. Exit\n");
		scanf("%d",&option);
		switch(option) {
		case 1 : {
			printf("Enter the Number of Rows and Column of First Matrix\n");
			scanf("%d%d",&row,&col);
			accept(a,row,col);
			printf("Enter the Number of Rows and Column of Second Matrix\n");
			scanf("%d%d",&row1,&col1);
			accept(b,row1,col1);
			break;
		}
		case 2 : {
			printf("The First Matrix is \n");
			display(a,row,col);
			printf("The Second Matrix is \n");
			display(b,row1,col1);
			break;
		}
		case 3 : {
			if(row==row1 && col==col1) {
				addMatrix(a,b,row,col);
			}
			else {
				printf("The Values for Row and Column for the Two Matrices must be same\n");
			}
			break;
		}
		case 4 : {
			if(row==row1 && col==col1) {
				multiplyMatrix(a,b,row,col);
			}
			else {
				printf("The Values for Row and Column for the Two Matrices must be same\n");
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
			printf("The Saddle Point of First Matrix is %d\n",saddlePoint(a,row,col));
			break;
		}
		case 8 : {
			printf("The Saddle Point of Second Matrix is %dd\n",saddlePoint(b,row1,col1));
			break;
		}
		case 9 : {
			return 0;
		}
		}
	}while(1);
}
