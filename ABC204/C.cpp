/**
 *    author:  ytsmash
 *    created: 12.08.2021 20:24:20
 **/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) x.begin(), x.end()
const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
using P = pair<int, int>;

vector<vector<int>> to;  // to[i]は都市A[i]から行くことのできる都市の一覧

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(N);
    rep(i, M) { cin >> A[i] >> B[i]; }

    to.resize(M);
    rep(i, M) {
        A[i]--;
        B[i]--;
        to[A[i]].push_back(B[i]);  // A[i]からはB[i]に行ける
    }
    rep(i, M) {
        sort(all(to[i]));  // 都市A[i]から行くことのできる都市を昇順に並べる
    }
    return 0;
}