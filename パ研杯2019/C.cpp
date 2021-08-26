/**
 *    author:  ytsmash
 *    created: 26.08.2021 13:23:16
 **/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) x.begin(), x.end()
template <class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
using P = pair<int, int>;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M));
    rep(i, N) {
        rep(j, M) { cin >> A[i][j]; }
    }
    ll ans = -1;
    for (int i = 0; i < M - 1; i++) {
        for (int j = i + 1; j < M; j++) {
            ll sum = 0;
            ll score = 0;
            for (int k = 0; k < N; k++) {
                score = max(A[k][i], A[k][j]);
                sum += score;
            }
            ans = max(ans, sum);
        }
    }
    cout << ans << "\n";
    return 0;
}