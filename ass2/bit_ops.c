#include <stdio.h>
#include <limits.h>
#include <float.h>


int main() {

	int val = 0xCAFE;
	int count = 0;

	// check 1 - LSB
	int bit_result = val & 15;
	while (bit_result != 0) {
		if ((bit_result & 1) > 0) {
			count++;
		}
		bit_result >>= 1;
	}
	if (count >= 3) { puts("passes check 1"); }

	// check 2 - reverse bytes
	int buffer = val & 0xFF;
	int next_result = (val >> 8);
	next_result |= (buffer << 8);
	printf("output is "); 
	printf("%d", next_result);

	

	return 0;
}