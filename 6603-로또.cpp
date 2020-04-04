#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
vector <int> v;
vector <int> result;
int n;

void backtracking(int idx, int count) {

    // 길이가 6이 되었을 경우
    if (count == 6) {
        for (int i = 0; i < 6; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
        return;
    }

    for (int i = idx; i < n; i++) {

        result.push_back(v[i]);
        backtracking(i + 1, count + 1);
        result.pop_back();
    }

}

int main()
{
    int input;
    while (1)
    {
        result.clear();
        v.clear();
        scanf("%d", &n);

        if (n == 0)
            break;

        for (int i = 0; i < n; i++) {
            scanf("%d", &input);
            v.push_back(input);
        }

        backtracking(0, 0);
        
        printf("\n");
    }


    return 0;
}