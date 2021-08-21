/**
 *    author:  ytsmash
 *    created: 20.08.2021 19:45:23
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

int D, G, P[10], C[10];
int dp[11][401010];  // dp[i][point] :=
                     // 100*i点問題まででpoint点得るための最小の問題数

int main() {
    cin >> D >> G;
    G /= 100;

    rep(i, D) {
        cin >> P[i] >> C[i];
        C[i] /= 100;
    }

    rep(i, D + 1) {
        rep(point, 201010) { dp[i][point] = INF; }
    }
    dp[0][0] = 0;

    rep(i, D) {
        rep(point, 201010) {
            rep(j, P[i]) {
                chmin(dp[i + 1][point + (i + 1) * j], dp[i][point] + j);
            }
            chmin(dp[i + 1][point + (i + 1) + P[i] + C[i]],
                  dp[i][point] + P[i]);
        }
    }
    int ans = INF;
    for (int point = G; point < 201010; point++) {
        chmin(ans, dp[D][point]);
    }
    return 0;
}