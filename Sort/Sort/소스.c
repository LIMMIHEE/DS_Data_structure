#include<stdio.h>
#include<limits.h>
#define M INT_MAX
#define SIZE 8

void Dijkstra(int D[], int G[][SIZE], int p[], int i) {
	int j = 0, cnt = 0, chk[SIZE] = { 0 };
	for (j = 0; j < SIZE; j++) {
		if (G[i][j] > 0 && G[i][j] < M) {
			p[j] = i;
			D[j] = G[i][j];
		}
	}
	chk[i] = 1; cnt++;
	while (cnt < SIZE) {
		i = minval(D, chk);
		for (j = 0; j < SIZE; j++) {
			if (D[j] > D[i] + G[i][j]) {
				D[j] = D[i] + G[i][j];
				p[j] = i;
			}
		}
		chk[i] = 1;
		cnt++;
	}
}
int minval(int D[], int chk[]) {
	int index=0, i=0, minvalue = M;
	for (i = 0; i < SIZE; i++) {
		if (chk[i] == 0 && minvalue > D[i]) {
			minvalue = D[i];
			index = i;
		}
	}
	return index;
}
int main() {
	int G[][SIZE] = { {0,12,15,18,M,M,M,M},{12,0,M,M,33,26,M,M},{15,M,0,7,M,10,M,M},{18,M,7,0,M,M,11,M}
								,{M,33,M,M,0,17,M,15},{M,26,10,M,17,0,M,28},{M,M,M,11,M,M,0,20},{M,M,M,M,15,28,20,0} };
	int D[SIZE] = { M };
	int p[SIZE] = { 0 };
	int V[SIZE] = {'A','B','C','D','E','F','G','H'};
	int i;
	char aV, bV;
	printf("출발정점 : "); scanf_s("%c", &aV, 1);
	printf("도착정점 : "); scanf_s("%c", &bV, 1);
	for (i = 0; i < SIZE; i++) { if (V[i] == bV) break; }
	Dijkstra(D, G, p, i);
	for (i = 0; i < SIZE; i++) { if (V[i] == aV) break; }
	printf("%c 에서  %c 까지의 최단거리 : %d", aV, bV, D[i]);
	printf("최단거리 : ");
	while (V[i] != bV) {
		i = p[i];
		printf("-> %c",V[i]);
	}
}