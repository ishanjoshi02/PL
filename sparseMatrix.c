#include <stdio.h>
#define MAX 100
typedef struct {
	int row,col,value;
}matrix;
void accept(matrix a[MAX]) {
	printf("Enter the Number of Rows and Columns\n");
	scanf("%d%d",&a[0].row,&a[0].col);
	int i,j,k,var;
	printf("Enter the Elements now\n");
	for(i=0,k=1;i<a[0].row;i++) {
		for(j=0;j<a[0].col;j++) {
			scanf("%d",&var);
			if(var!=0) {
				a[k].row = i;
				a[k].col = j;
				a[k].value = var;
				k++;
			}
		}
	}
	a[k].value = k-1;
}
void display(matrix a[MAX]) {
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
void add(matrix a[MAX],matrix b[MAX]) {
	int i = 1,j = 1,k = 1;
	matrix c[MAX];
	c[0].row = a[0].row;
	c[0].col = a[0].col;
	while(i<=a[0].value && j<=b[0].value) {
		if(a[i].row == b[j].row) {
			if(a[i].col == b[j].col) {
				c[k].row = a[i].row;
				c[k].col = a[i].col;
				c[k].value = a[i].value + b[j].value;
				i++;j++;k++;
			}
			else if(a[i].row < b[j].row) {
				c[k].row = a[i].row;
				c[k].col = a[i].col;
				c[k].value = a[i].value;
				i++;k++;
			}
			else {
				c[k].row = b[j].row;
				c[k].col = b[j].col;
				c[k].value = b[j].value;
				j++;k++;
			}
		}
		else if(a[i].row < b[j].row) {
			c[k].row = a[i].row;
			c[k].col = a[i].col;
			c[k].value = a[i].value;
			i++;k++;
		}
		else {
			c[k].row = b[j].row;
			c[k].col = b[j].col;
			c[k].value = b[j].value;
			j++;k++;
		}
	}
	while(j<=b[0].value) {
		c[k].row = b[j].row;
		c[k].col = b[j].col;
		c[k].value = b[j].value;
		j++;k++;
	}
	while(i<=a[0].value) {
		c[k].row = a[i].row;
		c[k].col = a[i].col;
		c[k].value = a[i].value;
		i++;k++;
	}
	c[0].value = k-1;
	display(c);
}
void stranspose(matrix a[]) {

}
void ftranspose(matrix b[]) {

}
int main() {
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
				add(a,b);
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
