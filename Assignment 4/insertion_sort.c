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

Array insertionSort(Array mArray) {

  int temp;
  int i, j;

  for (i = 0;i < mArray.length;i++) {

    temp = mArray.array[i];

    for (j = i - 1;j >= 0 && mArray.array[j] > temp;j--) {

      mArray.array[j + 1] = mArray.array[j];
      mArray.array[j] = temp;

    }

  }

  return mArray;

}

int main(int argc, char const *argv[]) {

  display(insertionSort(acceptArray()));
  return 0;

}
