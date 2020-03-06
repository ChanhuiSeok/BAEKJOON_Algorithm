#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int house[1001][3];
int dp[1001][3];

int MIN(int a, int b) {
	if (a <= b)
		return a;
	else
		return b;
}

int main() {

	int N, min = 999999;
	int sum = 0;
	int i, j;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &house[i][j]);
		}
	}

	//(1) dp 배열 맨 첫째줄은 첫 집이 선택하는 경우므로 그대로 채움
	dp[0][0] = house[0][0];
	dp[0][1] = house[0][1];
	dp[0][2] = house[0][2];

	//(2) 진행
	for (i = 1; i < N; i++) {
		for (j = 0; j < 3; j++) {
			// 현재 열을 제외한 다른 열의 직전 행을 확인
			if (j == 0) {			
				// 직전 행의 1, 2중 최소값을 더한다.
				dp[i][j] = house[i][j] + MIN(dp[i - 1][1], dp[i - 1][2]);
			}
			else if (j == 1) {
				dp[i][j] = house[i][j] + MIN(dp[i - 1][0], dp[i - 1][2]);
			}
			else if (j == 2) {
				dp[i][j] = house[i][j] + MIN(dp[i - 1][0], dp[i - 1][1]);
			}

			if (i == N - 1) {
				if (min >= dp[i][j])
					min = dp[i][j];
			}
		}
	}

	printf("%d",min);

	return 0;
}