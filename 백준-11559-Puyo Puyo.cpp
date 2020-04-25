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

// 밑으로 내려갈 수 있으면, 내려가게끔
// 현재 위치 기준 아래만 보고 . 이면 내리는 DFS
int isBottomDot(int y, int x){
	// (하) 좌표
	int tempY = -1;
	for (int i = y; i < N; i++) {
		if (arr[i][x] == '.') {
			tempY = i;
		}
	}
	return tempY;
}

void bfs(int y, int x) {

	q.push({ y, x }); // 현 위치 푸쉬
	v.push_back({ y,x }); // 방문한 경로를 푸쉬

	while (!q.empty()) {

		int idxY = q.front().first;
		int idxX = q.front().second;
		visit[idxY][idxX] = 1;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ty = idxY + dy[i];
			int tx = idxX + dx[i];

			// 조건을 만족할 때에만 큐에 푸쉬한다.
			if (ty < N && ty >= 0 && tx < 6 && tx >= 0
				&& !visit[ty][tx] && arr[idxY][idxX] == arr[ty][tx]) {
				q.push({ ty, tx });
				v.push_back({ ty,tx }); // 방문할 경로를 푸쉬
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

	// 12* 6 입력받기 완료
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	while (1) {

		// 이 2중 포문을 다 돌면, 1차적으로 동시에 터질 수 있는 곳들이 visit에 1로 표시된다.
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 6; j++) {
				if(arr[i][j]!= '.' && visit[i][j] != 1)
					dfs(i, j);
				
				if (v.size() >= 4) // 최초 1회라도 true로 설정 가능
					FourCnt = true;

				if (v.size() < 4) {
					for (int i = 0; i < v.size(); i++) {
						visit[v[i].first][v[i].second] = 0;
					}
				}
				v.clear();
			}
		}
		// 동시다발 연쇄 1번을 추가한다.
		if (FourCnt == true)
			crash += 1;
		else if (FourCnt == false)
			break; // 다 검사했는데 터질 곳이 없으면 빠져나간다.

		// visit가 1로 표시된 곳을 모두 . 으로 만들어 준다.
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 6; j++) {
				if (visit[i][j] == 1) {
					arr[i][j] = '.';
				}
			}
		}
		// 밑에 . 이 있다면 . 이 없을 때까지 계속 위치를 밑으로 내린다.
		for (int i = N - 2; i >= 0; i--) {
			for (int j = 0; j < 6; j++) {
				tempY = -1;
				if (arr[i][j] != '.') {
					tempY = isBottomDot(i, j);
				}
				if (tempY != -1) {
					arr[tempY][j] = arr[i][j]; // 밑으로 옮기고,
					arr[i][j] = '.'; // 그 자리에 . 을 대입한다.
				}
			}
		}
		// 복귀
		FourCnt = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 6; j++) {
				visit[i][j] = 0;
			}
		}
	}

	cout << crash;
}