#include <stdio.h>
void shellSort(int *a, int n) {
	int i, j, key = 0,t;
	for(t= n/2; t>=1; t/=2){
		for (i = t; i < n; i++) {
			key = a[i];
			for (j = i - t; j >= 0; j-=t) {
				if (key >= a[j]) break;
				a[j + t] = a[j];
			}
			a[j + t] = key;
		}
	}
}

int main(void) {
	int  a[] = { 21,10,1,15,7,124,76,11,20,1,10,4,19 };
	int n = sizeof(a) / sizeof(int);
	shellSort(a, n);
	printf("½© Á¤·Ä: ");
	for (int i = 0; i < n; i++) {
		printf("%5d ", a[i]);
	}
	printf("\n");
	return 0;
}