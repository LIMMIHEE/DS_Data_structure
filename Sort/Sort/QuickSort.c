#include<stdio.h>
void QuickSort(int a[], int left, int right) {
	int pivot = a[left],j=right,i=left,temp;
	if (left < right) {
		while (i <j) {
			while (pivot >= a[i]&&right> i) i++;
			while (pivot <= a[j]&&left < j) j--;
			if (i < j) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	a[left] = a[j]; a[j] = pivot;
	QuickSort(a,left,j-1);
	QuickSort(a, j + 1, right);
	}
}

int main(void) {
	int a[] = {30,24,55,9,27,57,3,21,45,12,50,38,28,41,33};
	int n = sizeof(a) / sizeof(int);
	QuickSort(a, 0, n - 1);
	printf("Quick Sort : ");
	for (int i = 0; i < n; i++) {
		printf("%5d",a[i]);
	}


	return 0;
}