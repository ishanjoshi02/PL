#include <stdio.h>
#include <stdlib.h>
void binarySearch(int a[],int key,int start,int end);
int main(int argc, char const *argv[]) {
  int key,elements;
  printf("Enter the Number of Elements\n");
  scanf("%d",&elements);
  int a[elements];
  printf("Enter the Elements now\n");
  for(int i=0;i<elements;i++) {
    scanf("%d",&a[i]);
  }
  printf("Enter the Key Element\n");
  scanf("%d",&key);
  binarySearch(a,key,0,elements);
  return 0;
}
void binarySearch(int a[],int key,int start,int end) {
  int mid = (start+end)/2;
  if(a[mid]==key) {
    printf("Found %d at %d",a[mid],mid);
  }
  else if(start<end) {
    binarySearch(a,key,start,mid-1);
  }
  else {
    binarySearch(a,key,mid+1,end);
  }
}
