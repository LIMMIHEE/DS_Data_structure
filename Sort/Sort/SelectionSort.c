#include<stdio.h>


int main() {
	int a []= {10,5,7,12,9,16,1,3};
	int num = sizeof(a) / sizeof(int);
	int MIN ;
	int N = 0;

	for (int j = 0; j < num-1; j++) {
		MIN = a[j];
		N = j;	//얘 안넣으면  9 9 할때 9가 2개 생김.
		for (int i = j+1; i < num; i++) {
			if (MIN >= a[i]) {
				MIN=a[i];
				N = i;
			}
		}
		a[N] = a[j];
		a[j] = MIN;
		
		for (int i = 0; i < num; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
	}

}