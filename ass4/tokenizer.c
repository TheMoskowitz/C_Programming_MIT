#include <string.h>
#include <stdio.h>

unsigned int stringspn(const char *str, const char *delims) {
	// Finds first non-delimiter character in string, returns its index
	unsigned int i = 0;
	while (strchr(delims, str[i]) != NULL) {
		i++;
	}
	return i;
}

unsigned int stringcspn(const char *str, const char *delims) {
	// Finds first delimiter character in string, returns its index
	unsigned int i = 0;
	while(strchr(delims, str[i]) == NULL) {
		i++;
	}
	return i;

}


int main() {
	
	char delims[] = " .,?!";
	char test_string[] = "Testing, 1 2 3.";

	unsigned int index;
	index = stringspn(test_string, delims);
	printf("The first non-delimiter character is \'%c\'\n", test_string[index]);
	index = stringcspn(test_string, delims);
	printf("The first delimiter character is \'%c\'\n", test_string[index]);


	return 0;
}