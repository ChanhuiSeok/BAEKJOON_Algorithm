#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first == b.first)
        return a.second < b.second;
    else
        return a.first < b.first;
}

int main() {
    vector <pair<int, int>> v;
    int n, a, b;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        v.push_back({ a,b });
    }

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < n; i++) {
        printf("%d %d\n", v[i].first, v[i].second);
    }

    return 0;
}