#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int arr[4003][4003]; // 0으로 초기화 됨

int main() {

	int N;
	int str1Len, str2Len;
	char str1[4003];
	char str2[4003];
	int result;
	int max = 0;

	scanf("%s", &str1);
	scanf("%s", &str2);
	str1Len = strlen(str1);
	str2Len = strlen(str2);

	//첫행과 첫열은 0인 상태.	
	for (int j = 0; j < str2Len; j++) {
		for (int i = 0; i < str1Len; i++) {
			// 문자열이 같을 경우
			if (str1[i] == str2[j]) {
				arr[j+1][i+1] = arr[j][i] + 1;

				if (max <= arr[j+1][i+1])
					max = arr[j+1][i+1];
			}
		}
	}

	printf("%d", max);

}