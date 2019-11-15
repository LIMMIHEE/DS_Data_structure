#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int InterSearch(int a[], int n, int key) {
	int left = 0, right = n - 1, index;
	while (left <= right) {
		if (a[left] == a[right])index = left;
		else {
			index = left + (right - left)*(key - a[left]) / (a[right] - a[left]);
			if (index < left) index = left;
			if (index > right) index = right;
		}
		if (key == a[index]) return index;
		else if (key > a[index])left = index + 1;
	}
	return -1;
}
int main() {
	int a[] = {3,7,10,12,14,18,21,33,35,48
	};
	int n = sizeof(a) / sizeof(int);
	int index, key;
	printf("찾을 값 : ");
	scanf_s("%d", &key);
	index = InterSearch(a, n, key);
	if (index == -1) {
		printf("값이 없음!");
	}
	else {
		printf("%d를 %d에서 찾음\n", key, index);
	}

	return 0;
}