#include <stdio.h>
#include <stdlib.h>

void shift_element(int *pElement, int *arr) {
	// pElement points to an out-of-order element in 
	// int[] called "arr"
	int ivalue;
	for (ivalue = *pElement; pElement != arr && *(pElement - 1) > ivalue; pElement--) {
		*pElement = *(pElement - 1);
	}
	*pElement = ivalue;
}

void insertion_sort(int *arr, int length) {
	// get size of array
	for (int i=1; i < length; ++i) {
		if (*(arr + i) < *(arr + i - 1)) shift_element(arr + i, arr);
	}

}


int main() {

	int *arr = malloc(sizeof(int)*5);
	arr[0] = 51;
	arr[1] = 10;
	arr[2] = 2078;
	arr[3] = 2;
	arr[4] = 3;

	// before sorting
	for (int i=0; i < 5; ++i) {
		printf("%d ", *(arr + i));
	}
	printf("\n");

	// sort
	insertion_sort(arr, 5);

	// after sorting
	for (int i=0; i < 5; ++i) {
		printf("%d ", *(arr + i));
	}

	free(arr);

	return 0;
}