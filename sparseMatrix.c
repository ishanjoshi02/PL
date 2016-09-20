#include <stdio.h>
typedef struct {
  int row,col,value;
}sparse;
void acceptSparse(sparse a[]) {
  printf("Enter the Number of Rows and Column\n");
  scanf("%d%d",&a[0].row,&a[0].col);
  printf("Enter the Elements now\n");
  int i,var,k=1,j;
  for(i=0;i<a[0].row;i++) {
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
  printf("Accepting Finished\n");
  a[0].value = k-1;
}
void displaySparse (sparse a[]) {
  int i,j,k=1;
  for(i=0;i<a[0].row;i++) {
    for(j=0;j<a[0].col;j++) {
      if(a[k].row == i && a[k].col == j) {
        printf("%d\t",a[k].value);
        k++;
      }
      else {
        printf("%d\t",0);
      }
    }
    printf("\n");
  }
  printf("Displaying finished\n");
}
void addSparse(sparse a[], sparse b[]) {
  sparse c[100];
  c[0].row = a[0].row;
  c[0].col = a[0].col;
  int m=1,n=1,o=1;
  while (m<=a[0].value && n<=b[0].value) {
    if(a[m].row < b[n].row) {
      c[o].row = a[m].row;
      c[o].col = a[m].col;
      c[o].value = a[m].value;
      m++; o++;
    }
    else if(a[m].row > b[n].row) {
      c[o].row = b[n].row;
      c[o].col = b[n].col;
      c[o].value = b[n].value;
      o++; n++;
    }
    else {
      if(a[m].col < b[n].col) {
        c[o].row = a[m].row;
        c[o].col = a[m].col;
        c[o].value = a[m].value;
        m++; o++;
      }
      else if(a[m].col > b[n].col) {
        c[o].row = b[n].row;
        c[o].col = b[n].col;
        c[o].value = b[n].value;
        o++; n++;
      }
      else {
        c[o].row = a[m].row;
        c[o].col = a[m].col;
        c[o].value = a[m].value + b[n].value;
        m++; o++; n++;
      }
    }
  }
  displaySparse(c);
}
void fastTranspose(sparse a[]) {
	sparse c[100];
	int total[a[0].row],index[a[0].row+1];
	int t = 0;
	c[0].row = a[0].col;
	c[0].col = a[0].row;
	c[0].value = a[0].value;
	while(t<=a[0].row) {
		a[t].row = 0;
		t++;
	}
	t = 1;
	total[0] = 1;
	while(t<=a[0].row) {
		total[a[0].row]++;
		t++;
	}
	index[0] = 1;
	t = 1;
	while(t<=a[0].row) {
		index[t] = total[t] + index[t-1];
	}
	t = 1;
	while(t<=a[0].value) {
		c[total[a[t].col]].row = a[t].row;
		c[total[a[t].col]].col = a[t].col;
		c[total[a[t].col]].value = a[t].value;
		total[a[t].col]++;
	}
	displaySparse(c);
}
void simpleTranspose(sparse a[]) {

}
int main() {
  sparse a[100],b[100];
  int opt;
  do {
	  printf("1. Accept First Matrix\n"
			  "2. Accept Second Matrix\n"
			  "3. Add the Two Matrices\n"
			  "4. Fast Transpose the First Matrix\n"
			  "5. Fast Transpose the Second Matrix\n"
			  "6. Simple Transpose the First Matrix\n"
			  "7. Simple Transpose the Second Matrix\n"
			  "8. Exit\n");
	  scanf("%d",&opt);
	  switch(opt) {
	  case 1 : {
		  acceptSparse(a);
		  displaySparse(a);
		  break;
	  }
	  case 2 : {
		  acceptSparse(b);
		  displaySparse(b);
		  break;
	  }
	  case 3 : {
		  if(a[0].row != b[0].row || a[0].col != b[0].col) {
			  addSparse(a,b);
		  }
		  else {
			  printf("The Values for Row and Column are Wrong\n");
		  }
		  break;
	  }
	  case 4 : {
		  fastTranspose(a);
		  break;
	  }
	  case 5 : {
		  fastTranspose(b);
		  break;
	  }
	  case 8 : {
		  return 0;
	  }
	  default : {
		  return 0;
	  }
	  }
  }while(1);
}
