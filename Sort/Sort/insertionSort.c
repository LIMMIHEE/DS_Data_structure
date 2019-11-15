#include <stdio.h>
void InsertionSort(int *a, int n) {
	int i, j, key=0;
	for (i = 1; i < n; i++) {
		key = a[i];
		for (j = i - 1; j >= 0; j--) {
			if (key >= a[j]) break;
			a[j + 1] = a[j];
		}
		a[j + 1] = key;
	}
}

int main(void) {
	int  a[] = {21,15,7,11,20,10,4,19};
	int n = sizeof(a) / sizeof(int);
	InsertionSort(a, n);
	printf("���� ����: ");
	for (int i = 0; i < n; i++) {
		printf("%5d",a[i]);
	}
	printf("\n");
	return 0;
}