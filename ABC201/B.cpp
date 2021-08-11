/**
 *    author:  ytsmash
 *    created: 11.08.2021 22:21:42
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

int main() {
    int N;
    cin >> N;
    vector<pair<int, string>> data(N);
    rep(i, N) { cin >> data[i].second >> data[i].first; }
    sort(all(data)); // 要素がpairの時のvectorのソートは「一つ目をソート」→「一つ目が同順の場合はさらに二つ目をソート」という挙動になる
    cout << data[N - 2].second << "\n";
}