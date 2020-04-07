#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
int N, M;

int arr[9];
int visit[9];

void dfs(int cnt) {

	if (cnt == M) {
		for (int i = 0; i < cnt; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 1; i <= N; i++) {

		// 방문하지 않았으면,
		if (visit[i] == 0) {
			
			arr[cnt] = i;
			visit[i] = 1;
			dfs(cnt + 1);

			visit[i] = 0;
		}

	}


}


int main() {

	int rank = 1;
	scanf("%d %d", &N, &M);

	dfs(0);

	return 0;

}