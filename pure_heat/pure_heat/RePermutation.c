#include <stdio.h>
#define R 3

//전역변수 선언
int b[R];

//함수 선언
void Permutation(int  a[], int r, int n);
void per();
void swap(int* p1, int* p2);

void per() {
	int i;
	for (i = 0; i < R; i++)
		printf("%5d", b[i]);
	printf("\n");
}

void Permutation(int  a[], int r, int n) {
	int i;
	if (r == R)
		per();
	else {
		for (i = r; i < n; i++) {
			swap(a + r, a + i);
			b[r] = a[r];
			Permutation(a, r + 1, n);
			swap(a + r, a + i);
		}
	}
}

void swap(int* p1, int* p2) {
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

int main(void) {
	int a[] = { 1,2,3,4,5 };
	int n = sizeof(a) / sizeof(int);

	Permutation(a, 0, n);

	return 0;
}