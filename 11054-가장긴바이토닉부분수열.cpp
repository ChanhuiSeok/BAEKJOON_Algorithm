#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
int dp[1001];
int dp2[1001];

int main() {

	int N, input;
	int sum = 0;
	int maxV = -1;
	int pointIdx = 0;
	scanf("%d", &N);

	vector<int> v;

	for (int i = 0; i < N; i++) {
		scanf("%d", &input);
		v.push_back(input);
		dp[i] = 1;
		dp2[i] = 1;
	}
	/* ���ʿ��� �ѹ�, �����ʿ��� �� ���� ������ �� �迭�� ���� ó���� ���� �� ��*/

	// ���ʿ��� ���������� �ö� �� (�����ϴ� ��)
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {

			if (v[j] < v[i] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
	}

	// �����ʿ��� �������� ������ �� (�����ϴ� ��)
	for (int i = N-1; i >= 0; i--) {
		for (int j = N-1; j > i; j--) {

			if (v[j] < v[i] && dp2[i] < dp2[j] + 1) {
				dp2[i] = dp2[j] + 1;
			}
		}
	}

	// �� �迭�� ��
	for (int i = 0; i < N; i++) {
		int result = dp[i] + dp2[i];
		if (result > maxV)
			maxV = result;
	}
	
	printf("%d", maxV - 1);

}