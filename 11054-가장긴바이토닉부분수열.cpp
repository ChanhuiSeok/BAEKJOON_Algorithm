#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
int dp[1001];
int dp2[1001];

int main() {

	int N, input;
	int sum = 0;
	int maxV = -1;
	int pointIdx = 0;
	scanf("%d", &N);

	vector<int> v;

	for (int i = 0; i < N; i++) {
		scanf("%d", &input);
		v.push_back(input);
		dp[i] = 1;
		dp2[i] = 1;
	}
	/* 왼쪽에서 한번, 오른쪽에서 한 번은 했지만 두 배열의 합은 처음에 생각 못 함*/

	// 왼쪽에서 오른쪽으로 올라갈 때 (증가하는 것)
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {

			if (v[j] < v[i] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
	}

	// 오른쪽에서 왼쪽으로 내려갈 때 (증가하는 것)
	for (int i = N-1; i >= 0; i--) {
		for (int j = N-1; j > i; j--) {

			if (v[j] < v[i] && dp2[i] < dp2[j] + 1) {
				dp2[i] = dp2[j] + 1;
			}
		}
	}

	// 두 배열의 합
	for (int i = 0; i < N; i++) {
		int result = dp[i] + dp2[i];
		if (result > maxV)
			maxV = result;
	}
	
	printf("%d", maxV - 1);

}