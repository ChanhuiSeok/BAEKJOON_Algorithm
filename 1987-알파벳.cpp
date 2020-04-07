#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int isExist = 0;
int R, C;
int maxCnt = 0;
int cnt = 0;

//상,하,좌,우
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

char input[21][21];
int visit[21][21];
int visitA[26];
vector <char> v;

void dfs(int y, int x) {

	for (int i = 0; i < 4; i++) {
		int ty = y + dy[i];
		int tx = x + dx[i];

		if (ty < R && ty >= 0 && tx < C && tx >= 0
			&& visit[ty][tx] == 0 && visitA[input[ty][tx]-65] == 0) {
			
			v.push_back(input[ty][tx]);
			visit[ty][tx] = 1;
			visitA[input[ty][tx] - 65] = 1;
			cnt += 1;

			if (maxCnt <= cnt) 
				maxCnt = cnt;
				
			dfs(ty, tx);
			visit[ty][tx] = 0;
			visitA[input[ty][tx] - 65] = 0;
			v.pop_back();
			cnt -= 1;

		}
	}

}


int main() {

	char str[21];
	scanf("%d %d", &R, &C);

	for (int i = 0; i < R; i++) {
		scanf("%s", &str);
		for (int j = 0; j < C; j++) {
			input[i][j] = str[j];
		}
	}

	// 시작 위치를 넣고, 방문 표시
	v.push_back(input[0][0]);
	visit[0][0] = 1;
	visitA[input[0][0] - 65] = 1;
	dfs(0, 0);

	printf("%d",maxCnt+1);

	return 0;

}