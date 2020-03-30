#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;
int dp[1001][1001];

int main() {

	int N, sum = 0;
	scanf("%d", &N);

	// 맨 마지막 요소 설정
	for (int i = 0; i < 10; i++) {
		dp[N - 1][i] = 10 - i;
	}

	// dp 진행
	for (int j = N - 2; j >= 0; j--) {
		for (int k = 0; k < 10; k++) {
			for (int m = k; m < 10; m++) {
				dp[j][k] += (dp[j + 1][m]);
			}
			dp[j][k] = dp[j][k] % 10007;
		}
	}

	printf("%d", dp[0][0]);
	
}