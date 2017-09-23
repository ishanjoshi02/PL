#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *array;
  int length;
}Array;

Array acceptArray() {

  Array a;

  printf("Enter the length of the Array\n");
  scanf("%d", &a.length);

  a.array = (int *) malloc(sizeof(int) * a.length);

  printf("Enter the Elements now\n");
  int i;
  for (i = 0;i < a.length;i++) {

    scanf("%d", &a.array[i]);

  }

  return a;

}

void display(Array a) {

  int i;
  for (i = 0;i < a.length;i++) {

    printf("%d\t", a.array[i]);

  }

  printf("\n");

}

Array selectionSort(Array mArray) {

  int i, j;
  int min;
  int n = mArray.length;

  for (i = 0;i < n - 1;i++) {

    min = i;
    for (j = i + 1;j < n;j++) {

      if (mArray.array[j] < mArray.array[min]) {

        min = j;

      }

    }

    int temp = mArray.array[min];
    mArray.array[min] = mArray.array[i];
    mArray.array[i] = temp;

  }

  return mArray;

}

int main(int argc, char const *argv[]) {

  display(selectionSort(acceptArray()));
  return 0;

}
