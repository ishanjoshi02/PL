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

Array bubbleSort(Array a) {

  int i, j;

  for (i = 0;i < a.length;i++) {

    for (j = 0;j < a.length - i - 1;j++) {

      if (a.array[j] > a.array[j+1]) {

        int temp = a.array[j];
        a.array[j] = a.array[j+1];
        a.array[j+1] = temp;

      }

    }

  }

  return a;

}

int main(int argc, char const *argv[]) {

  display(bubbleSort(acceptArray()));
  return 0;

}
