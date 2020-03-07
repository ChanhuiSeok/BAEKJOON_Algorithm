#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000001
#include <iostream>
#include <cstdio>

using namespace std;

int dp[301] = { 0, };
int stair[301];

int MAXF(int a, int b) {
	if (a >= b)
		return a;
	else
		return b;
}

int func(int x) {

	if (dp[x] != -1)
		return dp[x];

	dp[x] = MAXF(func(x - 2) + stair[x], stair[x - 1] + stair[x] + func(x-3));
	return dp[x];
}

int main() {

	int N, sum = 0;
	scanf("%d", &N);


	for (int i = 1; i <= N; i++) {
		scanf("%d", &stair[i]);
		dp[i] = -1;
	}

	dp[0] = 0;
	dp[1] = stair[1];

	// 계단은 한 번에 한 계단 혹은 두 계단씩 오르기 가능
	// 연속 세 계단은 밟을 수 없음
	// 반드시 도착 계단을 밟아야 함

	func(N);
	printf("%d", dp[N]);

}