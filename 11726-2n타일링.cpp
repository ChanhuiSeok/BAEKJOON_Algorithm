
#include <iostream>
#include <cstdio>

using namespace std;
long long int dp[1001];

/* [2]锅规过
int tile(int x) {
	
	if (dp[x] == 0) {
		dp[x] = (tile(x - 1) + tile(x - 2)) % 10007;
	}
	else {
		return dp[x];
	}
	return dp[x];
	
}
*/

int main() {

	int N;
	scanf("%d",&N);

	dp[1] = 1;
	dp[2] = 2;
	
	///[1]锅规过
	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}
	///
	
	///[2]//
	///tile(N);

	printf("%lld", dp[N]);
	
	return 0;
}