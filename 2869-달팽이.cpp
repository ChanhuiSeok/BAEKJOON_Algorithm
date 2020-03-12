#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {

	int A, B, V;
	int temp1, temp2;
	int daySub;
	int dayM = 0;
	int day = 0;
	int temp = 0;
	int tempV = 0;
	scanf("%d %d %d", &A, &B, &V);

	//[1] 낮에 올라갈 수 있는 높이가 나무 높이보다 크거나 같을 경우

	day = (V - B) / (A - B);
	tempV = (V - B) % (A - B);

	if (tempV != 0)
		day = day + 1;

	printf("%d", day);

	return 0;
}