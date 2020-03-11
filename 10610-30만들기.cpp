#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int compare(int a, int b) {
	return a > b;
}

int arr[100001];

int main() {

	int n, idx = 0;
	int sum = 0;
	int flag = 0;
	char input[100001];

	vector<int> ans;

	scanf("%s", &input);	
	
	// ���Ϳ� �ڸ��� ���
	while (1) {
		if (input[idx] == '\0')
			break;
		else
		{
			ans.push_back(input[idx++]-48);
		}
	}
	
	// [����ó��]
	// �ڸ����� ���� 3�� ����� �ƴϸ� -1
	for (int i = 0; i < ans.size(); i++) {
		sum += ans[i];
	}
	if (sum % 3 != 0) {
		printf("-1");
		return 0;
	}

	// 0�� ���ԵǾ� ���� ������ -1
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i] == 0) {
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		printf("-1");
		return 0;
	}

	// �������� ����
	stable_sort(ans.begin(), ans.end(), compare);

	for (int i = 0; i < ans.size(); i++) {
		printf("%d", ans[i]);
	}


	return 0;
}