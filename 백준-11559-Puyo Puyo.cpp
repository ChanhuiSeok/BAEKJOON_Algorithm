#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
queue <pair<int, int>> q;
vector <pair<int, int>> v;

int N;
string arr[12];
int visit[12][6];
int cnt;
bool FourCnt = false;
int maxCnt = -1;

// ������ ������ �� ������, �������Բ�
// ���� ��ġ ���� �Ʒ��� ���� . �̸� ������ DFS
int isBottomDot(int y, int x){
	// (��) ��ǥ
	int tempY = -1;
	for (int i = y; i < N; i++) {
		if (arr[i][x] == '.') {
			tempY = i;
		}
	}
	return tempY;
}

void bfs(int y, int x) {

	q.push({ y, x }); // �� ��ġ Ǫ��
	v.push_back({ y,x }); // �湮�� ��θ� Ǫ��

	while (!q.empty()) {

		int idxY = q.front().first;
		int idxX = q.front().second;
		visit[idxY][idxX] = 1;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ty = idxY + dy[i];
			int tx = idxX + dx[i];

			// ������ ������ ������ ť�� Ǫ���Ѵ�.
			if (ty < N && ty >= 0 && tx < 6 && tx >= 0
				&& !visit[ty][tx] && arr[idxY][idxX] == arr[ty][tx]) {
				q.push({ ty, tx });
				v.push_back({ ty,tx }); // �湮�� ��θ� Ǫ��
				visit[ty][tx] = 1;
			}
		}
	}
}

int main() {
	
	int crash = 0;
	int tempY = -1;
	N = 12;

	cin.tie(NULL);
	cout.tie(NULL);

	// 12* 6 �Է¹ޱ� �Ϸ�
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	while (1) {

		// �� 2�� ������ �� ����, 1�������� ���ÿ� ���� �� �ִ� ������ visit�� 1�� ǥ�õȴ�.
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 6; j++) {
				if(arr[i][j]!= '.' && visit[i][j] != 1)
					dfs(i, j);
				
				if (v.size() >= 4) // ���� 1ȸ�� true�� ���� ����
					FourCnt = true;

				if (v.size() < 4) {
					for (int i = 0; i < v.size(); i++) {
						visit[v[i].first][v[i].second] = 0;
					}
				}
				v.clear();
			}
		}
		// ���ôٹ� ���� 1���� �߰��Ѵ�.
		if (FourCnt == true)
			crash += 1;
		else if (FourCnt == false)
			break; // �� �˻��ߴµ� ���� ���� ������ ����������.

		// visit�� 1�� ǥ�õ� ���� ��� . ���� ����� �ش�.
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 6; j++) {
				if (visit[i][j] == 1) {
					arr[i][j] = '.';
				}
			}
		}
		// �ؿ� . �� �ִٸ� . �� ���� ������ ��� ��ġ�� ������ ������.
		for (int i = N - 2; i >= 0; i--) {
			for (int j = 0; j < 6; j++) {
				tempY = -1;
				if (arr[i][j] != '.') {
					tempY = isBottomDot(i, j);
				}
				if (tempY != -1) {
					arr[tempY][j] = arr[i][j]; // ������ �ű��,
					arr[i][j] = '.'; // �� �ڸ��� . �� �����Ѵ�.
				}
			}
		}
		// ����
		FourCnt = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 6; j++) {
				visit[i][j] = 0;
			}
		}
	}

	cout << crash;
}