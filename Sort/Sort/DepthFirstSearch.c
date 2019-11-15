#define SIZE 8
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
typedef enum {false,true} bool;
int stack[SIZE];
int top = -1;
bool push(int index) {
	if (top == SIZE) {
		return false;
	}stack[++top] = index;
	return true;
}
int pop(void) {
	if (top == -1) return -1;
	return stack[top--];
}

void DepthFirstSearch(bool G[][SIZE], char V[]) {
	bool chk[SIZE] = { false };
	int i, j; 
	char startV;
	printf("출발 정점 : ");
	scanf_s("%c",&startV,1);
	for (i = 0; i < SIZE; i++) {
		if (startV = V[i])break;
	}
	printf("%c", startV); chk[i] = true;
	do {
		for (j = 0; j < SIZE; j++) {
			if (G[i][j] == 1 && chk[j] == 0) {
				printf("-> %c", V[j]);
				chk[j] = 1; push(i); i = j; break;
			}
		}if (j == SIZE) { i = pop(); }
	} while (i >= 0);
	printf("\n");
}
int main() {
	bool G[][8] = {
		{0,1,0,1,0,0,0,0},
		{1,0,0,0,1,0,1,0},
		{0,0,0,0,1,1,0,0},
		{1,0,0,0,0,1,0,0},
		{0,1,1,0,0,0,1,0},
		{0,0,1,1,0,0,0,1},
		{0,1,0,0,1,0,0,1},
		{0,0,0,0,0,1,1,0}
	};
	char V[] = {'A','B','C','D','E','F','G','H'};
	int i, j=0;
	for (i = 0; i < SIZE; i++) {
		
	}
	DepthFirstSearch(G, V);
	return 0;

}