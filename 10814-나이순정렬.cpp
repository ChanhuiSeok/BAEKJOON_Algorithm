#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

bool compare(const tuple<int, string, int>& a, const tuple<int, string, int>& b) {
	if (get<0>(a) == get<0>(b)) {
		return get<2>(a) < get<2>(b);
	}
	else {
		return get<0>(a) < get<0>(b);
	}
}

int main() {

	int N, age;
	string name;
	vector <tuple<int, string, int>> v;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		cin >> age >> name;
		v.push_back({ age,name,i });
	}

	stable_sort(v.begin(), v.end(), compare);

	for (int i = 0; i < N; i++) {
		cout << get<0>(v[i]) << " " << get<1>(v[i]) << '\n';
		// endl; 을 '\n'으로만 바꿨을 뿐인데 시간초과 되지 않고 통과했다.
	}

}