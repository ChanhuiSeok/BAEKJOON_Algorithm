#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
int dp[31];

int main() {

	int N;
	scanf("%d", &N);

	dp[0] = 1;
	dp[2] = 3;

	for (int i = 4; i <= N; i = i + 2) {

		dp[i] += dp[i - 2] * dp[2];

		for (int j = 4; j <= i; j=j+2) {
			dp[i] += 2 * dp[i - j];
		}

	}

	printf("%d", dp[N]);
	
}