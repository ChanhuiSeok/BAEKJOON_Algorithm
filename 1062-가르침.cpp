#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int alphabet[26];
int exist[26];

int main() {

	int N, K; //N은 단어의 개수, K는 글자의 개수
	int ess_K, count = 0;
	int max_count = -1;
	int j;
	int one_count = 0;
	string input;
	vector <string> v;
	vector <int> idx;
	vector <int> ind;

	scanf("%d %d", &N, &K);

	// 남극의 모든 단어는 anta ~ tica 로 이루어져 있으므로,
	// a,c,i,n,t 이 5글자는 반드시 학생들이 익혀야 하며,
	// 그렇지 않으면 글자를 읽을 수 없으므로 답은 0이다.

	alphabet['a' - 97] = 1;
	alphabet['c' - 97] = 1;
	alphabet['i' - 97] = 1;
	alphabet['n' - 97] = 1;
	alphabet['t' - 97] = 1;

	// K개의 글자를 가르칠 때, a,c,i,n,t 이 5글자는 필수로 있어야 함
	// a,c,i,n,t 5글자를 가르치고 추가로 가르칠 수 있는 글자의 갯수
	ess_K = K - 5;

	// 벡터 v에는 읽어야 하는 단어들이 push 된다.
	for (int i = 0; i < N; i++) {
		cin >> input;
		v.push_back(input);
	}

	if (K <= 4) {
		printf("%d", 0);
		return 0;
	}

	// 단어에 anta, tica 를 뺀 나머지 단어들에서 출현한 글자를 파악한다.
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			
			if (v[i][j] != 'a' && v[i][j] != 'c' && v[i][j] != 'i'
				&& v[i][j] != 'n' && v[i][j] != 't' && exist[v[i][j]-97] != 1) {
				exist[v[i][j] - 97] = 1;
				idx.push_back(v[i][j] - 97);
			}
		}
	}
	sort(idx.begin(), idx.end());
	

	// 나머지 단어들에서 출현한 글자들의 수와 a,c,i,n,t의 합보다 K가 크면
	// 볼 필요가 없이 모든 단어를 색출 가능하다.
	if (5 + idx.size() < K) {
		printf("%d", v.size());
		return 0;
	}

	// idx에는 a,c,i,n,t 를 뺀 나머지 알파벳들의 인덱스가 들어 있다.
	// 이 인덱스들을 조합으로 경우의 수를 구해 alphabet 배열에 1로 바꾸어 준다.

	// (1) ind 벡터에 1 넣기
	for (int i = 0; i < ess_K; i++) {
		ind.push_back(1);
	}
	// (1)-1 ind 벡터에 0 넣기
	for (int i = 0; i < idx.size() - ess_K; i++) {
		ind.push_back(0);
	}

	sort(ind.begin(), ind.end());
	
	/*
	// ess_K개만큼 추가로 a~z 중에서 뽑아서 alphabet 배열에 1로 추가한다.
	// 단, 이미 정해진 a,c,i,n,t 5글자는 항상 1로 되어 있어야 한다.

	// (1) ind 벡터에 1 넣기
	for (int i = 0; i < ess_K; i++) {
		ind.push_back(1);
	}
	// (1)-1 ind 벡터에 0 넣기
	for (int i = 0; i < 26 - ess_K; i++) {
		ind.push_back(0);
	}
	sort(ind.begin(), ind.end());
	*/


	do {
		// idx에 들어 있는 인덱스들을 조합하여 알파벳에 켜준다.
		for (int i = 0; i < idx.size(); i++) {
			if (ind[i] == 1) {
				alphabet[idx[i]] = 1;
			}
		}

		for (int i = 0; i < v.size(); i++) {
			for (j = 0; j < v[i].size(); j++) {
				if (alphabet[v[i][j] - 97] == 0)
					break;
			}
			// 끝까지 읽었으면
			if (j == v[i].size()) {
				count += 1;
			}
		}

		if (max_count < count) {
			max_count = count;
		}

		// 조합 원상복귀 
		for (int i = 0; i < ind.size(); i++) {
			if (ind[i] == 1) {
				alphabet[idx[i]] = 0;
			}
		}

		count = 0;
	} while (next_permutation(ind.begin(), ind.end()));


	/*
	do {
		for (int i = 0; i < ind.size(); i++) {
			if (ind[i] == 1) {
				alphabet[i] = 1;
			}
		}
		
		// alphabet 배열에 1로 표기된 값들이 K개 아니라면 재시도
		for (int i = 0; i < 26; i++) {
			if (alphabet[i] == 1)
				one_count += 1;
		}

		if (one_count == K) {
			// 주어진 N개 단어를 기준으로, alphabet 배열에 1로 표기된 글자들을 읽어보기
			for (int i = 0; i < v.size(); i++) {

				for (j = 0; j < v[i].size(); j++) {
					if (alphabet[v[i][j] - 97] == 0)
						break;
				}
				// 끝까지 읽었으면
				if (j == v[i].size()) {
					count += 1;
				}
			}

			if (max_count < count) {
				max_count = count;
			}

		}

		// 조합 원상복귀 
		for (int i = 0; i < ind.size(); i++) {
			if (ind[i] == 1 && i != 'a' - 97 && i != 'c' - 97 && i != 'i' - 97
				&& i != 'n' - 97 && i != 't' - 97) {
				alphabet[i] = 0;
			}
		}
		count = 0;
		one_count = 0;
	
	} while (next_permutation(ind.begin(),ind.end()));
	*/

	printf("%d", max_count);

}