#include<stdio.h>
int n;

void preOrder(char a[],int nodeNum) {
	if (nodeNum < n && a[nodeNum]!=NULL) {
		printf("%c  ", a[nodeNum]);
		preOrder(a,nodeNum*2);
		preOrder(a, nodeNum * 2+1);
	}
}
void InOrder(char a[], int nodeNum) {
	if (nodeNum < n && a[nodeNum] != NULL) {
		InOrder(a, nodeNum * 2);
		printf("%c  ", a[nodeNum]);
		InOrder(a, nodeNum * 2 + 1);
	}
}
void PostOrder(char a[], int nodeNum) {
	if (nodeNum < n && a[nodeNum] != NULL) {
		PostOrder(a, nodeNum * 2);
		PostOrder(a, nodeNum * 2 + 1);
		printf("%c  ", a[nodeNum]);
	}
}

int main(void) {
	char a[] = { NULL ,'A','B','C','D','E',NULL ,'F',NULL ,NULL ,'G',NULL ,NULL ,NULL ,'H','I',
					NULL ,NULL ,NULL ,NULL ,NULL ,'J'};
	 n = sizeof(a) / sizeof(char);

	 preOrder(a,1);
	 printf("\n");
	 InOrder(a, 1);
	 printf("\n");
	 PostOrder(a, 1);
}