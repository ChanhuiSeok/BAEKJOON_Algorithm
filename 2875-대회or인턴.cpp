#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
int arr[100001];

int make(int women, int men) {
	int team = 0;

	while (1) {	
		if (women - 2 >= 0 && men - 1 >= 0) {
			women -= 2; men -= 1;
			team++;
		}
		else
			break;
	}
	return team;
}

int main() {

	int N, M, K;
	int tempN, tempM;
	int maxTeam =-1;
	int subW = 0, subM = 0;
	int team;
	scanf("%d %d %d", &N, &M, &K);

	// (3) 하나씩 서로 줄여가면서 모두 비교
	tempN = N; tempM = M;
	subW = 0; subM = K;
	for (int i = 0; i <= K; i++) {
		tempN = N - subW;
		tempM = M - subM;

		team = make(tempN, tempM);
		if (maxTeam <= team)
			maxTeam = team;

		subW += 1;
		subM -= 1;
	}

	printf("%d", maxTeam);

	return 0;
}