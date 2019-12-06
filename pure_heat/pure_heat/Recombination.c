#include <stdio.h>
#define R 3

//전역변수 선언
int b[R];
int cnt = 0;
//함수 선언
void ReCombination(int  a[], int n, int r, int ii);
void Com();

void Com() {
	cnt++;
	int i;
	for (i = 0; i < R; i++)
		printf("%5d", b[i]);
	printf("\n");
}

void ReCombination(int  a[], int n, int r, int ii) {
	int i;
	if (r >= R) Com();
	else {
		for (i = ii; i < n; i++) {
			b[r] = a[i];
			ReCombination(a, n, r + 1, i);
		}
	}
}

int main(void) {
	int a[] = { 1,2,3,4,5 };
	int n = sizeof(a) / sizeof(int);

	ReCombination(a, n, 0, 0);

	printf("중복조합 개수 : %d\n", cnt);

	return 0;
}