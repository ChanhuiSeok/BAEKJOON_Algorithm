#include <stdio.h>
#include <stdlib.h>

int main() {

	int C;
	int size, input, sum;
	int count = 0;
	int * arr;
	double ave;
	double * RATIO_ARR;
	double ratio;

	scanf("%d", &C);
	RATIO_ARR = (double *)malloc(sizeof(double)*C);

	for (int i = 0; i < C; i++) {
		sum = 0;
		ratio = 0;
		count = 0;

		scanf("%d", &size);
		arr = (int *)malloc(sizeof(int)*size);

		for (int j = 0; j < size; j++) {
			scanf("%d", &input);
			arr[j] = input;
			sum += arr[j];
		}

		ave = (double)sum / (double)size; // ��� ����

		for (int k = 0; k < size; k++) {
			if (ave < arr[k]) // ��պ��� ũ��, ī��Ʈ 1 ����
				count++;
		}

		ratio = (double)count / (double)size;
		RATIO_ARR[i] = ratio; // ���� ����
	}

	for (int i = 0; i < C; i++) {
		printf("%.3f%%\n", RATIO_ARR[i] * 100);
	}

	return 0;
}