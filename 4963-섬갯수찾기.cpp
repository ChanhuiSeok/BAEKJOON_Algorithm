#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>

int map[50][50];
int visit[50][50];
int w, h;
int landCnt = 0;

//stack <pair<int, int> > path;

// 상,하,좌,우,좌상,우상,좌하,우하
int dx[8] = { 0,0,-1,1,-1,1,-1,1 };
int dy[8] = { -1,1,0,0,-1,-1,1,1 };

using namespace std;

void find(int y, int x) {
	int tx, ty;
	for (int i = 0; i < 8; i++) {
		tx = x + dx[i];
		ty = y + dy[i];

		// 벽이 아니거나, 해당 길이 방문하지 않았을 경우이며
		// 해당 길이 1일 경우 방문
		if (tx >= 0 && tx < w && ty < h && ty >= 0
			&& map[ty][tx] == 1 && visit[ty][tx] != 1) {

			visit[ty][tx] = 1;

			find(ty, tx);
		}
	}
}

int main() {

	int input;
	int px, py;
	int tx, ty;

	while (1) {
		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0)
			break;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf("%d", &input);
				map[i][j] = input;
			}
		}

		// px 방향이 열 증가/감소 방향, py 방향이 행 증가/감소 방향
		// 찾기
		// 0,0에서 시작
		
		for (int py = 0; py < h; py++) {
			for (int px = 0; px < w; px++) {
				if (map[py][px] == 0 || visit[py][px] == 1)
					continue;
				visit[py][px] = 1;
				find(py, px);
				landCnt++;
			}
		}

		printf("%d\n", landCnt);
		
		// 초기화 작업
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				map[i][j] = 0;
				visit[i][j] = 0;
			}
		}
		landCnt = 0;
	}
	return 0;
}