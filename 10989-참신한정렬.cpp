#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int compare(int a, int b) {
    return a < b;
}

int main()
{
    int N;
    int input;
    int count[10001];
    scanf("%d", &N);

    for (int i = 1; i <= 10000; i++) {
        count[i] = 0;
    }

    for (int i = 1; i <= N; i++) {
        scanf("%d", &input);
        count[input]++;
    }

    for (int i = 1; i <= 10000; i++) {     
        while (count[i] != 0) {
            printf("%d", i);
            count[i]--;
            printf("\n");
        }
    }

}
