#include<stdio.h>
void BubbleSort(int a[], int n) {
	int chk=1,j,i=1,temp;

		while (chk==1) {
			chk = 0;
			for (j = 0; j < n-i; j++) {
				if (a[j] > a[j + 1]) {
					chk = 1;
					temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
					chk = 1;
				}
			}
			i++;
		}
}
int main(void) {
	int a[] = { 21,25,7,11,45,72,38,100,51 };
	int n = sizeof(a) / sizeof(int);
	BubbleSort(a, n);
	printf("버블 정렬\n");
	for (int i = 0; i < n; i++) {
		printf("%5d", a[i]);
	}

	return 0;
}