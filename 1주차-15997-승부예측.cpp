#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>


using namespace std;
vector <pair<string, double>> v;
vector <double> result(4); // ���߿� ���� Ȯ�� ��°�

string t1, t2, t3, t4;
int reName(string str) {
    if (str == t1) {
        return 0;
    }
    else if (str == t2) {
        return 1;
    }
    else if (str == t3) {
        return 2;
    }
    else if (str == t4) {
        return 3;
    }
}

int n;
double percentage = 1;

typedef struct cases {
    string A;
    string B;
    double W;
    double D;
    double L;
}Case;

Case cases[6];

bool compare(const pair<string,double> &a, const pair<string, double>& b) {
    return a.second > b.second;
}

void dfs(int n) {

    if (percentage == 0)
        return;

    if (n == 6) {
        vector <pair<string, double>> rank; // �� ���̽��� ��ũ�� ����
        for (int i = 0; i < 4; i++) {
            rank.push_back({ v[i].first, v[i].second });
        }
        sort(rank.begin(), rank.end(), compare);

        // ��� ���� ������ ���� ��
        if (rank[0].second == rank[1].second && rank[1].second == rank[2].second &&
            rank[2].second == rank[3].second) {
            result[reName(rank[0].first)] += 0.5 * percentage;
            result[reName(rank[1].first)] += 0.5 * percentage;
            result[reName(rank[2].first)] += 0.5 * percentage;
            result[reName(rank[3].first)] += 0.5 * percentage;
        }

        // ���� 1���� ��Ȯ�ϰ�, �߰� 2, 3���� ����� ����, 4� ��Ȯ�� ��
        else if (rank[0].second > rank[1].second &&
            rank[1].second == rank[2].second && rank[2].second > rank[3].second) {
            result[reName(rank[0].first)] += percentage;
            result[reName(rank[1].first)] += 0.5 * percentage;
            result[reName(rank[2].first)] += 0.5 * percentage;
        }

        // ���� 1���� ��Ȯ�ϰ�, 2,3,4 ���� ������ ���� ��
        else if (rank[0].second > rank[1].second &&
            rank[1].second == rank[2].second && rank[2].second == rank[3].second) {
            result[reName(rank[0].first)] += percentage;
            result[reName(rank[1].first)] += percentage * 1.0 / 3.0;
            result[reName(rank[2].first)] += percentage * 1.0 / 3.0;
            result[reName(rank[3].first)] += percentage * 1.0 / 3.0;
        }

        // ���� 1,2,3 ���� ������ ����, 4���� ��Ȯ�� ��
        else if (rank[0].second == rank[1].second && rank[1].second == rank[2].second
            && rank[2].second > rank[3].second) {
            result[reName(rank[0].first)] += percentage * 2.0 / 3.0;
            result[reName(rank[1].first)] += percentage * 2.0 / 3.0;
            result[reName(rank[2].first)] += percentage * 2.0 / 3.0;
        }

        // ���� 1, 2���� ��Ȯ�ϰ� ���е� ��
        else if (rank[0].second > rank[1].second && rank[1].second > rank[2].second
            || (rank[0].second == rank[1].second && rank[1].second > rank[2].second)) {
            result[reName(rank[0].first)] += percentage;
            result[reName(rank[1].first)] += percentage;
        }

        return;
    }


    for (int i = 0; i < 4; i++) {
        if (cases[n].A == v[i].first) { // cases n��° ���� A�� �ݺ��� i������ ����� ���� ��           
            for (int j = 0; j < 4; j++) {
                if (cases[n].B == v[j].first) { // cases n��° ���� B�� �ݺ��� j������ ����� ���� ��
                 
                    for (int c = 0; c < 3; c++) {
                        double tempPercent = percentage;

                        // case 0. A�� �̱� ��
                        if (c == 0) {
                            v[i].second += 3;
                            percentage = percentage * cases[n].W;
                            dfs(n + 1);
                            v[i].second -= 3;
                        }

                        // case 1. A�� B�� ��� ��
                        else if (c == 1) {
                            v[i].second += 1;
                            v[j].second += 1;
                            percentage = percentage * cases[n].D;
                            dfs(n + 1);
                            v[i].second -= 1;
                            v[j].second -= 1;
                        }

                        // case 2. A�� �� �� (��, B�� �̱� ��)
                        else if (c == 2) {
                            v[j].second += 3;
                            percentage = percentage * cases[n].L;
                            dfs(n + 1);
                            v[j].second -= 3;
                        }

                        percentage = tempPercent;
                    }

                }
            }
        }
    }
    
    
}

int main()
{
    string team;
    for (int i = 0; i < 4; i++)
    {
        cin >> team;
        v.push_back({ team, 0 });
    }
    
    t1 = v[0].first;
    t2 = v[1].first;
    t3 = v[2].first;
    t4 = v[3].first;

    // �Ʒ� 6�ٿ� ���Ͽ� ��� ����� ���� �ľ��Ѵ�.
    // ��, �� �ٴ� �̰��� �� , ����� ��, ���� ���� 3���� ��찡 ������,
    // 3*3*3*3*3*3 = 3^6 ������ ����� ���� ��� ���ٴ� �ǹ̰� �ȴ�!!
    // KOREA CCC 0.3 0.4 0.3
    // AAA BBB 0.428 0.144 0.428
    // AAA KOREA 0.0 0.0 1.0
    // CCC BBB 0.0 0.0 1.0
    // KOREA BBB 1.0 0.0 0.0
    // CCC AAA 0.0 0.0 1.0
    // �̾��ٸ�,
    // (1��° ��) KOREA�� CCC�� �̰��� �� (Ȯ�� 0.3)
    // (2) AAA�� �̰��� �� -> (3) AAA�� �̰��� �� -> (4) CCC�� �̰��� �� -> (5) KOREA�� �̰��� ��
    // -> (6) CCC�� �̰��� �� -> (5) Korea�� �̰��� ���� ��Ʈ��ŷ -> (6) CCC�� AAA�� ����� ��
    // -> (5) Korea�� �̰��� ���� ��Ʈ��ŷ -> (6) CCC�� AAA���� ���� ��
    // -> (5) Korea�� BBB�� ����� �� -> (6) CCC�� �̰��� �� -> .... �ݺ� �ϸ� 3^6 ���� ����� ����
    // ��� �� �� �ִ�. �� ��, Ȯ�� ���� ������ �θ鼭 dfs�� �Ǵ��� �ش�.
    // 6���� ��� �� ������ ��, ������ �Ű��� ���̰�, �̸� ���� ��ũ�� ����� �ش�.
    // ��ũ �������� Ȯ�� ���� ������ �θ鼭 ���� result�� ������ �ش�.


    for (int i = 0; i < 6; i++) {
        string A, B;
        double W, D, L;

        cin >> A >> B >> W >> D >> L;
        cases[i].A = A; cases[i].B = B; cases[i].W = W;
        cases[i].D = D; cases[i].L = L;
    }

    dfs(0);


    for (int i = 0; i < 4; i++) {
        printf("%.6lf\n", result[i]);
    }
    

}