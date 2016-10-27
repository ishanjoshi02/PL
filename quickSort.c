#include <stdio.h>
#include <stdlib.h>
//To use this function i.e. quickSort(), use this #include "quickSort.c" and then directly use the quickSort func() 
//just like printf(), scanf() etc.
//Set int passByPass to 99 to display the Pass-by-Pass output
//Since this program originally had a main() too, I had to change some things, and haven't tested it yet
//So Errors might exist
//If any errors exist please make necessary changes.
int passByPass;
void swap(int *,int *) {
   int temp = *a;
  *a = *b;
  *b = temp;
}
void quickSort(int a[],int start,int end,int total) {
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
        if(passByPass == 99) {
        int t;
        for(t=0;t<total;t++) 
          printf("%d\n",a[t]);
        }
        quickSort(a,start,j-1,total);
        quickSort(a,j+1,end,total);
  }
}
