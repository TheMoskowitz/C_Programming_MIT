#include <stdio.h>
#include <stdlib.h>

void shift_element_by_gap(unsigned int i, unsigned int gap, int *arr) {

	int ivalue;

	for (ivalue = *(arr+i); i >= gap && *(arr+i-gap) > ivalue; i -= gap) {
		*(arr+i) = *(arr+i-gap);
		*(arr+i-gap) = ivalue;
	}
}

void shell_sort(int *arr, unsigned int length) {
	
	unsigned int gap, i;
	for (gap = length/2; gap > 0; gap--) {
		for (i=length-1; i >= gap; i--) {
			if (*(arr + i) < *(arr + i - gap)) shift_element_by_gap(i, gap, arr);
		}

	}

}

int main() {

	int *arr = malloc(sizeof(int) * 6);
	arr[0] = 52;
	arr[1] = 693;
	arr[2] = 58;
	arr[3] = 91;
	arr[4] = 293;
	arr[5] = 1;

	printf("unsorted\n");
	for (int i = 0; i < 6; ++i) {
		printf("%d ", arr[i]);
	}

	shell_sort(arr, 6);

	printf("\nsorted\n");
	for (int i = 0; i < 6; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	free(arr);

	return 0;
}