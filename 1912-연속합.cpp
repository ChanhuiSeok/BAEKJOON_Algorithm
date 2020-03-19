#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int dp[100001];

int main() {

	int n, sum = 0, input = 0;
	int maxV = -10000;
	scanf("%d", &n);


	for (int i = 0; i < n; i++) {
		scanf("%d", &input);
		dp[i] = input;
	}

	maxV = dp[0];

	for (int i = 1; i < n; i++) {	
		if (dp[i] + dp[i - 1] > 0 && dp[i - 1] >0 ) {
			dp[i] = dp[i] + dp[i - 1];
		}
		
		if (dp[i] >= maxV) {
			maxV = dp[i];
		}
	}

	/*
	 for(int i=1;i<n;i++){
        dp[i]=max(arr[i],dp[i-1]+arr[i]);
        ans=max(ans,dp[i]);
    } 이런식으로 구해도 됨
	*/


	printf("%d", maxV);

}