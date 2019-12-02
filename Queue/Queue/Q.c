#include<stdio.h>
#define SIZE 8

enum boolean{false,true};

int gueue[SIZE]; 
int frount = 0, rear = -1;

enum boolean add(int data) {
	if (rear == SIZE - 1) {
		printf("Queue is full!\n");
		return false;
	}
	gueue[++rear] = data;
	return true;
}
int delete(void) {
	if (frount > rear) {
		printf("Queue is empty!\n");
		return -1;
	}
	return gueue[frount++];
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
	return 0;
	//���������� ������ �������� ����, ������ �Ұ��ϴ�.
	//add�� �ص� ��� full�� ���´�,
	// �� ���α׷��� ��ȸ�� ���α׷�,
	// �̷� ���α׷��� ���� ���α׷��̶�� �Ѵ�.(Linear Queue)
}