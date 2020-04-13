#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

typedef long long int ll;

ll dp[100001];
ll dp_plus[100001];

int main() {

	int T, N;
	scanf("%d", &T);

	dp[1] = 1; // 초기값
	dp[2] = 1; // 초기값
	dp[3] = 1; // 초기값

	dp_plus[0] = 1;
	dp_plus[1] = 0;
	dp_plus[2] = 0;
	dp_plus[3] = 1;

	// dp_plus를 먼저 채운다.
	for (int t = 1; t <= T; t++) {

		scanf("%d", &N);
		for(int i = 4; i<=N; i++)
			dp_plus[i] = dp_plus[i - 3] + dp_plus[i - 2];

		for (int i = 4; i <= N; i++) {
			dp[i] = dp[i - 1] + dp_plus[i - 1];
		}


		printf("%lld\n", dp[N]);

	}

}

