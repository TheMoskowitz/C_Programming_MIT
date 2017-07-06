#include <stdlib.h>
#include <stdio.h>

// (a)
int factorial(int n) {

	int i = 2, ret = 1;
	while (i <= n) {
		ret *= i;
		i++;
	}
	return ret;

}

double rand_double () {
	// generate random number between 0 and 1
	double ret = (double)rand();
	return (ret / ((double)(RAND_MAX+1.0)));
}

int sample_geometric_rv(double p) {

	double q;
	q = rand_double();
	int n=0;
	while (q >= p) {
		q = rand_double();
		n++;
	}
	return n;
}

int main() {

	int ans;
	ans = factorial(6);
	printf("%d\n", ans);

	int result;
	double num = 0.000005;
	result = sample_geometric_rv(num);
	printf("%d\n", result);


	return 0;
}