/*
 * Accept  conventional  matrix
 *  and  convert  it  into  sparse  matrix  using  structure
 * and perform  addition, simple and fast transpose
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int **mallocate(int **a,int row, int col) {
	int k;
	a = (int **)malloc(sizeof(int)*row);
	for(k = 0;k<col;k++) {
		a[k] = (int *)malloc(sizeof(int)*col);
	}
	return a;
}
void display(int c[MAX][3],int row,int col) {
	int i,k = 1,j;
	for(i = 0;i < row;i++) {
		for(j = 0;j < col;j++) {
			if(c[k][0] == i && c[k][1] == j) {
				printf("%d",c[k][2]);
				k++;
			}
			else {
				printf("%d",0);
			}
		}
	}
}
void convert(int **a,int c[MAX][3],int row,int column) {
	int i,j,p = 0,q = 0,r = 0;
	for(i=0;i<row;i++) {
		for(j=0;j<column;j++) {
			if(*(*(a+i)+j)!=0) {
				c[1][0] = i;
				p++;
				c[1][1] = j;
				q++;
				c[1][2] = **a;
				r++;
			}
		}
	}
	c[0][0] = p;
	c[0][1] = q;
	c[0][2] = r;
}
void accept (int **a,int row,int column) {
	int i,j;

	printf("Enter the Elements now\n");
	for(i=0;i<row;i++) {
		for(j=0;j<column;j++) {
			scanf("%d",(*(a+i)+j));
		}
	}
}
int main() {
	int opt,row,row1,column,column1;
	int **a,**b,c[MAX][3],c1[MAX][3];
	do {
		printf("1.Accept a Sparse Matrix\n2.Display a Sparse Matrix\n3.Perform Addition of Two Sparse Matrices\n");
		printf("4.Transpose of A Matrix\n");
		scanf("%d",&opt);
		switch(opt) {
		case 1 : {
			printf("1.Accept First Matrix\n2.Accept Second Matrix\n");
			scanf("%d",&opt);
			switch(opt) {
			case 1 : {
				printf("Enter the Number of Rows of Sparse Matrix\n");
				scanf("%d",&row);
				printf("Enter the Number of Columns of Sparse Matrix\n");
				scanf("%d",&column);
				a = mallocate(a,row,column);
				accept(a,row,column);
				convert(a,c,row,column);
				break;
			}
			case 2 : {
				printf("Enter the Number of Rows of Sparse Matrix\n");
				scanf("%d",&row1);
				printf("Enter the Number of Columns of Sparse Matrix\n");
				scanf("%d",&column1);
				b = mallocate(b,row1,column1);
				accept(b,row1,column1);
				convert(b,c1,row1,column1);
				break;
			}
			}
			break;
		}
		case 2 : {
			printf("1.Display First Matrix\n2.Display Second Matrix\n");
			scanf("%d",&opt);
			switch(opt) {
			case 1 : {
				display(c,row,column);
				break;
			}
			case 2 : {
				display(c1,row1,column1);
				break;
			}
			}
			break;
		}
		case 3 : {

		}
		}
	}while(1);
}
