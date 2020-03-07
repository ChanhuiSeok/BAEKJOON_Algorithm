#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000001
#include <iostream>
#include <cstdio>

using namespace std;

int dp[10002] = { 0, };
int grape[10002];

int MAXF(int a, int b) {
	if (a >= b)
		return a;
	else
		return b;
}
int main() {

	int n, max = -10000;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &grape[i]);
		dp[i] = 0;
	}

	dp[0] = 0;
	dp[1] = grape[1];
	max = dp[1];

	if (n >= 2) {
		dp[2] = grape[1] + grape[2];
		max = dp[2];
	}

	if(n >= 3){
		for (int i = 3; i <= n; i++) {
			dp[i] = MAXF(grape[i] + grape[i - 1] + dp[i - 3], grape[i] + dp[i - 2]);
			dp[i] = MAXF(dp[i - 1], dp[i]);

			if (max <= dp[i]) {
				max = dp[i];
			}
		}
	}

	printf("%d", max);
}