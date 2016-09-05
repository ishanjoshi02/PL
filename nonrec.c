#include <stdio.h>
void partition(int a[],int start,int end) {
	if(start<end) {
		int mid;
		mid = (start+end)/2;
		partition(a,start,mid);
		partition(a,mid+1,end);
		sort(a,start,end);
	}
}
void sort(int a[],int start,int end) {
	int i,j,pivot,temp;
	i = start+1;
	j = end;
	pivot = (start+end)/2;
	while(i<j) {
		while(a[i]<a[pivot]) {
			i++;
		}
		while(a[j]>a[pivot]) {
			j--;
		}
		swapper(&a[j],&a[i]);
	}
	swapper(&a[j],&a[pivot]);
}
void swapper(int *a,int *b) {
	int t;
	t = *a;
	*a = *b;
	*b = t;
}
int main() {
	int i,n;
	printf("Enter the Number of Elements in the Array\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter the Elements in the Array Now\n");
	for(i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	printf("Finished Accepting\n");
	sort(a,0,n-1);
	partition(a,0,n-1);
	for(i=0;i<n;i++) {
		printf("%d\n",a[i]);
	}
}
