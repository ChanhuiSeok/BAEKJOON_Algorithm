#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
long long int dp[91][2];

int main() {

	int N, cnt;
	scanf("%d", &N);

	dp[1][0] = 0;
	dp[1][1] = 1;

	for (int i = 2; i <= N; i++) {
		if (dp[i - 1][0] >= 1) {
			dp[i][0] += dp[i - 1][0];
			dp[i][1] += dp[i - 1][0];
		}
		if (dp[i - 1][1] >= 1) {
			dp[i][0] += dp[i - 1][1];
		}
	}

	printf("%lld", dp[N][0] + dp[N][1]);

}