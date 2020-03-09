#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000001
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int compare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second)
		return a.first < b.first;

	return a.second < b.second;
}

int main() {

	int N, start, end;
	int count = 0, max = 0;
	int end_time = 0;
	int start_time = 0;

	scanf("%d", &N);

	vector <pair<int, int>> v;
	vector <pair<int, int>>::iterator it;
	vector <pair<int, int>>::iterator it2;

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &start, &end);
		v.push_back(make_pair(start, end));
	}

	// sorting
	stable_sort(v.begin(), v.end(), compare);

	end_time = v[0].second;
	for (it = v.begin() + 1; it != v.end() ; it++) {
		if (it->first >= end_time) {
			count++;
			end_time = it->second;
		}	
	}

	printf("%d", count+1);

}