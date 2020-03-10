#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;
int arr[1000001];
int cnt[1000001];
int NGF[1000001];

int main() {

	int N;
	int nCnt;
	scanf("%d", &N);

	stack <int> st;

	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = N; i >= 1; i--) {

		while (!st.empty() && arr[i] >= st.top()) {
			st.pop();
		}

		if (st.empty()) {
			NGF[i] = -1;
		}

		else {
			NGF[i] = st.top();
		}

		st.push(arr[i]);
	}


	for (int i = 1; i <= N; i++) {
		printf("%d ", NGF[i]);
	}

}