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

	// v ���Ϳ��� �� ������ ��ƿ �� �ִ� MAX �߷��� ���� ����.
	// ������ ������ N ����.
	// ���� ���� ���� ������ ������.
	stable_sort(v.begin(), v.end());
	
	//w = v[0]; // �ּ� �߷���, ���� ���� ������ ��Ƽ�� �߷���.
	
	for (int k = 1; k <= N; k++) {

		W = k * v[N - k];
		if (W >= maxW)
			maxW = W;

	}

	printf("%d", maxW);

	return 0;
}