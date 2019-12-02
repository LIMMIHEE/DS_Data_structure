#include<stdio.h>
#define SIZE 8

enum boolean { false, true };

int cqueue[SIZE];
int frount = 0, rear = -1;
int cnt = 0;

enum boolean add(int data) {
	if (cnt == SIZE) {
		printf("Queue is full!\n");
		return false;
	}
	cqueue[++rear%SIZE] = data;	//++rear%SIZE rear�� ��� �����ϴϱ� SIZE�� ���� ���� ��� 0~7�� �ݺ��Ѵ�.
	cnt++;
	printf("������ ��\n");
	return true;
}
int delete() {
	if (cnt == 0) {
		printf("Queue is empty!\n");
		return -1;
	}
	cnt--;
	printf("������ ������\n");
	return cqueue[frount++%SIZE];
}

int main(void) {
	add(5); add(10); add(15); add(20);
	add(25); add(30); add(35); add(40);
	add(45);

	printf("%d\n", delete(5));
	printf("%d\n", delete(10));
	printf("%d\n", delete(15));
	printf("%d\n", delete(20));
	printf("%d\n", delete(25));
	printf("%d\n", delete(30));
	printf("%d\n", delete(35));
	printf("%d\n", delete(40));
	printf("%d\n", delete(45));
	
	add(50); add(55); add(60);
	return 0;
	
}