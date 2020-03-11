#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

int map[50][50];
int visit[50][50];

// 상,하,좌,우,좌상,우상,좌하,우하
int dx = { 0,0,-1,1,-1,1,-1,1};
int dy = { -1,1,0,0,-1,-1,1,1};

using namespace std;

int main() {

	int w, h;
	int input;
	int px, py;

	while (1) {
		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0)
			break;

		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				scanf("%d", &input);
				map[i][j] = input;
			}
		}

		// px 방향이 열 증가/감소 방향, py 방향이 행 증가/감소 방향
		// 찾기
		px = 0, py = 0; // 0,0에서 시작
		while (1) {		
			// 1. 현재 위치를 방문했다고 표시
			visit[px][py] = 1;

			for (int i = 0; i < 8; i++) {
				px = px + dx[i];
				py = py + dy[i];
			}



		}


	}
	return 0;
}