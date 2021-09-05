/**
 *    author:  ytsmash
 *    created: 04.09.2021 09:50:05
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

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<vector<int>> G(N);
    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> dist(N, -1);
    queue<int> que;
    dist[0] = 0;
    que.push(0);
    while (!que.empty()) {
        int crr = que.front();
        que.pop();
        for (auto nxt : G[crr]) {
            if (dist[nxt] != -1) continue;
            dist[nxt] = dist[crr] + 1;
            que.push(nxt);
        }
    }

    rep(i, Q) {
        int c, d;
        cin >> c >> d;
        c--;
        d--;
        if (dist[c] % 2 == dist[d] % 2) cout << "Town" << endl;
        if (dist[c] % 2 != dist[d] % 2) cout << "Road" << endl;
    }
    return 0;
}