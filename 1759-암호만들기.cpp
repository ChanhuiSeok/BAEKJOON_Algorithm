#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
vector <int> v;
vector <int> result;
int n;

bool compare(int a, int b) {
   return a > b;
}

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
    int L, C;
    int c_cnt=0, v_cnt=0;

    vector <string> result;

    string input;
    scanf("%d %d", &L, &C);

    vector <string> v;
    for (int i = 0; i < C; i++) {
        cin >> input;
        v.push_back(input);
    }

    vector <int> ind;
    for (int i = 0; i < L; i++) {
        ind.push_back(1);
    }
    for (int i = 0; i < v.size() - L; i++) {
        ind.push_back(0);
    }

    //next_permutation 함수는 반드시 정렬 후 사용해야 한다.
    sort(ind.begin(), ind.end(),compare);
    sort(v.begin(), v.end());

    do {
        
        for (int i = 0; i < ind.size(); i++) {
            if (ind[i] == 1) {
                result.push_back(v[i]);
                if (v[i] == "a" || v[i] == "e" || v[i] == "i"
                    || v[i] == "o" || v[i] == "u") {
                    v_cnt++;
                }
                else {
                    c_cnt++;
                }
            }
        }

        if (v_cnt >= 1 && c_cnt >= 2) {
            for (int i = 0; i < result.size(); i++) {
                cout << result[i];
            }
            printf("\n");
        }

        result.clear();
        v_cnt = 0; c_cnt = 0;

    } while (prev_permutation(ind.begin(), ind.end()));

}