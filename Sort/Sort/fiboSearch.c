#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int fiboSearch(int a[], int key, int n) {
	int fibo[] = { 0,2,2,3,5,8,13,21,34,55,89 };
	int index = 0, pos, k = 0;
	while (fibo[k] < n)k++;
	while (k > 0) {
		pos = index + fibo[--k];
		if (pos >= n||key <a[pos]);
		else if (key > a[pos]) {
			index = pos;
			k--;
		}
		else return pos;
	}
	return -1;
}
int main() {
	int a[16] = { 1,2,5,11,11,20,21,31,32,40,41,45,50,60,61,71 };
	int n = sizeof(a) / sizeof(int);
	int key, index;
	printf("찾을 값 : ");
	scanf_s("%d", &key);
	index = fiboSearch(a, key, n);
	if (index == -1)printf("없음!");
	else printf("%d를 %d에서 찾음!\n", key,index);
	return 0;
}