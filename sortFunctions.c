#include <stdio.h>
#include <stdlib.h>
//This Program contains only basic sort functions like Bubble Sort, Selection Sort and Insertion Sort.
int i,j,passByPass;
void accept(int a[],int n);
void displayArray(int a[],int n);
void swap(int *a,int *b);
void bubbleSort(int a[],int n);
void insertionSort(int a[],int n);
void selectionSort(int a[],int n);
int main(int argc, char const *argv[]) {
  int option,n,*a;
  do {
    printf("1. Bubble Sort\n2. Insertion Sort\n3. Selection Sort\n4. Exit\n");
    scanf("%d",&option);
    switch (option) {
      case 1 : {
        printf("Enter Number of Elements\n");
        scanf("%d",&n);
        a = (int *)malloc(sizeof(int)*n);
        accept(a,n);
        printf("Do you want Pass by Pass Output\n1. Yes\n2. No\n");
        scanf("%d",&passByPass);
        bubbleSort(a,n);
        printf("Displaying Sorted List\n");
        displayArray(a,n);
        break;
      }
      case 2 : {
        printf("Enter Number of Elements\n");
        scanf("%d",&n);
        a = (int *)malloc(sizeof(int)*n);
        accept(a,n);
        printf("Do you want Pass by Pass Output\n1. Yes\n2. No\n");
        scanf("%d",&passByPass);
        insertionSort(a,n);
        printf("Displaying Sorted List\n");
        displayArray(a,n);
        break;
      }
      case 3 : {
        printf("Enter Number of Elements\n");
        scanf("%d",&n);
        a = (int *)malloc(sizeof(int)*n);
        accept(a,n);
        printf("Do you want Pass by Pass Output\n1. Yes\n2. No\n");
        scanf("%d",&passByPass);
        selectionSort(a,n);
        printf("Displaying Sorted List\n");
        displayArray(a,n);
        break;
      }
      case 4 : {
        return 0;
      }
    }
  } while(1);
}
void accept(int a[],int n) {
  int i;
  printf("Enter the Elements now\n");
  for(i=0;i<n;i++) {
    scanf("%d",&a[i]);
  }
  printf("Accepting Done\n");
}
void displayArray(int a[],int n) {
  int i;
  for(i=0;i<n;i++) {
    printf("%d\t",a[i]);
  }
}
void swap(int *a,int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
void bubbleSort(int a[],int n) {
  int flag = 1;
  for(i=1;i<n && flag == 1;i++) {
    flag = 0;
    for(j=0;j<n-i;j++) {
      if(a[j]>a[j+1]) {
        flag = 1;
        swap(&a[j],&a[j+1]);
      }
    }
    if(passByPass==1) {
      printf("Array at Pass %d",i+1);
      displayArray(a,n);
    }
  }
}
void insertionSort(int a[],int n) {
  int temp;
  for(i=0;i<n;i++) {
    temp = a[i];
    for(j=i-1;j>=0 && a[j]>temp;j--) {
      a[j+1] = a[j];
      a[j+1] = temp;
    }
    if(passByPass==1) {
      printf("Array at Pass %d",i+1);
      displayArray(a,n);
    }
  }
}
void selectionSort(int a[],int n) {
  int k;
  for(i=0;i<n;i++) {
    k = i;
    for(j=i+1;j<n;j++) {
      k = j;
    }
    if(k != i) {
      swap(&a[i],&a[k]);
    }
    if(passByPass==1) {
      printf("Array at Pass %d",i+1);
      displayArray(a,n);
    }
  }
}
