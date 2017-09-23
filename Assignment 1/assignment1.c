#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *array; // Stores the sequence of Numbers
	int length; // Stores the Size or Length of the Set.
} Set;

Set acceptSet() {

	Set mSet;

	int length, *temp;

	printf("Enter the Number of Integers in the Array\n");
	scanf("%d", &length);

	// Allocating Memory to the Temp array
	temp = (int *) malloc(sizeof(int) * length);

	printf("Enter the Elements of the Set\n");

	int i;

	for (i = 0;i < length;i++) {

		// No need to use & below, as temp + i will directly point to the Correct Address Space
		scanf("%d", (temp + i));

	}

	// Now Assign temp array and length to the Set mSet;
	mSet.length = length; // Using variables of the same name is allowed in this and such cases, as,
	// mSet.length belongs to the Struct variable whereas, the simple length variable belongs to the Function

	mSet.array = temp;

	// Return Set mSet for further operations.
	return mSet;

}

void displaySet(Set mSet) {

	int i;

	printf("{");
	for (i = 0;i < mSet.length - 1;i++) {

		printf("%d, ", mSet.array[i]);

	}
	printf("%d}\n", mSet.array[mSet.length - 1]);
	// Such code is written to print the Set in the conventional way i.e. {1, 2, 3}

}

// Do not use function name as union. Union is a keyword in c. Eclipse will show you an error in yellow
Set unionSet(Set a, Set b) {

	// Write variables on different lines according to their purpose
	// Eg. i and j will be used as loop counter, hence, write them on one line.
	// This will increase readability of your code and help you when you are debugging your code.
	Set c;
	int i, j;
	int k;
	int flag;

	int *temp; // Store all the Elements in this primarily. Then transfer into Set variable c

	// Allocate Memory to temp
	temp = (int *) malloc(sizeof(int) * (a.length + b.length));

	// Copying Elements of Set a into c
	for (i = 0, k = 0;i < a.length;i++, k++) {
		// Multiply initalizers and incrementors are allowed in the for loop

		temp[k] = a.array[i];

	}

	// Now loop through set b and if any element doesn't belong to a but does to b, add to c;

	for (i = 0;i < b.length;i++) {

		flag = 0;
		for (j = 0;j < a.length;j++) {

			if (b.array[i] == a.array[j])
				flag = 1; // Flag = 1 indicates the element exists in a too

		}

		if (flag == 0)
			temp[k++] = b.array[i];
		// If flag remains zero, this means that the element doesn't exist in a. Add to Set c

	}

	c.length = k;

	// Allocate memory for only necessary elements.
	c.array = (int *) malloc(sizeof(int) * c.length);

	// Now loop through temp and c.array and transfer elements from temp to c.
	// This method will save a lot of memory space and make other operations easier.

	for (i = 0;i < c.length;i++) {

		c.array[i] = temp[i];

	}

	// Union of Set a and b is complete. Return c. DO NOT DISPLAY C in this function.
	// Make a separate call to the displaySet() function.
	free(temp);
	return c;

}

Set intersection(Set a, Set b) {

	Set c; // Set used to store the intersection of Sets a and b
	int i, j;
	int k = 0;

	// Again using temp array to save memory.
	int *temp = (int *) malloc(sizeof(int) * (a.length + b.length));

	for (i = 0;i < a.length;i++) {

		for (j = 0;j < b.length;j++) {

			if (b.array[j] == a.array[i])
				temp[k++] = a.array[i];

		}

	}

	c.length = k;

	// Allocate memory for only necessary elements.
	c.array = (int *) malloc(sizeof(int) * c.length);

	// Loop through temp and c.array to Transfer elements from temp to c.array.

	for (i = 0;i < c.length;i++) {

		c.array[i] = temp[i];

	}

	free(temp);
	return c;

}

Set difference(Set a, Set b) {

	Set c;
	int i, j;
	int k = 0;
	int flag;

	// Difference returns the elements in a not in b
	// This similar to what we did in Union Function

	int *temp = (int *) malloc(sizeof(int) * (a.length));

	for (i = 0;i < a.length;i++) {

		flag = 0;

		for (j = 0;j < b.length;j++) {

			if (a.array[i] == b.array[j])
				flag = 1;

		}

		if (flag == 0)
			temp[k++] = a.array[i];

	}

	c.length = k;

	// Allocate memory to c.array
	c.array = (int *) malloc(sizeof(int) * c.length); // You can make this statement into a function or a Macro

	for (i = 0;i < c.length;i++) {

		c.array[i] = temp[i];

	}

	free(temp);
	return c;

}

Set symmetricDifference(Set a, Set b) {

	return unionSet(difference(a, b), difference(b, a));

}

int main(int argc, char **argv) {

	Set a, b; // Sets on which we are going to operate. Do not use 1, 2 as variables. It is not allowed.
	int option; // Used to store the option, the user chooses.

	do {

		printf(" 1. Accept Set A\n");
		printf(" 2. Accept Set B\n");
		printf(" 3. Display Set A\n");
		printf(" 4. Display Set B\n");
		printf(" 5. Union of the Two Sets\n");
		printf(" 6. Intersection of the Two Sets\n");
		printf(" 7. (A - B)\n");
		printf(" 8. (B - A)\n");
		printf(" 9. Symmetric Difference\n");
		printf("10. Exit\n");

		scanf("%d", &option);

		switch(option) {

		case 1 : {

			a = acceptSet();
			break;

		}

		case 2 : {

			b = acceptSet();
			break;

		}

		case 3 : {

			displaySet(a);
			break;

		}

		case 4 : {

			displaySet(b);
			break;

		}

		case 5 : {

			displaySet(unionSet(a, b));
			break;

		}

		case 6 : {

			displaySet(intersection(a, b));
			break;

		}

		case 7 : {

			displaySet(difference(a, b));
			break;

		}

		case 8 : {

			displaySet(difference(b, a));
			break;

		}

		case 9 : {

			displaySet(symmetricDifference(a, b));
			break;

		}

		case 10 : {

			exit(0); // You can also use return 0;
		}

		}

	} while (1); // This a do while true. It will run until main function returns, or exits

	return 0;

}
