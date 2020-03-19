#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;
int tri[501][501];

int main() {

	int n;
	int cnt = 0;
	int sum = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <i+1; j++) {
			scanf("%d", &tri[i][j]);
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) 
				tri[i][j] += tri[i - 1][j];
			else if (i == j) {
				tri[i][j] += tri[i - 1][j - 1];
			}
			else {
				tri[i][j] = max(tri[i][j]+tri[i - 1][j-1], tri[i][j]+tri[i - 1][j]);
			}
		}
	}

	// 맨 마지막줄에서 최댓값 찾기
	for (int i = 0; i < n; i++) {
		sum = max(sum, tri[n-1][i]);
	}

	printf("%d",sum);
	
}