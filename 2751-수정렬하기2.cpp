#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    int n, input;
    scanf("%d", &n);
    vector <int> v;

    for (int i = 0; i < n; i++) {
        scanf("%d", &input);
        v.push_back(input);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        printf("%d\n", v[i]);
    }

    return 0;
}