#include<stdio.h>

#include <time.h>
#define MAXELE 100000

int interpolSearch(int a[], int n, int s){
	int i, pos;
	int l = 0, h = n - 1;
		
	while (l <= h && s >= a[l] && s <= a[h]){
		if (l == h){ 
            if (a[l] == s) return l; 
            return -1; 
        }
        
        int pos = l + (((double)(h-l) / (a[h]-a[l]))*(s - a[l]));
        
		if(a[pos] == s)
			return pos;
		if(s > a[pos])
			l = pos + 1;
		else if(s < a[pos])
			h = pos - 1;
	}
	return -1;
}

int main(int agn, char **ar){
	int a[MAXELE], n, i, s;
	
	clock_t start_t, end_t;
	float total_t;
	
	n = MAXELE;
	
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
		
	switch(ar[1][0]){
		case 'f':s = a[0];
		break;
		case 'm':s = a[MAXELE/2];
		break;
		case 'l':s = a[MAXELE-1];
		break;
	}
	
	start_t = clock();
	
	printf("%d\n", interpolSearch(a, n, s));
	
	end_t = clock();
	total_t = (float)(end_t - start_t)/CLOCKS_PER_SEC;
	
	printf("%f\n", total_t);
}
