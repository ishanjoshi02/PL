#include <stdio.h>
#define MAX 100
typedef struct {
	int row,col,value;
}matrix;
void accept(matrix a[]) {
	printf("Enter the Number of Rows and Columns\n");
	scanf("%d%d",&a[0].row,&a[0].col);
	int i,j,k,var;
	printf("Enter the Elements now\n");
	for(i=0,k=1;i<a[0].row;i++) {
		for(j=0;j<a[0].col;j++) {
			scanf("%d",&var);
			if(var!=0) {
				a[k].row = i,
						a[k].col = j,
						a[k].value = var,
						k++;
			}
		}
	}
	a[k].value = k-1;
}
void display(matrix a[]) {
	int i,j,k = 1;
	for(i = 0;i < a[0].row;i++) {
		for(j = 0;j < a[0].col;j++) {
			if(i == a[k].row && j == a[k].col) {
				printf("%d\t",a[k].value);
				k++;
			}
			else {
				printf("%d\t",0);
			}
		}
		printf("\n");
	}
}
int *add(matrix a[],matrix b[]) {
	matrix c[MAX];
	c[0].row = a[0].row;
	c[1].row = a[0].col;
	int k = 1,l = 1,m = 1;
	while(k <= a[0].value && l <= b[0].value) {
		if(a[k].row == b[l].row) {
			if(a[k].col == b[l].col) {
				c[m].row = a[k].row;
				c[m].col = a[k].col;
				c[m].value = a[k].value + b[l].value;
				k++; l++; m++;
			}
			else if(a[k].col < b[l].col) {
				c[m].row = a[k].row;
				c[m].col = a[k].col;
				c[m].value = a[k].value;
				k++; m++;
			}
			else {
				c[m].row = b[l].row;
				c[m].col = b[l].col;
				c[m].value = b[l].value;
				l++; m++;
			}
		}
		else if(a[k].row < b[l].row) {
			c[m].row = a[k].row;
			c[m].col = a[k].col;
			c[m].value = a[k].value;
			k++; m++;
		}
		else {
			c[m].row = b[l].row;
			c[m].col = b[l].col;
			c[m].value = b[l].value;
			l++; m++;
		}
	}
	while(k<=a[0].value) {
		c[m].row = a[k].row;
		c[m].col = a[k].col;
		c[m].value = a[k].value;
		k++; m++;
	}
	while(l<=b[0].value) {
		c[m].row = b[l].row;
		c[m].col = b[l].col;
		c[m].value = b[l].value;
		l++; m++;
	}
	c[0].value = m-1;
	display(c);
}
void stranspose(matrix a[]) {
	
}
void ftranspose(matrix b[]) {
	
}
int main(int argc, char **argv) {
	matrix a[MAX],b[MAX];
	int opt;
	do {
		printf("1. Accept the 1st Matrix\n"
				"2. Accept the 2nd Matrix\n"
				"3. Add the 2 Matrices\n"
				"4. Simple Transpose of 1st Matrix\n"
				"5. Simple Transpose of 2nd Matrix\n"
				"6. Fast Transpose of 1st Matrix\n"
				"7. Fast Transpose of 2nd Matrix\n");
		scanf("%d",&opt);
		switch(opt) {
		case 1 : {
			accept(a);
			display(a);
			break;
		}
		case 2 : {
			accept(b);
			display(b);
			break;
		}
		case 3 : {
			if(a[0].row == b[0].row && a[0].col == b[0].col) {
				display(add(a,b));
				break;
			}
			else {
				printf("Invalid Values for Row and Column\n"
						"Please Try Again\n");
			}
			break;
		}
		}
	}while(1);
}
