#include <stdio.h>
#include <stdlib.h>

int main() {

	int N;
	int cnt_3 = 0;
	int cnt_5 = 0;

	scanf("%d", &N);

	// 5kg로 최대한 할 수 있다면 전체 봉지수를 줄일 수 있다.
	// 먼저 처음엔 3kg로부터 빼고, 5kg로 나누어 떨어지면 
	// 그 즉시 5kg 봉지로 세면 된다.
	// 하지만 입력받은 N이 처음부터 5로 나누어 떨어지면,
	// 바로 5kg 봉지로만 세면 끝난다.

	while (N % 5 != 0) {
		N = N - 3;
		cnt_3++;

		if (N < 3 && N != 0) {
			printf("-1");
			return 0;
		}
	}
	cnt_5 = N / 5;

	printf("%d",cnt_5 + cnt_3);

	return 0;
}