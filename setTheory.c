#include <stdio.h>
#include <stdlib.h>
int element1,element2;
void accept(int a[],int b[]) {
	int i;
	printf("Enter the Elements of Set A now\n");
	for(i=0;i<element1;i++) {
		scanf("%d",&a[i]);
	}
	printf("Enter the Elements of Set B now\n");
	for(i=0;i<element2;i++) {
		scanf("%d",&b[i]);
	}
}
void display(int a[],int elements) {
	int i;
	printf("{");
	for(i=0;i<elements-1;i++) {
		printf("%d, ",a[i]);
	}
	printf("%d}\n",a[elements-1]);
}
void setUnion(int a[],int b[]) {
	int i,j,c[15],k=0,flag;
	for(i=0;i<element1;i++) {
		c[k++] = a[i];
	}
	for(i=0;i<element2;i++) {
		flag = 0;
		for(j=0;j<element1;j++) {
			if(b[i]==a[j]) {
				flag = 1;
			}
		}
		if(flag==0) {
			c[k++] = b[i];
		}
	}
	display(c,k);
}
void intersection(int a[],int b[]) {
	int i,j,c[15],k=0;
	for(i=0;i<element1;i++) {
		for(j=0;j<element2;j++) {
			if(b[j]==a[i]) {
				c[k++] = a[i];
			}
		}
	}
	display(c,k);
}
void difference(int a[],int b[]) {

}
int main(int argc, char **argv) {
	int *a,*b;
	int option;
	do {
		printf("1. Accept Sets\n"
				"2. Union\n"
				"3. Intersection\n"
				"4. (A-B)\n"
				"5. (B-A)\n"
				"6. Symmetric Difference\n"
				"7. Exit\n");
		scanf("%d",&option);
		switch(option) {
		case 1 : {
			printf("Enter the Number of Elements in Set A and B\n");
			scanf("%d%d",&element1,&element2);
			a = (int *)malloc(sizeof(int)*element1);
			b = (int *)malloc(sizeof(int)*element2);
			accept(a,b);
			display(a,element1);
			display(b,element2);
			break;
		}
		case 2 : {
			setUnion(a,b);
			break;
		}
		case 3 : {
			intersection(a,b);
			break;
		}
		}
	} while (1);
}
