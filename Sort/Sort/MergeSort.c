#include<stdio.h>
#include<stdlib.h>



void Merge(int a[], int left, int mid, int right) {
	int *result = (int *)malloc(sizeof(a)*(right - left + 1)); //동적할당
	//실제 배열은 아니지마 시작주소를 받았기 때문에 배열처럼 사용이 가능하다.
	int i = left, j = mid + 1, k = 0;

	while (i <= mid && j <= right) {
		if (a[i] < a[j]) {
			result[k++] = a[i++];
		}
		else {
			result[k++] = a[j++];
		}
	}
	if (i > mid) while (j <= right) {
		result[k++] = a[j++];
	}
	else while (i <= mid) {
		result[k++] = a[i++];
	}
	k = 0;
	for (i = left; i <= right; i++) {
		a[i] = result[k++];
	}

	free(result);
}


void Divide(int a[], int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		Divide(a,left,mid);
		Divide(a, mid+1, right);
		Merge(a, left, mid, right);
	}
}




int main(void) {
	int a[] = { 3, 56, 7, 14, 2,11 , 9, 6, 54, 63,22, 64 };
	int n = sizeof(a) / sizeof(int);
	int i;

	Divide(a, 0, n - 1);
	printf(" 병합 정렬 : ");
	for (i = 0; i < n; i++) {
		printf("%5d", a[i]);
	}
	printf("\n");

	return 0;
}