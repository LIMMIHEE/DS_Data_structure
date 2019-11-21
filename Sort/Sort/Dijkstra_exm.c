#include<stdio.h>
#include<limits.h>
#define M INT_MAX
#define SIZE 8

int Minval(int D[], int chk[]) {
	int i, minvalue = M, index;
	for (i = 0; i < SIZE; i++) {
		if (chk != 1 && minvalue > D[i]) {
			minvalue = D[i];
			index = i;
		}
	}
	return index;
}

void Dijstra(int G[][SIZE], int D[], int i, int p[]) {
	int chk[] = { 0 }, j = 0, cnt = 0;
	for (j = 0; j < SIZE; j++) {
		if (D[i][j] > 0 && D[i][j] < M) {
			D[j] = G[i][j]; p[j] = i;
		}
	}
	chk[i] = 1; cnt++;

	while (cnt < SIZE) {
		i = Minval(D, chk);
		for (j = 0; j < SIZE; j++) {
			if (D[i][j] > 0 && D[i][j] < M) {
				D[j] = D[i] + D[i][j]; p[j] = i;
			}
			chk[i] = 1;  cnt++;
		}
	}
}

int main(void) {
	int G[]][SIZE] = { {},{},{},{},{},{},{},{} };
	int V[] = { 'A','B','C','D','E','F','G','H' };
	int D[SIZE] = {M};
	int p[SIZE] = {0};
	int i = 0,aV,bV; 
	printf("출발정점 : ");
	scanf_s("%c", &aV, 1);
	printf("도착정점 : ");
	scanf_s("%c", &bV, 1);
	for (i = 0; i < SIZE; i++) { if (V[i] == bV) break; }
	Dijstra(G, D, i, p);
	for (i = 0; i < SIZE; i++) { if (V[i] == aV) break; }
	printf("%c 부터 %c 까지의 최단거리 : %d ", aV, bV, D[i]);
	printf("최단 거리 : %c", aV);
	while (V[i] !=bV) {
		printf("-> %c", V[i]);
	}
	printf("\n");

	return 0;

}