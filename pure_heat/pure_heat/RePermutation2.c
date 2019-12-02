#include<stdio.h>
#define R 3
int b[R];

void Reper(void) {
	int i;
	for (i = 0; i < R; i++) {
		printf("%5d", b[i]);
	}
	printf("\n");
}

void Swap(int *p1, int *p2) {
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void Repermutation(int a[], int r, int n) {
	int i;

	if (r == R) {
		Reper();
	}
	else {
		for (i = 0; i < n; i++) {
			Swap(&a[0], &a[i]);
			b[r] = a[0];
			Repermutation(a, r + 1, n);
			Swap(&a[0], &a[i]);
		}
	}
}


int main(void) {
	int a[] = { 1,2,3,4,5 };
	int n = sizeof(a) / sizeof(int);
	Repermutation(a, 0, n);

	return 0;
}