#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 30

void analyze_file(char filename[]) {

	FILE *fp = NULL;
	if ((fp = fopen(filename, "r")) == NULL) {
		perror("Error opening file\n");
		exit(1);
	}
	printf("File opened\n");

	printf("%-25s TOTAL\n", "STATE");
	printf("--------------------------\n");

	char line[150];
	int total = 0;

	// This is the initial line with the category headings
	fgets(line, 150, fp);

	// These will hold the variables from each line
	char origin_code[MAX_SIZE];
	char origin_county[MAX_SIZE];
	char dest_code[MAX_SIZE];
	char dest_county[MAX_SIZE];
	char abbr[MAX_SIZE];
	char state[MAX_SIZE];
	int returning;
	int exempt;
	int agg_AGI;

	char mass_code[] = "\"25\"";

	int r;
	r = fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\n", origin_code, origin_county, dest_code, dest_county, 
															abbr, state, &returning, &exempt, &agg_AGI);

	while(r != EOF) {
		if (strcmp(mass_code, origin_code) == 0) {
			printf("%-25s %d\n", state, agg_AGI);
			total += agg_AGI;
		}
		r = fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\n", origin_code, origin_county, dest_code, dest_county, 
															abbr, state, &returning, &exempt, &agg_AGI);
	}
	printf("--------------------------\n");
	printf("%-25s %d\n", "TOTAL", total);

	fclose(fp);

}


int main() {

	char filename[] = "stateoutflow0708.txt";

	analyze_file(filename);


	return 0;
}