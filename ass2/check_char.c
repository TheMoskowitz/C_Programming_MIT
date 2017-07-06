#include <stdio.h>
#include <limits.h>
#include <float.h>

typedef enum {
	LOWER,
	UPPER,
	DIGIT,
	SPACE
} ascii;

ascii test(char c) {

	ascii answer;
	if ((c > 47) && (c < 58)) {
		answer = DIGIT;
		return answer;
	}  else if ((c > 64) && (c < 91)) {
		answer = UPPER;
		return answer;
	} else if ((c > 96) && (c < 123)) {
		answer = LOWER;
		return answer;
	} else if (c == 32) {
		answer = SPACE;
		return answer;
	} else {
		return -1;
	}

}


int main() {

	char c;

	printf("Enter a character:");
	c = getchar();

	int answer = test(c);

	if (answer == LOWER) { puts("It was a lowercase letter"); }
	else if (answer == UPPER) { puts("It was an uppercase letter"); }
	else if (answer == DIGIT) { puts("It was a number"); }
	else if (answer == SPACE) { puts("It was a space"); }
	else { puts("Unrecognized"); }

	return 0;
}