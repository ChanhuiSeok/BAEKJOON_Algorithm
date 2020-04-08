#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int dp[2][1000002];

int main() {
	
	int T, input;
	int row = 0, col = 0;
	int sumV = 0, maxSum = -1;

	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d", &n);

		for (int i = 0; i < 2; i++) {
			for (int j = 2; j < n+2; j++) {
				scanf("%d", &input);
				dp[i][j] = input;
			}
		}


		for (int i = 2; i < n + 2; i++) {		
			for (int j = 0; j < 2; j++) {

				//拉率 青捞搁
				if (j == 0) {
					dp[j][i] = dp[j][i] + max(dp[j + 1][i - 1], dp[j + 1][i - 2]);
				}
				//酒阀率 青捞搁
				else if (j == 1) {
					dp[j][i] = dp[j][i] + max(dp[j - 1][i - 1], dp[j - 1][i - 2]);
				}
			}		
		}

		printf("%d\n",max(dp[0][n+1], dp[1][n+1]));

	}

	

	return 0;
}