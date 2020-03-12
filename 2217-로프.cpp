#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N, input;
	//int w;
	int W;
	int maxW = -1;
	vector <int> v;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &input);
		v.push_back(input);
	}

	// v 벡터에는 각 로프가 버틸 수 있는 MAX 중량이 적혀 있음.
	// 로프의 갯수는 N 개임.
	// 가장 약한 로프 순으로 정렬함.
	stable_sort(v.begin(), v.end());
	
	//w = v[0]; // 최소 중량은, 가장 약한 로프가 버티는 중량임.
	
	for (int k = 1; k <= N; k++) {

		W = k * v[N - k];
		if (W >= maxW)
			maxW = W;

	}

	printf("%d", maxW);

	return 0;
}