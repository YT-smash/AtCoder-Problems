/**
 *    author:  ytsmash
 *    created: 26.09.2021 21:33:17
 **/

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

typedef long long ll;
typedef long double ld;
struct edge {
    int to, cost;
};
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
const ll INF = 1e18;
const long double PI = acos(-1.0L);
using P = pair<int, int>;
vector<int> devisor(int num) {
    vector<int> ret;
    for (int i = 1; i * i <= num; i++) {
        if (num % i == 0) {
            ret.push_back(i);
            if (i * i != num) {
                ret.push_back(num / i);
            }
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}
vector<pair<ll, ll>> prime_factorize(ll N) {
    vector<pair<ll, ll>> res;
    for (ll a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        ll ex = 0;
        while (N % a == 0) {
            ++ex;
            N /= a;
        }
        res.push_back({a, ex});
    }
    if (N != 1) res.push_back({N, 1});
    return res;
}

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N + 10);
    for (int i = 0; i < N; i++) cin >> A[i];

    const ll MOD = 998244353;
    vector<vector<ll>> dp(N + 10, vector<ll>(10));  // dp[i][j]は操作をi回やったときに次に挿入する数がjになるときの操作手順の場合の数
    dp[0][A[0]] = 1;
    // dp[1][(A[0] + A[1]) % 10] = 1;
    // dp[1][(A[0] * A[1]) % 10] = 1;
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < 10; j++) {
            dp[i + 1][(j + A[i + 1]) % 10] += dp[i][j];
            dp[i + 1][(j + A[i + 1]) % 10] %= MOD;
            dp[i + 1][(j * A[i + 1]) % 10] += dp[i][j];
            dp[i + 1][(j * A[i + 1]) % 10] %= MOD;
        }
    }
    for (int i = 0; i < 10; i++) {
        cout << dp[N - 1][i] % MOD << endl;
    }
    return 0;
}