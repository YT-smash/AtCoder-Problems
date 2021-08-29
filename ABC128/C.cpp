/**
 *    author:  ytsmash
 *    created: 29.08.2021 09:53:27
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
    int N, M;
    cin >> N >> M;
    vector<vector<int>> s(M, vector<int>(N));
    rep(i, M) {
        int k;
        cin >> k;
        rep(j, k) {
            int ss;
            cin >> ss;
            ss--;
            s[i].push_back(ss);
        }
    }
    vector<int> p(M);
    rep(i, M) cin >> p[i];

    int ans = 0;
    rep(bit, 1 << N) {
        int ok = 0;
        rep(j, M) {
            int cnt = 0;
            for (auto s : s[j])
                if (bit & (1 << s)) cnt++;
            if (cnt % 2 == p[j]) ok++;
        }
        if (ok == M) ans++;
    }
    cout << ans << "\n";
    return 0;
}