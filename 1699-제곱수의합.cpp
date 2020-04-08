#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
int dp[100001];

int main() {

	int N;
	scanf("%d", &N);

	dp[0] = 0; dp[1] = 1;

	for (int i = 0; i <= N; i++)
		dp[i] = i;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j * j <= i; j++) {

			dp[i] = min(dp[i], dp[i - j * j] + 1);
			// 이후 j의 반복이 계속되어, 기존 dp[i]의 값과 새로운 dp[i - j * j] + 1
			// 과의 비교를 하려면 min 의 인자에 들어갈 두 값들은 위와 같다.
		}
	}

	printf("%d",dp[N]);

}