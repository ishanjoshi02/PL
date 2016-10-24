#include <stdio.h>
#define MAX 10
void accept(int a[][MAX],int row,int column) {
  int i,j;
  printf("Enter Elements now\n");
  for(i=0;i<row;i++) {
    for(j=0;j<column;j++) {
      scanf("%d",&a[i][j]);
    }
  }
}
void display(int a[][MAX],int row,int column) {
  int i,j;
  printf("Displaying Elements now\n");
  for(i=0;i<row;i++) {
    for(j=0;j<column;j++) {
      printf("%d\t",a[i][j]);
    }
    printf("\n");
  }
}
void addMatrices(int a[][MAX],int b[][MAX],int row,int column) {
  int c[MAX][MAX],i,j;
  for(i=0;i<row;i++) {
    for(j=0;j<column;j++) {
      c[i][j] = a[i][j] + b[i][j];
    }
  }
  display(c,row,column);
}
void multiplyMatrices(int a[][MAX],int b[][MAX],int column1,int row,int column) {
  int c[MAX][MAX],i,j,k;
  for(i=0;i<row;i++) {
    for(j=0;j<column;j++) {
      c[i][j] = 0;
      for(k=0;k<column1;k++) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  display(c,row,column);
}
void transpose(int a[][MAX],int row,int column) {
  int i,j,c[MAX][MAX];
  for(i=0;i<row;i++) {
    for(j=0;j<column;j++) {
      c[i][j] = a[j][i];
    }
  }
  display(c,column,row);
}
void saddlePoint(int a[][MAX],int row,int column) {
  int i,j,min[row],max;
  for(i=0;i<row;i++) {
    min[i] = a[i][0];
    for(j=0;j<column;j++) {
      if(a[i][j]<min[i]) {
        min[i] = a[i][j];
      }
    }
  }
  max = min[0];
  for(i=1;i<row;i++) {
    if(max<min[i]) {
        max = min[i];
    }
  }
  printf("Saddle Point is %d",max);
}
int main(int argc, char const *argv[]) {
  int a[MAX][MAX],b[MAX][MAX],row,col,row1,col1,option;
  do {
    printf("1. Accept First Matrix\n2. Accept Second Matrix\n3. Add the Two Matrices\n4. Multiply the Two Matrices\n5. Transpose of the First Matrix\n6. Transpose of Second Matrix\n7. Saddle Point of First Matrix\n8. Saddle Point of Second Matrix\n9. Exit\n");
    scanf("%d",&option);
    switch (option) {
      case 1 : {
        printf("Enter the Number of Rows and Columns\n");
        scanf("%d%d",&row,&col);
        accept(a,row,col);
        display(a,row,col);
        break;
      }
      case 2 : {
        printf("Enter the Number of Rows and Columns\n");
        scanf("%d%d",&row1,&col1);
        accept(b,row1,col1);
        display(b,row1,col1);
        break;
      }
      case 3 : {
        if(row==row1 && col==col1) {
          addMatrices(a,b,row,col);
        }
        else {
          printf("Value for Row and Column must be same\n");
        }
        break;
      }
      case 4 : {
        if(row==row1) {
          multiplyMatrices(a,b,col1,row,col);
        }
        else {
          printf("Values for Rows must be Same\n");
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
  } while(1);
  return 0;
}
