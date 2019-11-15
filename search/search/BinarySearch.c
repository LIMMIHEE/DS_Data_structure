#include<stdio.h>

int binarySearch(int a[], int key, int n) {
	int left = 0, right = n - 1, mid;
	while (left<= right) {
		mid = (left + right) / 2;
		if (key == a[mid]) return mid;
		else if (key > a[mid]) left = mid + 1; 
		else right = mid - 1;
	}
}

int main(void) {
	int a[] = { 3,7,11,19,25,33,49,51,67,85,100 };
	int n = sizeof(a) / sizeof(int), index, key;
	printf("ã�� �� : ");
	scanf_s("%d", &key);
	index = binarySearch(a, key, n);
	if (index >= 0) printf("\n%d��(��) %d���� ã��!!\n", key, index);
	else printf("\n ã���� �ϴ� ���� ����! \n"); 

	return 0;
}