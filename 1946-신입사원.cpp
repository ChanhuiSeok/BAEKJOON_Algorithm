#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

int map[50][50];
int visit[50][50];

// ��,��,��,��,�»�,���,����,����
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

		// px ������ �� ����/���� ����, py ������ �� ����/���� ����
		// ã��
		px = 0, py = 0; // 0,0���� ����
		while (1) {		
			// 1. ���� ��ġ�� �湮�ߴٰ� ǥ��
			visit[px][py] = 1;

			for (int i = 0; i < 8; i++) {
				px = px + dx[i];
				py = py + dy[i];
			}



		}


	}
	return 0;
}