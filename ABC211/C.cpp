/**
 *    author:  ytsmash
 *    created: 11.08.2021 14:24:00
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
    string S;
    cin >> S;
    string T = "chokudai";
    int n = (int)S.size();
    // dp[i][j]はSのi文字目まででTのj文字目までを表すときの場合の数、求めるものはdp[n][8]
    vector<vector<int>> dp(n + 1, vector<int>(9));
    rep(i, n + 1) {
        // 各iについて、Sのi文字目まででTの0文字目(これは空文字、つまり空白)を作る場合の数は、Sに何も下線を引かない場合の1通り
        dp[i][0] = 1;
    }
    const int mod = 1000000007;

    rep(i, n) {
        rep(j, 8) {
            if (S[i] == T[j]) {
                /*
                 * Sのi+1文字目がTのj+1文字目と一致する場合、
                 * Sのi+1文字目まででTのj+1文字目までを表すときの場合の数は、
                 * Sのi文字目まででTのj文字目までを表すときの場合の数と
                 * Sのi文字目まででTのj+1文字目までを表すときの場合の数の和で表せる
                 */
                dp[i+1][j+1] = (dp[i][j] + dp[i][j+1]) % mod;
            } else {
                /*
                 * Sのi+1文字目がTのj+1文字目と一致しない場合、
                 * Sのi+1文字目まででTのj+1文字目までを表すときの場合の数は、
                 * Sのi-1文字目まででTのj+1文字目までを表すときの場合の数に等しい
                 */
                dp[i+1][j+1] = dp[i][j+1];
            }
        }
    }

    ll ans = dp[n][8];
    cout << ans << "\n";
    return 0;
}