#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int dp[1001];
int arr[1001];

int main() {
	
	int N;
	int idx;
	int cnt;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}
	// arr에는 카드팩 가격을 나타낸 것임
	// 인덱스 번호는 카드팩에 들어있는 카드 갯수를 뜻함.
	cnt = N;
	dp[0] = 0;
	dp[1] = arr[1];

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + arr[j]);
		}
	}

	printf("%d",dp[N]);

}