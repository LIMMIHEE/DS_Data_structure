#include<stdio.h>
#include<limits.h>
void heepSort(int a[], int n) {
	int value, i, parent, child;
	for (i = n / 2; i >= 1; i--) {
		value = a[i];
		parent = i;
		while ((child = parent * 2) <= n) {
			if (child + 1 <= n && a[child] < a[child + 1]) child++;
			if (value >= a[child]) break;
			a[parent] = a[child];
			parent = child;
		}
		a[parent] = value;
	}

	while (n > 1) {
		value = a[n];
		a[n--] = a[1];
		parent = 1;
		while ((child = parent * 2) <= n) {
			if (child + 1 <= n && a[child] < a[child + 1]) child++;
			if (value >= a[child]) break;
			a[parent] = a[child];
			parent = child;
		}
		a[parent] = value;
	}
}

int main() {
	int a[] = {INT_MIN, 56,7,8,10,39,21,18,28,20,67,2,4};
	int i, n = sizeof(a) / sizeof(int);
	heepSort(a, n - 1);
	printf("Heep Sort : ");
	for (int i = 1; i < n; i++) {
		printf("%5d",a[i]);
	}
	printf("\n");
	return 0;
}