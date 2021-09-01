/**
 *    author:  ytsmash
 *    created: 29.08.2021 12:49:57
 **/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
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
struct edge {
    int to, cost;
};

int N, M, L;
vector<vector<edge>> G;
int ans = 0;

void dfs(int pre, int crr, int sum) {
    if (crr == 0) {
        if (ans < sum) {
            chmax(ans, sum);
        }
    }

    for (int i = 0; i < G[crr].size(); i++) {
        if (sum + G[crr][i].cost <= L) {
            dfs(crr, G[crr][i].to, sum + G[crr][i].cost);
        } else {
            return;
        }
    }
    return;
}

int main() {
    cin >> N >> M >> L;
    G.resize(N);
    rep(i, M) {
        int s, t, d;
        cin >> s >> t >> d;
        s--;
        t--;
        edge e = {t, d};
        G[s].push_back(e);
    }
    dfs(-1, 0, 0);
    cout << ans << "\n";
    return 0;
}