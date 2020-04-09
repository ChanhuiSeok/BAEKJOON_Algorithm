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

	int N, K; //N�� �ܾ��� ����, K�� ������ ����
	int ess_K, count = 0;
	int max_count = -1;
	int j;
	int one_count = 0;
	string input;
	vector <string> v;
	vector <int> idx;
	vector <int> ind;

	scanf("%d %d", &N, &K);

	// ������ ��� �ܾ�� anta ~ tica �� �̷���� �����Ƿ�,
	// a,c,i,n,t �� 5���ڴ� �ݵ�� �л����� ������ �ϸ�,
	// �׷��� ������ ���ڸ� ���� �� �����Ƿ� ���� 0�̴�.

	alphabet['a' - 97] = 1;
	alphabet['c' - 97] = 1;
	alphabet['i' - 97] = 1;
	alphabet['n' - 97] = 1;
	alphabet['t' - 97] = 1;

	// K���� ���ڸ� ����ĥ ��, a,c,i,n,t �� 5���ڴ� �ʼ��� �־�� ��
	// a,c,i,n,t 5���ڸ� ����ġ�� �߰��� ����ĥ �� �ִ� ������ ����
	ess_K = K - 5;

	// ���� v���� �о�� �ϴ� �ܾ���� push �ȴ�.
	for (int i = 0; i < N; i++) {
		cin >> input;
		v.push_back(input);
	}

	if (K <= 4) {
		printf("%d", 0);
		return 0;
	}

	// �ܾ anta, tica �� �� ������ �ܾ�鿡�� ������ ���ڸ� �ľ��Ѵ�.
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
	

	// ������ �ܾ�鿡�� ������ ���ڵ��� ���� a,c,i,n,t�� �պ��� K�� ũ��
	// �� �ʿ䰡 ���� ��� �ܾ ���� �����ϴ�.
	if (5 + idx.size() < K) {
		printf("%d", v.size());
		return 0;
	}

	// idx���� a,c,i,n,t �� �� ������ ���ĺ����� �ε����� ��� �ִ�.
	// �� �ε������� �������� ����� ���� ���� alphabet �迭�� 1�� �ٲپ� �ش�.

	// (1) ind ���Ϳ� 1 �ֱ�
	for (int i = 0; i < ess_K; i++) {
		ind.push_back(1);
	}
	// (1)-1 ind ���Ϳ� 0 �ֱ�
	for (int i = 0; i < idx.size() - ess_K; i++) {
		ind.push_back(0);
	}

	sort(ind.begin(), ind.end());
	
	/*
	// ess_K����ŭ �߰��� a~z �߿��� �̾Ƽ� alphabet �迭�� 1�� �߰��Ѵ�.
	// ��, �̹� ������ a,c,i,n,t 5���ڴ� �׻� 1�� �Ǿ� �־�� �Ѵ�.

	// (1) ind ���Ϳ� 1 �ֱ�
	for (int i = 0; i < ess_K; i++) {
		ind.push_back(1);
	}
	// (1)-1 ind ���Ϳ� 0 �ֱ�
	for (int i = 0; i < 26 - ess_K; i++) {
		ind.push_back(0);
	}
	sort(ind.begin(), ind.end());
	*/


	do {
		// idx�� ��� �ִ� �ε������� �����Ͽ� ���ĺ��� ���ش�.
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
			// ������ �о�����
			if (j == v[i].size()) {
				count += 1;
			}
		}

		if (max_count < count) {
			max_count = count;
		}

		// ���� ���󺹱� 
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
		
		// alphabet �迭�� 1�� ǥ��� ������ K�� �ƴ϶�� ��õ�
		for (int i = 0; i < 26; i++) {
			if (alphabet[i] == 1)
				one_count += 1;
		}

		if (one_count == K) {
			// �־��� N�� �ܾ ��������, alphabet �迭�� 1�� ǥ��� ���ڵ��� �о��
			for (int i = 0; i < v.size(); i++) {

				for (j = 0; j < v[i].size(); j++) {
					if (alphabet[v[i][j] - 97] == 0)
						break;
				}
				// ������ �о�����
				if (j == v[i].size()) {
					count += 1;
				}
			}

			if (max_count < count) {
				max_count = count;
			}

		}

		// ���� ���󺹱� 
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