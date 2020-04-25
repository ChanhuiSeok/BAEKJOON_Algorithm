#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;
int N, M;
vector<int> v;
vector<int>::iterator iter;

void dfs(int cnt) {

	if (cnt == M) {
		
		for (int i = 0; i < M; i++)
			printf("%d ", v[i]);
		printf("\n");
		return;
	}

	for (int i = 1; i <= N; i++) {
		
		if (v.empty())
			v.push_back(i);
		else if (v[v.size() - 1] <= i) {
			v.push_back(i);
		}
		else
			continue;
		

		dfs(cnt + 1);
		v.pop_back();

	}

}

int main() {

	//int N, M;
	scanf("%d %d", &N, &M);

	dfs(0);

}