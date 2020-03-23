#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
int dp[1001];

int main() {

	int N, input;
	int sum = 0;
	int max = 0;
	int maxDP = -100;
	scanf("%d", &N);

	vector<int> v;

	for (int i = 0; i < N; i++) {
		scanf("%d", &input);
		v.push_back(input);
	}

	dp[0] = 0;

	for (int i = 0; i < N; i++) {		
		max = 0;

		for (int j = 0; j < i; j++) {
			if (v[i] > v[j] && max < dp[j]) {
					max = dp[j];
			}
		}
		dp[i] = max + 1;

		if (maxDP < dp[i]) {
			maxDP = dp[i];
		}
	}


	printf("%d", maxDP);

}