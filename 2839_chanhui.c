#include <stdio.h>
#include <stdlib.h>

int main() {

	int N;
	int cnt_3 = 0;
	int cnt_5 = 0;

	scanf("%d", &N);

	// 5kg�� �ִ��� �� �� �ִٸ� ��ü �������� ���� �� �ִ�.
	// ���� ó���� 3kg�κ��� ����, 5kg�� ������ �������� 
	// �� ��� 5kg ������ ���� �ȴ�.
	// ������ �Է¹��� N�� ó������ 5�� ������ ��������,
	// �ٷ� 5kg �����θ� ���� ������.

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