#include <stdio.h>
#define NUMELE 100000

void main(){
	int i, j, t, pos, a[NUMELE];
	FILE *fptr;
	for(i = 0; i < NUMELE; ++i)
		scanf("%d", &a[i]);
	for(i = 0; i < NUMELE - 1; i++){
		pos = i;
		for(j = i + 1; j < NUMELE; j++){
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
	fptr = fopen("ascending.txt", "w");
	for(i = 0; i < NUMELE; i++)
		fprintf(fptr, "%d\n", a[i]);
	fclose(fptr);
	
	fptr = fopen("descending.txt", "w");
	for(i = NUMELE - 1; i > -1; i--)
		fprintf(fptr, "%d\n", a[i]);
	fclose(fptr);
}
