#include <stdio.h>
#include <stdlib.h>

//#define MAXELE 10
//#define MAXELE 100
//#define MAXELE 1000
//#define MAXELE 10000
#define MAXELE 100000

void main(){
	int i, j, t, pos, a[MAXELE];
	FILE *fptr;
	
	///// Random /////
	fptr = fopen("random.txt", "w");
	
	for(i = 0; i < MAXELE; ++i)
		a[i] = rand();
	
	for(i = 0; i < MAXELE; ++i)
		fprintf(fptr, "%d\n", a[i]);
	
	fclose(fptr);
	//////////////////
	
	///// Sort /////
	for(i = 0; i < MAXELE - 1; i++){
		pos = i;
		for(j = i + 1; j < MAXELE; j++){
			if(a[pos] > a[j]){
				pos = j;
			}
		}
		if(pos != i){
			t = a[i];
			a[i] = a[pos];
			a[pos] = t;
		}
	}
	///////////////
	
	///// ascending /////
	
	fptr = fopen("ascending.txt", "w");
	for(i = 0; i < MAXELE; i++)
		fprintf(fptr, "%d\n", a[i]);
	fclose(fptr);
	////////////////////
	
	///// descending /////
	fptr = fopen("descending.txt", "w");
	for(i = MAXELE - 1; i > -1; i--)
		fprintf(fptr, "%d\n", a[i]);
	fclose(fptr);
	//////////////////////
}
