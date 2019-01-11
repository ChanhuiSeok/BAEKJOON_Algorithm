#include <stdio.h>

// baekjoon_#1924
// Chanhui Seok (chanhuicom@gmail.com)

int main() {

	// 0...sunday, 1...monday, 2...tuesday

	int x, y;
	int day, date;
	char DAY_CHAR;

	int weight[12][2]; // 가중치 및 월별 일(31,28,30 중) 저장 위한 배열 선언
	weight[0][0] = 0; // 2007년 1월 1일은 월요일임이 주어졌음 - 가중치 0

	// 월별 저장
	for (int i = 0; i < 12; i++) {
		if ((i + 1) == 1 || (i + 1) == 3 || (i + 1) == 5 || (i + 1) == 7 || (i + 1) == 8 || (i + 1) == 10 || (i + 1) == 12)
			weight[i][1] = 31;
		else if ((i + 1) == 2)
			weight[i][1] = 28;
		else
			weight[i][1] = 30;
	}

	// 월별 가중치값 저장
	for (int i = 0; i < 11; i++) {
		weight[i + 1][0] = (weight[i][1] % 7 + weight[i][0]) % 7;
	}

	scanf("%d %d", &x, &y);

	// 요일 계산
	day = (weight[x-1][0] + (y % 7)) % 7;
	
	if (day == 0)
		printf("SUN");
	else if (day == 1)
		printf("MON");
	else if (day == 2)
		printf("TUE");
	else if (day == 3)
		printf("WED");
	else if (day == 4)
		printf("THU");
	else if (day == 5)
		printf("FRI");
	else if (day == 6)
		printf("SAT");

	return 0;
}