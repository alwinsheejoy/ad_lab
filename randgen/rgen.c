#include <stdio.h>
#include <stdlib.h>

#define MAXELE 100000

void main(){
	int i, j, t;
	FILE *fptr;
	fptr = fopen("random.txt", "w");
	for(i = 0; i < MAXELE; ++i)
		fprintf(fptr, "%d\n", rand());
	fclose(fptr);
}
