#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int arr[21];
int visit[21];
vector <int> result;
int N, S, sum;
int resultCnt;

void dfs(int cnt, int limit) {

	if (result.size() == limit) {

		for (int j = 0; j < result.size(); j++) {
			sum += result[j];
		}
		if (sum == S) 
			resultCnt += 1;
		
		sum = 0;
		return;
	}

	for (int i = cnt; i < N; i++) {

		result.push_back(arr[i]);
		dfs(i + 1, limit);
		result.pop_back();

	}

}


int main() {

	scanf("%d %d", &N, &S);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	for (int k = 0; k < N; k++) {
		dfs(0, k + 1);
	}

	printf("%d", resultCnt);

	return 0;

}