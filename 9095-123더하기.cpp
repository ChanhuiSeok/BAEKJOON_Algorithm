#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000001
#include <iostream>
#include <cstdio>

using namespace std;
int dp[12] = { 0, };

int func(int x) {

	// 구해져 있으면
	if (dp[x] != 0)
		return dp[x];

	// 안 구해져 있으면
	else{
		dp[x] = dp[x] + func(x - 1);
		dp[x] = dp[x] + func(x - 2);
		dp[x] = dp[x] + func(x - 3);
	}
	return dp[x];
}

int main() {

	int test_case;
	int n;
	int* result;

	dp[1] = 1; dp[2] = 2; dp[3] = 4;

	scanf("%d", &test_case);
	result = (int*)malloc(sizeof(int) * test_case);

	for (int i = 0; i < test_case; i++) {

		scanf("%d", &n);
		func(n);
		result[i] = dp[n];

	}
	
	for (int j = 0; j < test_case; j++) {
		printf("%d\n", result[j]);
	}

}