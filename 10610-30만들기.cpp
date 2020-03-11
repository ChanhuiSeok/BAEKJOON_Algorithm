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
	
	// 벡터에 자릿수 담기
	while (1) {
		if (input[idx] == '\0')
			break;
		else
		{
			ans.push_back(input[idx++]-48);
		}
	}
	
	// [예외처리]
	// 자릿수의 합이 3의 배수가 아니면 -1
	for (int i = 0; i < ans.size(); i++) {
		sum += ans[i];
	}
	if (sum % 3 != 0) {
		printf("-1");
		return 0;
	}

	// 0이 포함되어 있지 않으면 -1
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

	// 내림차순 정렬
	stable_sort(ans.begin(), ans.end(), compare);

	for (int i = 0; i < ans.size(); i++) {
		printf("%d", ans[i]);
	}


	return 0;
}