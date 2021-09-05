/**
 *    author:  ytsmash
 *    created: 04.09.2021 18:17:05
 **/

#include <bits/stdc++.h>
using namespace std;

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

int N, Q;
vector<vector<int>> G;
vector<int> val;

void dfs(int pre, int crr) {
    for (auto to : G[crr]) {
        if (to != pre) {
            val[to] += val[crr];
            dfs(crr, to);
        }
    }
}

int main() {
    cin >> N >> Q;
    G.resize(N);
    val.resize(N);
    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        G[a - 1].push_back(b - 1);
        G[b - 1].push_back(a - 1);
    }
    rep(i, Q) {
        int p, x;
        cin >> p >> x;
        p--;
        val[p] += x;
    }
    dfs(-1, 0);
    rep(i, N) { cout << val[i] << " "; }
    cout << "\n";
    return 0;
}