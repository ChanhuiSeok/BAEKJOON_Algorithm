#include <stdio.h>
#include <stdlib.h>

void push(int arr[], int input);
int pop(int arr[]);
int top = -1;

//main
int main() {

	int n;
	int data = 0;
	int input = 1;
	int cnt = 0;
	int max = 0;
	int tmp = 0;
	int j = 0;
	int *arr, *temp;
	char result[1000000];

	scanf("%d", &n);
	if (n < 1 || n>100000) {
		return 0;
	}

	temp = (int *)malloc(sizeof(int)*n); // 입력받은 임시
	arr = (int *)malloc(sizeof(int)*n); // 수열

	/* 스택을 0으로 초기화 */
	for (int i = 0; i < n; i++)
		arr[i] = 0;

	/* 임시로 입력받은 수열을 임시 배열에 저장 */
	for (int i = 0; i < n; i++) {
		scanf("%d", &data);
		temp[i] = data;
		if (max < temp[i])
			max = temp[i];
	}

	/* 임시 배열과 비교하면서 스택 push, pop 진행 */
	while (cnt <= (n - 1)) {
		// pop
		if (top != -1 && arr[top] == temp[cnt]) {
			tmp = pop(arr);
			result[j] = '-';
			cnt++;
			j++;
		}

		// push
		else if (top != -1 && arr[top] != temp[cnt]) {
			// 
			if (input > max) {
				printf("NO");
				return 0;
			}
			result[j] = '+';
			push(arr, input);
			input++;
			j++;
		}

		else if (top == -1 && arr[top] != temp[cnt]) {
			if (input > max) {
				printf("NO");
				return 0;
			}
			result[j] = '+';
			push(arr, input);
			input++;
			j++;
		}
	}

	// 정상적으로 나왔을 경우
	for (int k = 0; k < j; k++) {
		printf("%c\n", result[k]);
	}
}

void push(int arr[], int input) {
	arr[++top] = input;
}

int pop(int arr[]) {
	return arr[top--];
}

