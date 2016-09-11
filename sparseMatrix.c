#include <stdio.h>
#include <stdlib.h>
#define MAX 25
void accept(int c[MAX][3],int row,int col) {
	int i,j,k=1,var;
	printf("Enter the Elements now\n");
	for(i=0;i<row;i++) {
		for(j=0;j<col;j++) {
			scanf("%d",&var);
			if(var!=0) {
				c[k][0] = i;
				c[k][1] = j;
				c[k][2] = var;
				k++;
			}
		}
	}
	printf("Done Accepting\n");
	c[0][0] = row;
	c[0][1] = col;
	c[0][2] = k-1;
}
void display(int c[MAX][3]) {
	int i,j,k=1;
	for(i=0;i<c[0][0];i++) {
		for(j=0;j<c[0][1];j++) {
			if(c[k][0]==i && c[k][1]==j) {
				printf("%d",c[k][2]);
				k++;
			}
			else {
				printf("%d",0);
			}
			printf("\t");
		}
		printf("\n");
	}
}
int max(int a,int b) {
	if(a>b) {
		return a;
	}
	return b;
}
void add(int c[MAX][3],int c1[MAX][3]){
	int i,j,k=1,l=1,m=1;
	int c2[MAX][3];
	c2[0][0] = max(c[0][0],c1[0][0]);
	c2[0][1] = max(c[0][1],c1[0][1]);
	for(i=0;i<c2[0][0];i++) {
		for(j=0;j<c2[0][1];j++) {
			if(i==c[k][0] && j==c[k][1]) {
				if(i==c1[l][0] && j==c1[l][1]) {
					c2[m][0] = i;
					c2[m][1] = j;
					c2[m][2] = c[k][2] + c1[l][2];
					l++;
					continue;
				}
				else {
					c2[m][0] = i;
					c2[m][1] = j;
					c2[m][2] = c[k][2];
					continue;
				}
				k++;m++;
			}
			if(i==c1[l][0] && j==c1[l][1]) {
				c2[m][0] = i;
				c2[m][1] = j;
				c2[m][2] = c1[l][2];
				l++;m++;
			}
		}
	}
	display(c2);
}
int main(int argc, char **argv) {
	int opt,row,row1,col,col1;
	int c[MAX][3],c1[MAX][3];
	do {
		printf("1.Accept a Sparse Matrix\n");
		printf("2.Display a Sparse Matrix\n");
		printf("3.Addition of the two Matrices\n");
		printf("4.Transpose a Sparse Matrix\n");
		printf("5.Exit\n");
		scanf("%d",&opt);
		switch(opt) {
		case 1 : {
			printf("1.Accept the First Matrix\n2.Accept the Second Matrix\n");
			scanf("%d",&opt);
			switch(opt) {
			case 1 : {
				printf("Enter the Number of Rows and Number of Columns\n");
				scanf("%d%d",&row,&col);
				accept(c,row,col);
				break;
			}
			case 2 : {
				printf("Enter the Number of Rows and Number of Columns\n");
				scanf("%d%d",&row1,&col1);
				accept(c1,row1,col1);
			}
			}
			break;
		}
		case 2 : {
			printf("1.Display First Matrix\n2.Display Second Matrix\n");
			scanf("%d",&opt);
			switch(opt) {
			case 1 : {
				display(c);
				break;
			}
			case 2 : {
				display(c1);
				break;
			}
			}
			break;
		}
		case 3 : {
			add(c,c1);
			break;
		}
		}
	}while(1);
}

