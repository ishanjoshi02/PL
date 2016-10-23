#include <stdio.h>
#include <stdlib.h>
void bubbleSort(int a[],int n);
int binarySearch(int a[],int key,int start,int end);
int main(int argc, char const *argv[]) {
  int key,elements,i;
  printf("Enter the Number of Elements\n");
  scanf("%d",&elements);
  int a[elements];
  printf("Enter the Elements now\n");
  for(int i=0;i<elements;i++) {
    scanf("%d",&a[i]);
  }
  bubbleSort(a,elements);
  printf("Enter the Key Element\n");
  scanf("%d",&key);
  i = binarySearch(a,key,0,elements);
  if(i!=(-1)) {
    printf("Found Key Element %d at %d\n",key,i);
  }
  return 0;
}
void bubbleSort(int a[],int n) {
  int flag = 1,temp;
  for(i=1;i<n && flag == 1;i++) {
    flag = 0;
    for(j=0;j<n-i;j++) {
      if(a[j]>a[j+1]) {
        flag = 1;
        temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
      }
    }
  }
}
int binarySearch(int a[],int key,int start,int end) {
  int mid = (start+end)/2;
  while(a[mid]!=key && i<=j) {
    if(key>a[mid]) {
      start=mid+1;
    }
    else {
      end=mid-1;
    }
    mid=(start+end)/2;
  }
  if(start<=end) {
    return mid;
  }
  return (-1);
}
