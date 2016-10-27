#include <stdio.h>
#include <stdlib.h>
int passByPass = 0;
void accept(int a[],int);
void display(int a[],int);
void swap(int *,int *);
void quickSort(int [],int,int);
int main(int argc, char const *argv[]) {
  int n;
  printf("Enter the Number of Elements\n");
  scanf("%d",&n);
  int a[n];
  accept(a,n);
  display(a,n);
  quickSort(a,0,n-1);
  display(a,n);
  return 0;
}
void accept(int a[],int n) {
  int i;
  printf("Enter the Values now\n");
  for(i=0;i<n;i++) {
    scanf("%d",&a[i]);
  }
  printf("Accepting done\n");
  return;
}
void display(int a[],int n) {
  int i;
  printf("Printing Array\n");
  for(i=0;i<n;i++) {
    printf("%d\n",a[i]);
  }
}
void quickSort(int a[],int start,int end) {
  int pivot,i,j;
  i = start;
  j = end;
  pivot = (start+end)/2;//Pivot is the mid element as it increases efficiency of Algorithm in Average Cases
  if(start<end) {
      while(i<j) {
        while(a[i]<a[pivot] && i<end)
          i++;
        while(a[j]>=a[pivot] && j>=start)
          j--;
        swap(&a[i],&a[j]);
      }
      if(a[pivot] != a[pivot])
        swap(&a[pivot],&a[j]);
        quickSort(a,start,j-1);
        quickSort(a,j+1,end);
  }
}
void swap(int *a,int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
