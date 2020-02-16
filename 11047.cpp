#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>

int main() {

	int N, K;
	int* val;
	int count = 0;
	int idx = 0;
	int result = 0;

	scanf("%d %d", &N, &K);
	val = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &val[i]);
	}

	idx = N - 1;
	while (1) {
		if (result + val[idx] <= K) {
			result = result + val[idx]; // 결과에 더하기
			count++; // 동전 사용 횟수 증가
		}
		else {
			idx--;
		}

		if (result == K)
			break;
	}

	printf("%d", count);

}